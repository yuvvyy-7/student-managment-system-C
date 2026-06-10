#include <stdio.h>

struct Student {
    int rollNo;
    char name[30];
    int marks;

} s;


int main(){

FILE *fp;

int choice;
int found = 0;

printf("____Student Managment System____\n");


do{
    
    printf("\n\n1. Add New Student DATA\n");
    printf("2. Display Student DATA\n");
    printf("3. Search Student DATA\n");
    printf("4. Exit\n");
    printf("Enter Your Choice:");

    scanf("%d", &choice);

    switch(choice){
        case 1:{ //add student
            fp = fopen("Students.txt", "a");
            
            if(fp == NULL){
                printf("File Error!\n");
                break;
            }
            

            printf("\nEnter Details of Student\n");
            printf("Enter Roll No:");
            scanf("%d", &s.rollNo);

            printf("Enter Student's Name:");
            scanf(" %29[^\n]s", &s.name);
            
            printf("Enter Marks:");
            scanf("%d", &s.marks);

            fprintf(fp, "%d %s %d ", s.rollNo, s.name, s.marks);
            fclose(fp);

            printf("Student Added Succesfully!!\n");
            break;
            
        }
        case 2: { //display
            fp = fopen("Students.txt", "r");
            
            if(fp == NULL){
                printf("File Error!\n");
                break;
            }

            printf("____Student LIST____\n\n");

            while (fscanf(fp, "%d %s %d ", &s.rollNo, s.name, &s.marks) != EOF ){

                printf("{Student Name: %s}\n", s.name);
                printf("{ROll No: %d}\n", s.rollNo);
                printf("{Marks: %d}\n", s.marks);
                printf("\n--------------\n");


            }

            fclose(fp);
            break;

        } 

        case 3: { //search

            found = 0;

            fp = fopen("Students.txt", "r");
            
            if(fp == NULL){
                printf("File Error!\n");
                break;
            }
            int searchNo;

            printf("Enter Roll No of the Student: ");
            scanf("%d", &searchNo); 

            while (fscanf(fp, "%d %s %d", &s.rollNo, s.name, &s.marks) != EOF ){

               if(s.rollNo == searchNo){
                found = 1;
                printf("\nStudent Name: %s\n", s.name);
                printf("Student's Marks: %d\n\n", s.marks);

               }
               
            }

            if(found == 0){
                printf("\nNo Such Student Exist!\n");
               }

            fclose(fp);
            break;

                }
        
        case 4:{
        printf("Exiting....\n");
        break;
        }

        default: {
            printf("Wrong Input\n");
            break;
        }

    }
    
    

}while(choice != 4);

}