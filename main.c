//
// Created by maximilian on 1/3/23.
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#include "NovelGrabber.h"
#include "url.h"
#include "input.h"
#include "directory.h"
#include "download.h"





int main(int argc, char **argv)
{
    NovelGrabber *novelGrabber = initNovelGrabber(&argc, argv);

    printf("\n\n");
    downloadFiles(novelGrabber, "wget");

    return EXIT_SUCCESS;
}