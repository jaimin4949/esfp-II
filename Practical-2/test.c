#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int rollno;
    char name[50];
    char std[10];
    char sem[5];
    char subject[30];
    int fee;
};

void display(struct Student *students, int n);
void modify(struct Student *students, int *n);
void delete(struct Student *students, int *n);
void search(struct Student *students, int n);
int rollCheck(struct Student *students, int n, int rollno);

int main() {
    int n;

    printf("Enter how many records you want to store: ");
    scanf("%d", &n);

    struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter details for %d students:\n", n);
    for (int i = 0; i < n; i++) {
        int rollno;
        printf("Enter rollno: ");
        scanf("%d", &rollno);

        if (rollCheck(students, i, rollno)) {
            printf("Rollno already exists. Please enter a unique rollno.\n");
            i--; 
            continue;
        }

        students[i].rollno = rollno;

        printf("Enter name, std, sem, subject, fee: ");
        scanf("%s %s %s %s %d", students[i].name, students[i].std, 
              students[i].sem, students[i].subject, &students[i].fee);
    }

    printf("========== Output of student information============\n");
    display(students, n);

    char modifyChoice, deleteChoice;
    printf("Do you want to modify/update records (Y/N)? ");
    scanf(" %c", &modifyChoice);
    if (modifyChoice == 'Y' || modifyChoice == 'y') {
        modify(students, &n);
    }

    printf("Do you want to delete (Y/N)? ");
    scanf(" %c", &deleteChoice);
    if (deleteChoice == 'Y' || deleteChoice == 'y') {
        delete(students, &n);
    }

    search(students, n);

    free(students);
    return 0;
}

void display(struct Student *students, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d %s %s %s %s %d\n", students[i].rollno, students[i].name, 
               students[i].std, students[i].sem, students[i].subject, students[i].fee);
    }
}

void modify(struct Student *students, int *n) {
    int choice;
    printf("How do you want to modify record by id (1) or by name (2)? ");
    scanf("%d", &choice);

    if (choice != 1 && choice != 2) {
        printf("Invalid choice\n");
        return;
    }

    int id;
    char name[50];
    printf("Enter %s: ", (choice == 1) ? "id" : "name");
    if (choice == 1)
        scanf("%d", &id);
    else
        scanf("%s", name);

    students = (struct Student *)realloc(students, (*n + 1) * sizeof(struct Student));
    if (students == NULL) {
        printf("Memory reallocation failed\n");
        return;
    }

    int found = 0;
    for (int i = 0; i < *n; i++) {
        if ((choice == 1 && students[i].rollno == id) || 
            (choice == 2 && strcmp(students[i].name, name) == 0)) {
            printf("%d %s %s %s %s %d\n", students[i].rollno, students[i].name, 
                   students[i].std, students[i].sem, students[i].subject, students[i].fee);
            printf("Enter details: ");
            scanf("%d %s %s %s %s %d", &students[i].rollno, students[i].name, 
                  students[i].std, students[i].sem, students[i].subject, &students[i].fee);
            printf("Record updated successfully\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Record not found\n");
    else
        (*n)++;
}

void delete(struct Student *students, int *n) {
    int choice;
    printf("How do you want to delete record by id (1) or by name (2)? ");
    scanf("%d", &choice);

    if (choice != 1 && choice != 2) {
        printf("Invalid choice\n");
        return;
    }

    int id;
    char name[50];
    printf("Enter %s: ", (choice == 1) ? "id" : "name");
    if (choice == 1)
        scanf("%d", &id);
    else
        scanf("%s", name);

    int found = 0;
    for (int i = 0; i < *n; i++) {
        if ((choice == 1 && students[i].rollno == id) || 
            (choice == 2 && strcmp(students[i].name, name) == 0)) {
            printf("%d %s %s %s %s %d\n", students[i].rollno, students[i].name, 
                   students[i].std, students[i].sem, students[i].subject, students[i].fee);
            for (int j = i; j < (*n - 1); j++) {
                students[j] = students[j + 1];
            }
            students = (struct Student *)realloc(students, (*n - 1) * sizeof(struct Student));
            if (students == NULL) {
                printf("Memory reallocation failed\n");
                return;
            }
            (*n)--;
            printf("Record deleted successfully\n");
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Record not found\n");
}

void search(struct Student *students, int n) {
    char searchName[50];
    printf("Find the student record by name:\nEnter student name: ");
    scanf("%s", searchName);

    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(students[i].name, searchName) == 0) {
            printf("%d %s %s %s %s %d\n", students[i].rollno, students[i].name, 
                   students[i].std, students[i].sem, students[i].subject, students[i].fee);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Record not found\n");
    }
}

int rollCheck(struct Student *students, int n, int rollno) {
    for (int i = 0; i < n; i++) {
        if (students[i].rollno == rollno) {
            return 1; // Rollno already exists
        }
    }
    return 0; 
}
