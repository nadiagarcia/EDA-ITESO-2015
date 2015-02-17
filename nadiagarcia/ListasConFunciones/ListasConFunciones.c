/*
 * estructura1.c
 *
 *  Created on: Feb 4, 2013
 *      Author: Nadia
 */

#include <stdio.h>
#include <stdlib.h>

//estructura
struct task {
	int priority;
	char description[50];
	struct task *next;
};

//definir mi estructura como un nuevo tipo de dato
typedef struct task TASK;

TASK * new() {
	TASK *new_task = (TASK *) malloc(sizeof(TASK));

	printf("Priority: \n");
	scanf("%d", &new_task->priority);
	prtinf("Description: \n");
	gets(new_task->description);
	new_task->next = NULL;

	return new_task;
}

void removeTask(TASK **start, short index) {
	TASK *current = *start;
	short i;

	if (index == 1) {
		*start = current->next;
		free(current);
	} else if (index > 0) {
		for (i = 1; i < index - 1 && current != NULL ; i++) {
			current = current->next;
		}
		if (current != NULL ) {
			TASK *erease = current->next;
			current->next = erease->next;

			free(erease);
		}
	} else if (index == 0) {
		free(*start);
	}

}

void insertTask(TASK **start, short index) {
	TASK *current = *start;
	short i;

	TASK *task = new();

	if (*start == NULL ) {
		*start = task;
	} else if (index < 0) {
		while (current->next != NULL ) {
			current = current->next;
		}

		current->next = task;
	} else if (index > 0) {
		for (i = 0; i < index - 1 && current != NULL; i++) {
			current = current->next;
		}

		if(current != NULL){
			task->next = current->next;
			current->next = task;
		}
		else{
			printf("Index %d is out of boundary, element not inserted\n");
		}
	}

}

void print(TASK *start, short index) {
	short i;
	TASK *current = start;
	for (i = 1; i < index; i++) {
		current = current->next;
	}
	printf("PRIORITY\tDESCRIPTION\N");
	while (current != NULL ) {
		printf("%d\t%s\n", current->priority,current->description);
		current = current->next;
	}
}

int main() {
	setvbuf(stdout,NULL,_IONBF,0);

	TASK *start = NULL;

	int choice,index;

	do {

		printf("What would you like to do now?\n");
		printf("1) Add a new task\n");
		printf("2) Remove a task\n");
		printf("3) See all tasks\n");
		printf("-1) exit\n");

		scanf("%d",&choice);

		switch (choice) {
			case 1:
			insertTask(&start, -1);
			break;
			case 2:
			printf("which index would you like to erease?\n");
			scanf("%d",&index);
			removeTask(&start,index);
			break;
			case 3:
			print(start,1);
			break;
			default:
			printf("not an option, try again\n");
			break;
		}

	}while(choice!=-1);

	return 0;
}
