//
// Created by maximilian on 1/4/23.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "NovelGrabber.h"
#include "linkedList.h"
#include "url.h"

void handleURLConflict(void *input)
{
    if (input == NULL)
    {
        fprintf(stderr, "FAIL in building the URL! \n");
        exit(-1);
    }
}


/*
 *  This function extracts the normal URL from the []-brackets and stores the url in the linked list
 */
void extractNormalURL(NovelGrabber *novelGrabber)
{
    Element *urlElement = findElementType(novelGrabber->inputList, 'u');
    handleURLConflict(urlElement);

    char *token;

    //Start afeter the [-Bracket and loop till the ]-Bracket is reached
    token = strtok(&urlElement->str[1], "]");

    pushElement(novelGrabber->url, createURLElement(token, 0));
}


/*
 *  This function seperates the url-input into to url-strings and the {i}-Marker for replacing
 */
void extractModifiedURL(NovelGrabber *novelGrabber)
{
    Element *urlElement = findElementType(novelGrabber->inputList, 'u');
    handleURLConflict(urlElement);

    char *token = NULL;
    int strLen = 0;

    //Start after the '[' character and go till the {i}-Marker is reached and store this part of the url
    token = strtok(&urlElement->str[1], "{");
    handleURLConflict(token);
    strLen = 4 + strlen(token);
    pushElement(novelGrabber->url, createURLElement(token, 0));

    //Create a List element to signal that this part will be replaced by a integer
    Element *element = createURLElement("", 0);
    element->type = 'i';
    pushElement(novelGrabber->url, element);

    //Start after the {i}-Marker and go till the end of the url is reached. Store this part of the url in the list too.
    token = strtok(&urlElement->str[strLen], "]");
    handleURLConflict(token);
    pushElement(novelGrabber->url, createURLElement(token, 0));

}

/*
 *  This funktion returns a pointer to a string which contains the modified URL.
 *  With the variable num you can tell the funktion
 */
char *getIntervallAutoURL(NovelGrabber *novelGrabber, int num)
{
    static char url[1024];
    for (int i = 0; i < 1024; i++) url[i] = 0;

    Element *firstElement = findElementAtIndex(novelGrabber->url, 2);
    Element *lastElement = findElementAtIndex(novelGrabber->url, 0);

    handleURLConflict(firstElement);
    handleURLConflict(lastElement);

    if (firstElement->type != 'u' || lastElement->type != 'u')
    {
        handleURLConflict(NULL);
    }

    sprintf(url, "%s%d%s", firstElement->str, num, lastElement->str);

    return url;
}


