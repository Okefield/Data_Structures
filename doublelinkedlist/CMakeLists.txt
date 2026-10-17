cmake_minimum_required(VERSION 4.3)
project(doublelinkedlist C)

set(CMAKE_C_STANDARD 11)

add_executable(doublelinkedlist main.c
        doubleLinkedList.c
        doubleLinkedList.h)
