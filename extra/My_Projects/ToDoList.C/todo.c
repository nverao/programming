#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  char name[100];
  int priority;
  int done;
} Task;

Task createTask(char* name, int prior, int done) {
  Task x;
  strncpy(x.name, name, sizeof(x.name) - 1); // Используем strncpy для безопасности
  x.priority = prior;
  x.done = done;
  return x;
}

void printTask(Task x){ //void потому что только делает свою работу, ничего не возвращает
    printf("%s %d %d\n", x.name, x.priority, x.done);
}

char* taskToString(Task x){
    char *result = malloc(512 * sizeof(char));
    snprintf(result, 512, "%s %d %d\n", x.name, x.priority, x.done);
    return result;
}

Task getTaskFromUser(){
    Task x;
    scanf("%s %d %d", &x.name, &x.priority, &x.done);
    printTask(x);
    return x;
}

void markAsDone(Task *x){
    x->done = 1; //(*x).done = 1;
}

void printAllTasks(Task *tasks, int n){
    for (int i = 0; i < n; i++){
        printf("%d. ", i);
        printTask(tasks[i]);
    }
}

void setPriority(Task *x, int priority){
    x->priority = priority; 
}

void saveToFile(Task *tasks, int n, char *filename){
    FILE *fi = fopen(filename, "w");
    for (int i = 0; i < n; i++){
        char *s = taskToString(tasks[i]);
        fprintf(fi, "%s", s);
        free(s);
    }
    fclose(fi);
}

void swap(Task *task1, Task *task2){
    Task m;
    char tmp[100];
    strncpy(tmp, (*task1).name, sizeof(task1->name) - 1);
    strncpy((*task1).name , (*task2).name, sizeof(task2->name) - 1);
    strncpy((*task2).name, tmp, sizeof(task2->name) - 1);
    m.priority = (*task1).priority;
    m.done = (*task1).done;
    (*task1).priority = (*task2).priority;
    (*task1).done = (*task2).done;
    (*task2).priority = m.priority;
    (*task2).done = m.done;
}

void printTasksInOrder(Task *tasks, int n){
    for (int j = 0; j < n-1; j++){
        for (int i = 0; i < n-1; i++){
            if (tasks[i].priority > tasks[i+1].priority){
                swap(&tasks[i], &tasks[i+1]);
            }
        }
    }
    printAllTasks(tasks, n);
}

int importFromFile(Task *tasks, int *n, char *filename){
    char name[100];
    int priority, done;
    FILE *fi = fopen(filename, "r");
    int F = fscanf(fi, "%s %d %d", &name, &priority, &done);
    if (F == EOF){
        fclose(fi);
        return 2;
    }
    *n = 0;
    while(1){
        strncpy(tasks[*n].name, name, sizeof(name) - 1);
        tasks[*n].done = done;
        tasks[*n].priority = priority;
        (*n)++;
        int F = fscanf(fi, "%s %d %d", name, &priority, &done);
        if (F == EOF) break;
    }
    fclose(fi);
    return 0;
}

void deleteTask(Task *tasks, int *n, int elem){
    for (int i = elem; i < *n; i++){
        swap(&tasks[i], &tasks[i+1]);
    }
    (*n)--;
}

int main(){
    Task tasks[100];
    int elem, num, n = 0;
    while(1){
        printf("If you want to create a Task, press 1\n");
        printf("If you want to delete a Task, press 2\n");
        printf("If you want to mark a Task as done, press 3\n");
        printf("If you want to save all tasks to a file, press 4\n");
        printf("If you want to import all tasks from a file, press 5\n");
        printf("If you want to print Task with number, print 0\n");
        printf("If you want to print all tasks, press 6\n");
        printf("If you want to change the priority, press 7\n");
        printf("If you want to print tasks in order of priority, print 8\n");
        scanf("%d", &num);
        switch(num){
            case 1:
            tasks[n++] = getTaskFromUser();
            break;
            case 2:
            if (n == 0){ 
                printf("There are no tasks to delete");
                break;
            }
            printf("Write number of task, which you want to delete(0-%d)", n);
            scanf("%d", &elem);
            deleteTask(tasks, &n, elem);
            break;
            case 0:
            scanf("%d", &num);
            printTask(tasks[num]);
            break;
            case 3:
            scanf("%d", &num);
            markAsDone(&tasks[num]);
            break;
            case 4:
            saveToFile(tasks, n, "output.txt");
            break;
            case 5:
            importFromFile(tasks, &n,"output.txt");
            break;
            case 6:
            printAllTasks(tasks, n);
            break;
            case 7:
            int priority;
            scanf("%d %d", &num, &priority);
            setPriority(&tasks[num], priority);
            break;
            case 8:
            printTasksInOrder(tasks, n);
            break;
        }
    }
}