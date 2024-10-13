#ifndef PROGRAM_H
#define PROGRAM_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct TaskInfo
{
    int id;
    char taskName[50];
    char dueDate[15];
    int status;
};


void addTask();
void deleteTask();
void modifyTask();
void viewAllTasks();
void mainMenu();



#endif //PROGRAM_H