//
// Created by maximilian on 1/3/23.
//

#ifndef NOVELGRABBER_LINKEDLIST_H
#define NOVELGRABBER_LINKEDLIST_H

struct Element
{
    char type;
    char *str;
    int num;

    struct Element *next;
};
typedef struct Element Element;

struct List
{
    int leangh;
    Element *head;
};
typedef struct List List;

Element *createElement(char *str, int num);
Element *createURLElement(char *str, int num);
List *createList();
void pushElement(List *list, Element *element);
Element *findElementString(List *list, char *str);
Element *findElementNumber(List *list, int num);
Element *findElementType(List *list, char type);
void printList(List *list);
Element *findElementAtIndex(List *list, int index);
void printListReverse(List *list);
Element *createFILEElement(char *str, int num);

#endif //NOVELGRABBER_LINKEDLIST_H
