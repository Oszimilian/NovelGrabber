//
// Created by maximilian on 1/4/23.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "NovelGrabber.h"
#include "linkedList.h"

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

}

#include "file.h"
