//
// Created by maximilian on 1/4/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NovelGrabber.h"
#include "linkedList.h"

void initOutputDirectory(NovelGrabber *novelGrabber)
{
    Element *element = findElementType(novelGrabber->inputList, 'd');
    if (element == NULL)
    {
        fprintf(stderr, "Es wurde kein Outputdirectory angegeben \n");
        exit(-1);
    }

    int strLen = strlen(element->str);
    novelGrabber->outputDirectory = (char*) malloc(sizeof(char) * strLen);
    strcpy(novelGrabber->outputDirectory, &element->str[1]);
    novelGrabber->outputDirectory[strLen - 2] = '\0';

    printf("OutputDir: %s \n", novelGrabber->outputDirectory);

}

#include "directory.h"
