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

void handleNovelGrabberError(void *input)
{
    if (input == NULL)
    {
        fprintf(stderr, "Error in Starting the NovelGrabber! \n");
        exit(-1);
    }
}

/*
 *      This function is responsible for initialising the NovelGrabber
 *      -> Create a NovelGrabber-Data-Structure
 *      -> Create a Linked-List where al input of this program is stored
 *      -> Create a Linked-List where the URL is partly stored together with the replace-patterns
 *      -> Create a Linked-List where the hole input for the Inputfile is stored line by line
 *      -> Set the globle mode in the NovelGrabber-Structure
 *      -> Set the Output-Directory where the downloaded files are stored
 *
 *      ->Start the programm debended on the mode
 */
NovelGrabber *initNovelGrabber(int *argc, int **argv)
{
    NovelGrabber *novelGrabber = (NovelGrabber*) malloc(sizeof(NovelGrabber));
    handleNovelGrabberError(novelGrabber);

    novelGrabber->input_list = createList();
    novelGrabber->url_list = createList();
    novelGrabber->inputTextFile_list = createList();


    novelGrabber->inputFile = NULL;
    novelGrabber->outputFile = NULL;

    fillLinkedListFromInput(novelGrabber->input_list, argc, argv);


    setNovelGrabberMode(novelGrabber);
    initOutputDirectory(novelGrabber);

    handleNovelGrabber(novelGrabber);


    return novelGrabber;
}

void setNovelGrabberMode(NovelGrabber *novelGrabber)
{
    Element *modeElement = findElementType(novelGrabber->input_list, 'm');
    handleNovelGrabberError(modeElement);

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

}