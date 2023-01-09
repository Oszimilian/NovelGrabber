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

void handleIntervallPointsError(void *input)
{
    if (input == NULL)
    {
        fprintf(stderr, "Error in setting up the intervallpoints! \n");
        exit(-1);
    }
}

void setIntervallPoints(NovelGrabber *novelGrabber)
{
    Element *startElement = findElementType(novelGrabber->input_list, 's');
    handleIntervallPointsError(startElement);

    Element *endeElement = findElementType(novelGrabber->input_list, 'e');
    handleIntervallPointsError(endeElement);

    novelGrabber->start = atoi(&startElement->str[1]);
    novelGrabber->ende = atoi(&endeElement->str[1]);

    printf("Start: %d \n", novelGrabber->start);
    printf("Ende: %d \n", novelGrabber->ende);
}