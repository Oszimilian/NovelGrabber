//
// Created by maximilian on 1/4/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NovelGrabber.h"
#include "linkedList.h"
#include "directory.h"

void handleInputDirectoryError(void *input)
{
    if (input == NULL)
    {
        fprintf(stderr, "Error in building the Inputdirectory! \n");
        exit(-1);
    }
}

void initOutputDirectory(NovelGrabber *novelGrabber)
{
    Element *element = findElementType(novelGrabber->input_list, 'd');
    handleInputDirectoryError(element);

    int strLen = 0;
    char *token = strtok(element->str, "]");
    strLen = strlen(token);
    novelGrabber->outputDirectory = (char*) malloc(sizeof(char) * strLen);
    strcpy(novelGrabber->outputDirectory, token);

    printf("OutputDir: %s \n", novelGrabber->outputDirectory);
}


