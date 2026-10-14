cmake_minimum_required(VERSION 4.3)
project(doublelonkedlist C)

set(CMAKE_C_STANDARD 11)

add_executable(doublelonkedlist main.c
        doubleLinkedList.c
        doubleLinkedList.h
        doubleLinkedList.h)
