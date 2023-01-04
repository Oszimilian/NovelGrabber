cmake_minimum_required(VERSION 3.24)
project(NovelGrabber C)

set(CMAKE_C_STANDARD 11)

add_executable(NovelGrabber main.c linkedList.c linkedList.h NovelGrabber.h input.c input.h url.c url.h NovelGrabber.c intervall.c intervall.h directory.c directory.h download.c download.h file.c file.h)
