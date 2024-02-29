#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct College
{
    int id;
    char name[50];
    char course[50];
    int year;
    int semester;
    char subject[50];
    float fee;
    struct College *next;
    struct College *prev;
};

struct College *head = NULL;
struct College *tail = NULL;

void addCollege()
{
    struct College *new_college = (struct College *)malloc(sizeof(struct College));
    if (new_college == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Enter College ID: ");
    scanf("%d", &new_college->id);
    printf("Enter College Name: ");
    scanf("%s", new_college->name);
    printf("Enter Course Stream: ");
    scanf("%s", new_college->course);
    printf("Enter Year: ");
    scanf("%d", &new_college->year);
    printf("Enter Semester: ");
    scanf("%d", &new_college->semester);
    printf("Enter Subject Group: ");
    scanf("%s", new_college->subject);
    printf("Enter Fee Structure: ");
    scanf("%f", &new_college->fee);
    
    new_college->next = NULL;
    new_college->prev = tail;
    
    if (head == NULL) {
        head = new_college;
    } else {
        tail->next = new_college;
    }
    tail = new_college;
}

void displayColleges()
{
    struct College *current = tail;
    printf("College ID\tCollege Name\tCourse Stream\tYear\tSemester\tSubject Group\tFee Structure\n");
    while (current != NULL)
    {
        printf("%d\t\t%s\t\t%s\t\t%d\t%d\t\t%s\t\t%.2f\n", current->id, current->name,
               current->course, current->year, current->semester, current->subject, current->fee);
        current = current->prev;
    }
}

void searchCollege()
{
    char search_Name[50];
    printf("Enter College ID or Name to search: ");
    scanf("%s", search_Name);
    
    struct College *current = head;
    while (current != NULL)
    {
        if ((atoi(search_Name) == current->id) || (strcmp(current->name, search_Name) == 0))
        {
            printf("College ID\tCollege Name\tCourse Stream\tYear\tSemester\tSubject Group\tFee Structure\n");
            printf("%d\t\t%s\t\t%s\t\t%d\t%d\t\t%s\t\t%.2f\n", current->id, current->name,
                   current->course, current->year, current->semester, current->subject, current->fee);
            return;
        }
        current = current->next;
    }
    printf("College with ID/Name %s not found.\n", search_Name);
}


int main()
{
    int num, choice;
    printf("Enter the number of colleges: ");
    scanf("%d", &num);

    for (int i = 0; i < num; i++)
    {
        printf("\nCollege %d:\n", i + 1);
        addCollege();
    }

    while (1)
    {
        printf("\n1. Display Colleges\n");
        printf("2. Search College\n");
        printf("3. Exit\n");
        printf("Enter Your Choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            displayColleges();
            break;
        case 2:
            searchCollege();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid Choice\n");
        }
    }
    return 0;
}
