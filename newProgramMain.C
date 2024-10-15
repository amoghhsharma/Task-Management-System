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

void addTask(TaskInfo *task, int taskcount);
void deleteTask(TaskInfo *task, int taskcount);
void modifyTask(TaskInfo *task, int taskcount);
void viewAllTasks(TaskInfo *task, int taskcount);
void mainMenu();

int main(){

    printf("\nWelcome to the task manager program\n");
    printf("-----------------------------------\n\n");

    struct TaskInfo task[5];
    
    int choice = 0;
    int taskcount = 0;

      
        while (taskcount >= 0)
        {
        mainMenu();
        scanf("%d", &choice);
            switch (choice) {
                case 1:
                    if (taskcount < 5) {  // Limiting to 5 tasks
                        addTask(&task[taskcount], taskcount);
                        taskcount++;  // Increment task count after adding
                    break;  
                    } 
                case 2:
                    deleteTask(task, taskcount);
                    taskcount--;
                    break;
                case 3:
                    modifyTask(task, taskcount);
                    break;
                case 4:
                    viewAllTasks(task, taskcount);  // View all tasks
                    break;
                case 5:
                    printf("\nExiting the program...\n");
                    break;
                default:
                    printf("\nInvalid choice! Please try again.\n");
            }
        }
        

    return(0);
}

void mainMenu(){
        printf("\nTask Management System\n");
        printf("1. Add Task\n");
        printf("2. Delete Task\n");
        printf("3. Update Task\n");
        printf("4. List Tasks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
}

void addTask(TaskInfo *task, int taskcount){
    char tempname[100];

    printf("\n\nEnter the ID of the task: ");
    scanf("%d", &task->id);
    getchar();  

    printf("\nEnter the name of the task: ");
    fgets(tempname, sizeof(tempname), stdin); 
    tempname[strcspn(tempname, "\n")] = 0;
    strcpy(task->taskName, tempname);  

    printf("Enter the due date of the task: ");
    fgets(tempname, sizeof(tempname), stdin);  
    tempname[strcspn(tempname, "\n")] = 0;  
    strcpy(task->dueDate, tempname);

    printf("\n\n----Task added successfully----\n");

}

void viewAllTasks(TaskInfo task[], int taskcount){
if (taskcount == 0) {
        printf("\nNo tasks available!\n");
    } else {
        printf("\n---- All Tasks ----\n");
        for (int i = 0; i < taskcount; i++) {
            printf("\nTask \n%d\n", i + 1);
            printf("ID: %d\n", task[i].id);
            printf("Name: %s\n", task[i].taskName);
            printf("Due Date: %s\n", task[i].dueDate);
            printf("Status: %s\n", task[i].status ? "Completed" : "Incomplete");
        }
    }
}

void deleteTask(TaskInfo task[], int taskcount){
    int taskNum;
    
    printf("Enter the id of the task you want to delete: ");
    scanf("%d", &taskNum);

    int found = 0;
    for (int i = 0; i < taskcount; i++) {
        if (task[i].id == taskNum) {
            task[i].id = -1;  
            strcpy(task[i].taskName, "");
            strcpy(task[i].dueDate, "");
            task[i].status = -1;  
            printf("Task %d has been deleted.\n", taskNum);
            found = 1;
            break;
        }
    }
    
    if (!found) {
        printf("Task with ID %d not found.\n", taskNum);
    }
    
}
void modifyTask(TaskInfo *task, int taskcount){

    deleteTask(task, taskcount);
    addTask(task, taskcount);

    printf("The task has been modified!\n");

}