//
// Created by maximilian on 1/4/23.
//

#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "linkedList.h"

void fillLinkedListFromInput(List *inputList, int *argc, char **argv)
{
    for (int i = 1; i < *argc; i++)
    {
        pushElement(inputList, createElement(argv[i], 0));
    }
}

#include "input.h"
