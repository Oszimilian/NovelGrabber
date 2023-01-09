//
// Created by maximilian on 1/4/23.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "NovelGrabber.h"
#include "linkedList.h"
#include "file.h"

void handleInputTextFileError(void *input)
{
    if (input == NULL)
    {
        fprintf(stderr, "Error in opening or editing the inputfile! \n");
        exit(-1);
    }
}

void generateInputTextFileList(NovelGrabber *novelGrabber)
{
    novelGrabber->inputTextFile = fopen(novelGrabber->inputFile, "r");
    handleInputTextFileError(novelGrabber->inputTextFile);

    char *token = NULL;

    char *str = (char*) malloc(sizeof(char) * 1024);
    handleInputTextFileError(str);

    int counter = 0;

    do
    {
        if (counter >= novelGrabber->start)
        {
            fgets(str, 1024, novelGrabber->inputTextFile);
            token = strtok(str, "\n");
            pushElement(novelGrabber->inputTextFile_list, createURLElement(token, counter));
        } else {
            fgets(str, 1024, novelGrabber->inputTextFile);
        }

    }while(feof(novelGrabber->inputTextFile) != 1 || ++counter < novelGrabber->ende);

    fclose(novelGrabber->inputTextFile);
    free(str);
}

void initInputFile(NovelGrabber *novelGrabber)
{
    Element *element = findElementType(novelGrabber->input_list, 'f');
    handleInputTextFileError(element);

    char *token = NULL;
    token = strtok(&element->str[1], "]");
    novelGrabber->inputFile = (char*) malloc(sizeof(char) * 1024);
    strcpy(novelGrabber->inputFile, token);

    printf("InputFile: %s \n", novelGrabber->inputFile);

    generateInputTextFileList(novelGrabber);
}

char *getIntervallFileURL(NovelGrabber *novelGrabber, int num)
{
    static char url_list[1024];
    for (int i = 0; i < 1024; i++) url_list[i] = 0;

    Element *firstElement = findElementAtIndex(novelGrabber->url_list, 2);
    Element *lastElement = findElementAtIndex(novelGrabber->url_list, 0);
    Element *fileElement = findElementAtIndex(novelGrabber->inputTextFile_list, num);

    handleInputTextFileError(firstElement);
    handleInputTextFileError(lastElement);
    handleInputTextFileError(fileElement);

    if (firstElement->type != 'u' || lastElement->type != 'u')
    {
        handleInputTextFileError(NULL);
    }

    sprintf(url_list, "%s%s%s", firstElement->str, fileElement->str, lastElement->str);

    return url_list;
}





