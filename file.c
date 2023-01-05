//
// Created by maximilian on 1/4/23.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "NovelGrabber.h"
#include "linkedList.h"
#include "file.h"

void generateInputTextFileList(NovelGrabber *novelGrabber)
{
    novelGrabber->inputTextFile = fopen(novelGrabber->inputFile, "r");
    if (novelGrabber->inputTextFile == NULL)
    {
        fprintf(stderr, "Input Text file konnte nicht geöffnet werden \n");
        exit(-1);
    }

    char *str = (char*) malloc(sizeof(char) * 1024);
    if (str == NULL)
    {
        fprintf(stderr, "Hilfsarry für InputTextFile konnte nicht erzeugt werden \n");
        exit(-1);
    }
    str[0] = '\0';

    int strLen;
    char  *c;

    novelGrabber->inputTextFileList = createList();

    for(int i = 0; i <= novelGrabber->ende; i++)
    {
        if (i >= novelGrabber->start)
        {
            c = fgets(str, 1024, novelGrabber->inputTextFile);
            //
            if (feof(novelGrabber->inputTextFile))
            {
                novelGrabber->ende = i;
            } else {
                str[strlen(str) - 1] = '\0';
            }

            pushElement(novelGrabber->inputTextFileList, createURLElement(str, i));

        } else {
            fgets(str, 1024, novelGrabber->inputTextFile);
        }
        str[0] = '\0';
    }


    printf("InputTextFile: \n");
    printListReverse(novelGrabber->inputTextFileList);

    fclose(novelGrabber->inputTextFile);
}

void initInputFile(NovelGrabber *novelGrabber)
{
    Element *element = findElementType(novelGrabber->inputList, 'f');
    if (element == NULL)
    {
        fprintf(stderr, "Es wurde kein Inputfile Verzeichnis angegeben \n");
        exit(-1);
    }

    int strLen = strlen(element->str);
    novelGrabber->inputFile = (char*) malloc(sizeof(char) * strLen);
    strcpy(novelGrabber->inputFile, &element->str[1]);
    novelGrabber->inputFile[strLen - 2] = '\0';

    printf("InputFile: %s \n", novelGrabber->inputFile);


    generateInputTextFileList(novelGrabber);
}





