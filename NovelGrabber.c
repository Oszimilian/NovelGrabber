//
// Created by maximilian on 1/4/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#include "NovelGrabber.h"
#include "url.h"
#include "input.h"
#include "intervall.h"
#include "directory.h"
#include "file.h"

NovelGrabber *initNovelGrabber(int *argc, int **argv)
{
    NovelGrabber *novelGrabber = (NovelGrabber*) malloc(sizeof(NovelGrabber));
    if (novelGrabber == NULL) return NULL;

    novelGrabber->inputList = createList();
    novelGrabber->url = createList();
    fillLinkedListFromInput(novelGrabber->inputList, argc, argv);
    novelGrabber->inputFile = NULL;

    //Handle Input

    setNovelGrabberMode(novelGrabber);
    initOutputDirectory(novelGrabber);

    handleNovelGrabber(novelGrabber);


    return novelGrabber;
}

void setNovelGrabberMode(NovelGrabber *novelGrabber)
{
    Element *modeElement = findElementType(novelGrabber->inputList, 'm');
    if (modeElement == NULL)
    {
        fprintf(stderr, "Mode is missing \n");
        exit(-1);
    }

    if (strcmp(modeElement->str, "[MANU]") == 0)
    {
        novelGrabber->mode = 'M';
    }
    else if (strcmp(modeElement->str, "[AUTO]") == 0)
    {
        novelGrabber->mode = 'A';
    }
    else if (strcmp(modeElement->str, "[FILE]") == 0)
    {
        novelGrabber->mode = 'F';
    }
}

void handleNovelGrabber(NovelGrabber *novelGrabber)
{

    switch (novelGrabber->mode)
    {
        case 'M':   extractNormalURL(novelGrabber);

                    break;


        case 'A':   extractModifiedURL(novelGrabber);
                    setIntervallPoints(novelGrabber);

                    break;



        case 'F':   extractModifiedURL(novelGrabber);
                    setIntervallPoints(novelGrabber);
                    initInputFile(novelGrabber);

                    break;

        default:    break;
    }

    //printListReverse(novelGrabber->url);
}