#include "Program.h"
#include "Tasks.c"

int main(){

    printf("\nWelcome to the task manager program\n");
    printf("-----------------------------------\n\n");

    struct TaskInfo task[5];
    
    int choice = 0;
    char firstTask[50];
    bool validChoice = true;

    printf("Enter your first task:\n");
    printf("ID: ");
    scanf("%d", &task->id);

    printf("Name: ");
    fflush(stdin);
    gets(firstTask);
    strcpy(firstTask, task->taskName);

    printf("Due date: ");
    fflush(stdin);
    gets(firstTask);

    printf("Status: ");
    fflush(stdin);
    gets(firstTask);

    while (true)
    {


        mainMenu();

        scanf("%d", &choice);
        if(choice == 1){
            addTask();
        }
    }
    


    return(0);
}
