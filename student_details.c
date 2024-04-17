#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 50
#define MAX_ID_LENGTH 20
#define MAX_GRADE_LENGTH 5
#define MAX_COURSE_LENGTH 50
#define NUM_COURSES 3

struct Student {
	char firstName[MAX_NAME_LENGTH];
	char lastName[MAX_NAME_LENGTH];
	char id[MAX_ID_LENGTH];
	char grade[MAX_GRADE_LENGTH];
	char courses[NUM_COURSES][MAX_COURSE_LENGTH];
};

struct Student inventory[MAX_STUDENTS];
int numStudents = 0;

void addStudent() {
	if (numStudents >= MAX_STUDENTS) {
		printf("Inventory is full. Cannot add more students.\n");
		return;
	}
	
	printf("Enter student details:\n");
	printf("First Name: ");
	scanf("%s", inventory[numStudents].firstName);
	printf("Last Name: ");
	scanf("%s", inventory[numStudents].lastName);
	printf("Enter ID: ");
	scanf("%s", inventory[numStudents].id);
	printf("Enter grade: ");
	scanf("%s", inventory[numStudents].grade);
	
	printf("Enter the courses (max of %d):\n", NUM_COURSES);
	for (int i = 0; i < NUM_COURSES; i++) {
		printf("Enter course %d:\n", i);
		scanf("%s", inventory[numStudents].courses[i]);
	}
	
	numStudents++;
}

void editStudent() {
	char searchId[MAX_ID_LENGTH];
	printf("Enter the ID of the student you want to edit: ");
	scanf("%s", searchId);
	
	for (int i = 0; i < numStudents; i++) {
		if (strcmp(inventory[i].id, searchId) == 0) {
			printf("Enter new details for student %s %s: \n", inventory[i].firstName, inventory[i].lastName);
			printf("First name: ");
			scanf("%s", inventory[i].firstName);
			printf("Last Name: ");
			scanf("%s", inventory[i].lastName);
			printf("Enter ID: ");
			scanf("%s", inventory[i].id);
			printf("Grade: ");
			scanf("%s", inventory[i].grade);
			
			printf("Enter courses (max of %d):\n", NUM_COURSES);
			for (int j = 0; j < NUM_COURSES; j++) {
				printf("Course %d: ", j + 1);
				scanf("%s", inventory[i].courses[j]);
			}
			
			return;
		}
	}
	
	printf("Student with ID %s not found.\n", searchId);
	
}

void deleteStudent() {
	char searchId[MAX_ID_LENGTH];
	printf("Enter the ID of the student you want to delete: ");
	scanf("%s", searchId);
	
	for (int i = 0; i< numStudents; i++) {
		if(strcmp(inventory[i].id, searchId) == 0) {
			for(int j = i; j < numStudents - 1; j++) {
				strcpy(inventory[j].firstName, inventory[j+1].firstName);
				strcpy(inventory[j].lastName, inventory[j+1].lastName);
				strcpy(inventory[j].id, inventory[j+1].id);
				strcpy(inventory[j].grade, inventory[j+1].grade);
				for (int k = 0; k < NUM_COURSES; k++) {
					strcpy(inventory[j].courses[k], inventory[j+1].courses[k]);
				}
			}
			numStudents--;
			printf("Student deleted successfully.\n");
			return;
		}
	}
	
	printf("Student with ID %s not found.\n", searchId);
	
}

void displayInventory() {
	printf("Inventory:\n");
	for(int i = 0; i < numStudents; i++) {
		printf("Student %d:\n", i+1);
		printf("Name: %s %s\n", inventory[i].firstName, inventory[i].lastName);
		printf("ID: %s\n", inventory[i].id);
		printf("Grade: %s\n", inventory[i].grade);
		printf("Courses:\n");
		for (int j = 0; j < NUM_COURSES; j++) {
			printf("%s,\n ", inventory[i].courses[j]);
		}
		printf("\n");
	}
}

int main() {
	int choice;
	do {
		printf("\nStudent Inventory Management System\n");
		printf("1. Add Student\n");
		printf("2. Edit Student\n");
		printf("3. Delete Student\n");
		printf("4. Display Inventory\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		
		switch(choice) {
			case 1:
				addStudent();
				break;
			case 2:
				editStudent();
				break;
			case 3:
				deleteStudent();
				break;
			case 4:
				displayInventory();
				break;
			case 5:
				printf("Exiting program.\n");
				break;
			default:
				printf("Invalid choice. Please choose from the given options.\n(Between 1 and 5)");
		}
	} while (choice != 5);
	
	return 0;
}
