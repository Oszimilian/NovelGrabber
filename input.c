//
// Created by maximilian on 1/4/23.
//

#include <stdio.h>
#include <stdlib.h>
#include "input.h"
#include "linkedList.h"

void fillLinkedListFromInput(List *input_list, int *argc, char **argv)
{
    for (int i = 1; i < *argc; i++)
    {
        pushElement(input_list, createElement(argv[i], 0));
    }
}

#include "input.h"
