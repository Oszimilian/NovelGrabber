//
// Created by maximilian on 1/4/23.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "NovelGrabber.h"
#include "linkedList.h"
#include "url.h"


void extractNormalURL(NovelGrabber *novelGrabber)
{
    Element *urlElement = findElementType(novelGrabber->inputList, 'u');
    if (urlElement == NULL)
    {
        fprintf(stderr, "URL is missing or not specified \n");
        exit(-1);
    }

    int strLen = strlen(urlElement->str);

    char *localStr = (char*) malloc(sizeof(char) * strLen);

    for (int i = 0; i < (strLen - 2); i++)
    {
        localStr[i] = urlElement->str[i + 1];
    }

    printf("URL: %s \n", localStr);

    pushElement(novelGrabber->url, createURLElement(localStr, strLen));

    free(localStr);

}

void extractModifiedURL(NovelGrabber *novelGrabber)
{
    int counter = 0;
    int strCounter = 0;
    int strLen = 0;
    char replaceType = 0;

    Element *localElement = NULL;

    Element *urlElement = findElementType(novelGrabber->inputList, 'u');
    if (urlElement == NULL)
    {
        fprintf(stderr, "URL is missing or not specified \n");
        exit(-1);
    }



    strLen = strlen(urlElement->str);
    char *localStr = (char*) malloc(sizeof(char) * strLen);

    printf("URL: %s \n", strtok(&urlElement->str[1], "]"));

    while(urlElement->str[counter + 1] != ']')
    {

        if (urlElement->str[counter + 1] == '<')
        {
            localStr[strCounter] = '\0';
            pushElement(novelGrabber->url, createURLElement(localStr, 0));
            strCounter = 0;

            replaceType = urlElement->str[counter + 2];

            while(urlElement->str[counter] != '>')
            {
                counter++;
            }
            localElement = createURLElement("--", 0);
            localElement->type = replaceType;

            pushElement(novelGrabber->url, localElement);

        }

        if (urlElement->str[counter + 1] == ']') break;

        localStr[strCounter] = urlElement->str[counter + 1];


        strCounter++;
        counter++;
    }

    localStr[strCounter] = '\0';
    pushElement(novelGrabber->url, createURLElement(localStr, 0));

    free(localStr);
}

char *generateModifiedAutoURL(NovelGrabber *novelGrabber, int i)
{
    static char url[512];
    for (int i = 0; i < 512; i++) url[i] = 0;
    static char number[128];
    for (int i = 0; i < 512; i++) number[i] = 0;

    sprintf(number, "%d", i);

    Element *element = novelGrabber->url;

    for (int i = novelGrabber->url->leangh - 1; i >= 0; i--)
    {
        element = findElementAtIndex(novelGrabber->url, i);

        if (element->type == 'u')
        {
            strcat(url, element->str);
        }
        else if (element->type == 'i')
        {
            strcat(url, number);
        }
    }

    return url;
}
