#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct std{
    int rollno;
    char name[50];
    char class[30];
    char sem[10];
    char subject[30];
    int fee;
};

void displayRecord(struct std *p, int records);
void updateRecord(struct std *p, int records);
void deleteRecord(struct std *p, int *records);
int searchRecord(struct std *p, int records, int choice, int key, char *search_name);

int main(){
    int records;
    struct std *p;
    printf("Enter the number of records you want to store: ");
    scanf("%d",&records);

    p = (struct std*)malloc(records*(sizeof(struct std)));

    for(int i=0;i<records;i++){
        printf("\nEnter rollno:");
        scanf("%d",&p[i].rollno);
        printf("\nEnter Name:");
        scanf("%s",p[i].name);
        printf("\nEnter class:");
        scanf("%s",p[i].class);
        printf("\nEnter Semester:");
        scanf("%s",p[i].sem);
        printf("\nEnter Subject:");
        scanf("%s",p[i].subject);
        printf("\nEnter Fees:");
        scanf("%d",&p[i].fee);
    }

    printf("\n-------------student information-------------\n");
    displayRecord(p,records);

    int choice;
    printf("Do you want to update records (Y/N)? \n<0> for Yes and <1> for No.");
    scanf("%d",&choice);

    if (choice==0){
        int update;
        printf("For update by ID enter <1>\nFor update by Name enter <2>");
        scanf("%d",&update);

        updateRecord(p,records);
        printf("-------------student information-------------\n");
        displayRecord(p, records);
    }

    printf("Do you want to delete records (Y/N)? \n<0> for Yes and <1> for No.");
    scanf("%d",&choice);

    if (choice==0){
        int delete;
        printf("For Delete by ID enter <1>\nFor Delete by Name enter <2>");
        scanf("%d",&delete);

        deleteRecord(p,&records);

        printf("\n-------------student information-------------\n");
        displayRecord(p,records);
    }

    char search_name[50];
    printf("Find the student record by name:\n Enter student name:");
    scanf("%s",search_name);

    int result = searchRecord(p,records,2,-1,search_name);

    if(result == -1){
        printf("Student not found.\n");
    }

    free(p);
    return 0;

}

void displayRecord(struct std *p, int records){
    for (int i = 0; i < records; i++)
    {
        printf("%d %s %s %s %s %d\n", p[i].rollno, p[i].name, p[i].class, p[i].sem, p[i].subject, p[i].fee);
    }
    
}

void updateRecord(struct std *p, int records){
    int update;
    printf("Enter student id or name to update: ");
    scanf("%d", &update);

    int new = searchRecord(p,records,1,update,"");

    if (new != -1){
        printf("Enter new details for the student:\n");
         printf("\nEnter rollno:");
        scanf("%d",&p[new].rollno);
        printf("\nEnter name:");
        scanf("%s",p[new].name);
        printf("\nEnter Class:");
        scanf("%s",p[new].class);
        printf("\nEnter Semester:");
        scanf("%s",p[new].sem);
        printf("\nEnter Subject:");
        scanf("%s",p[new].subject);
        printf("\nEnter Fees:");
        scanf("%d",&p[new].fee);
        printf("Record Updated successfully\n");
    }
    else{
        printf("Record not found.\n");
    }
}

void deleteRecord(struct std *p, int *records){
    int delete;
    printf("Enter student id or name to delete: ");
    scanf("%d", &delete);

    int new = searchRecord(p,records,1,delete,"");

    if(new != -1){
        for (int j = new;j<(*records - 1);j++){
            p[j] = p[j+1];
        }
        (*records)--;
        p = (struct std *)realloc(p,(*records)*sizeof(struct std));
        printf("Record deleted successfully\n");
    }
    else{
        printf("Record not found.\n");
    }

}

int searchRecord(struct std *p, int records, int choice, int key, char *search_name){
    int found = -1;

    for (int i = 0; i < records; i++)
    {
        if ((choice == 1 && p[i].rollno == key) ||
            (choice == 2 && strcmp(p[i].name, search_name) == 0))
        {
            found = i;
            break;
        }
    }
    return found;
    
}