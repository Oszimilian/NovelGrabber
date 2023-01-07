//
// Created by maximilian on 1/4/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NovelGrabber.h"
#include "linkedList.h"
#include "url.h"

void downloadFiles(NovelGrabber *novelGrabber, char *cmd)
{
    if (novelGrabber->mode == 'M')
    {
        printf("%s %s -P %s \n", cmd, getIntervallAutoURL(novelGrabber, 0), novelGrabber->outputDirectory);
    }
    if (novelGrabber->mode == 'A')
    {
        for (int i = novelGrabber->start; i <= novelGrabber->ende; i++)
        {
            printf("%s %s -P %s \n", cmd, getIntervallAutoURL(novelGrabber, i), novelGrabber->outputDirectory);
        }
    }
    if (novelGrabber->mode == 'F')
    {
        for (int i = novelGrabber->start; i <= novelGrabber->ende; i++)
        {
            printf("%s %s -P %s \n", cmd, findElementNumber(novelGrabber->inputTextFileList, i)->str, novelGrabber->outputDirectory );
        }

    }
}


