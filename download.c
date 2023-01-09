//
// Created by maximilian on 1/4/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NovelGrabber.h"
#include "linkedList.h"
#include "url.h"
#include "file.h"

void downloadFiles(NovelGrabber *novelGrabber, char *cmd)
{
    if (novelGrabber->mode == 'M')
    {
        printf("%s %s -P %s \n", cmd, getManuURL(novelGrabber), novelGrabber->outputDirectory);
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
            printf("%s %s -P %s \n", cmd, getIntervallFileURL(novelGrabber, i), novelGrabber->outputDirectory );
        }

    }
}


