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

void setIntervallPoints(NovelGrabber *novelGrabber)
{
    Element *startElement = findElementType(novelGrabber->inputList, 's');
    if (startElement == NULL)
    {
        fprintf(stderr, "startpoint is missing \n");
        exit(-1);
    }

    Element *endeElement = findElementType(novelGrabber->inputList, 'e');
    if (endeElement == NULL)
    {
        fprintf(stderr, "endpoint is missing \n");
        exit(-1);
    }

    novelGrabber->start = atoi(&startElement->str[1]);
    novelGrabber->ende = atoi(&endeElement->str[1]);

    printf("Start: %d \n", novelGrabber->start);
    printf("Ende: %d \n", novelGrabber->ende);
}