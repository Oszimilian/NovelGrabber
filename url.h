//
// Created by maximilian on 1/4/23.
//

#ifndef NOVELGRABBER_URL_H
#define NOVELGRABBER_URL_H

#include "NovelGrabber.h"

void extractModifiedURL(NovelGrabber *novelGrabber);
void extractNormalURL(NovelGrabber *novelGrabber);
char *getIntervallAutoURL(NovelGrabber *novelGrabber, int num);
char *getManuURL(NovelGrabber *novelGrabber);

#endif //NOVELGRABBER_URL_H
