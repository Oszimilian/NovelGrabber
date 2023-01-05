//
// Created by maximilian on 1/3/23.
//

#ifndef NOVELGRABBER_NOVELGRABBER_H
#define NOVELGRABBER_NOVELGRABBER_H

#include <stdio.h>
#include "linkedList.h"


struct NovelGrabber
{
    List *inputList;
    List *url;
    List *inputTextFileList;

    char mode;

    int start;
    int ende;

    char *outputDirectory;
    char *inputFile;

    FILE *inputTextFile;
};
typedef struct NovelGrabber NovelGrabber;

NovelGrabber *initNovelGrabber(int *argc, int **argv);
void setNovelGrabberMode(NovelGrabber *novelGrabber);
void handleNovelGrabber(NovelGrabber *novelGrabber);

#endif //NOVELGRABBER_NOVELGRABBER_H
