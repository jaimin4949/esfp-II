#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int rollno;
    char name[50];
    char class[20];
    char semester[10];
    char subject[30];
    int fee;
};

int main()
{
    int n;

    printf("Enter how many records you want to store: ");
    scanf("%d", &n);

    struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));

    for (int i = 0; i < n; i++)
    {
        printf("Enter student information (RollNo Name Class Semester Subject fee): ");
        scanf("%d %s %s %s %s %d", &students[i].rollno, students[i].name, students[i].class, students[i].semester, students[i].subject, &students[i].fee);
    }

    printf("=====================Output of student information============\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d %s %s %s %s %d\n", students[i].rollno, students[i].name, students[i].class, students[i].semester, students[i].subject, students[i].fee);
    }

    char search[50];
    printf("\nFind the student record by name or roll number:\nEnter student name or roll number: ");
    scanf("%s", search);

    int found = 0;
    for (int i = 0; i < n; i++)
    {
        if (strcmp(students[i].name, search) == 0 || students[i].rollno == atoi(search))
        {
            printf("%d %s %s %s %s %d\n", students[i].rollno, students[i].name, students[i].class, students[i].semester, students[i].subject, students[i].fee);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Student with name or roll number '%s' not found.\n", search);
    }

    free(students);

    return 0;
}
