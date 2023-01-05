//
// Created by maximilian on 1/3/23.
//

#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Element *createElement(char *str, int num)
{
    int strLen = strlen(str) + 1;

    Element *element = (Element*) malloc(sizeof(Element));
    if (element == NULL) return NULL;

    element->str = (char*) malloc(sizeof(char) * strLen);
    if (element->str == NULL) return NULL;


    element->type = str[1];
    strcpy(element->str, &str[2]);
    element->num = num;
    element->next = NULL;

    return element;
}

Element *createURLElement(char *str, int num)
{
    int strLen = strlen(str) + 1;

    Element *element = NULL;
    element = (Element*) malloc(sizeof(Element));
    if (element == NULL) return NULL;

    element->str = (char*) malloc(sizeof(char) * strLen);
    if (element->str == NULL) return NULL;


    element->type = 'u';
    strcpy(element->str, str);
    element->num = num;
    element->next = NULL;

    return element;

}

Element *createFILEElement(char *str, int num)
{
    int strLen = strlen(str);
    Element *element = (Element*) malloc(sizeof(Element));
    if (element == NULL) return NULL;

    element->str = (char*)malloc(sizeof(char) * strLen);
    if (element->str == NULL) return NULL;

    element->type = 't';
    strcpy(element->str, str);
    element->num = num;
    element->next = NULL;

    return element;
}

List *createList()
{
    List *list = (List*) malloc(sizeof(List));
    if (list == NULL) return NULL;

    list->head = NULL;
    list->leangh = 0;

    return list;
}

void pushElement(List *list, Element *element)
{
    element->next = list->head;
    list->head = element;
    list->leangh++;
}

Element *findElementString(List *list, char *str)
{
    Element *element = list->head;

    while(element != NULL)
    {
        if (strcmp(element->str, str) == 0)
        {
            return element;
        } else {
            element = element->next;
        }
    }
    return NULL;
}

Element *findElementNumber(List *list, int num)
{
    Element *element = list->head;

    while(element != NULL)
    {
        if (element->num == num)
        {
            return element;
        } else {
            element = element->next;
        }
    }

    return NULL;
}

Element *findElementType(List *list, char type)
{
    Element *element = list->head;

    while(element != NULL)
    {
        if (element->type == type)
        {
            return element;
        } else {
            element = element->next;
        }
    }

    return NULL;
}

Element *findElementAtIndex(List *list, int index)
{
    Element *element = list->head;

    while(element != NULL && index > 0)
    {
        element = element->next;
        index--;
    }

    return element;
}

void printList(List *list)
{
    Element *element = list->head;

    int counter = list->leangh;

    while(element != NULL && counter >= 0)
    {
        printf("%d: %c %s %d \n", counter, element->type, element->str, element->num);
        element = element->next;
        counter--;
    }
}

void printListReverse(List *list)
{
    Element *element = list->head;

    for (int i = list->leangh - 1; i >= 0; i--)
    {
        element = findElementAtIndex(list, i);
        printf("%d: %c %s %d \n", i, element->type, element->str, element->num);
    }
}

#include "linkedList.h"
