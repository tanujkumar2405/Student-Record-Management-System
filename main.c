#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define File_Name "student.csv"

struct Student{
    int id;
    char name[50];
    char course[50];
    float marks;
    char grade;
};

int idExists(int id){
    FILE *fp = fopen(File_Name, "r");
    struct Student s;

    if(fp == NULL){
        return 0;
    }
    while(fscanf(fp, "%d, %49[^,], %49[^,], %f, %c\n",
        &s.id, s.name, s.course, &s.marks, &s.grade) !=EOF){
            if(s.id == id){
                fclose(fp);
                return 1;
            }
        }
        fclose(fp);
        return 0;
}

void addStudent(){
    FILE *fp = fopen(File_Name, "a");
    struct Student s;

    if(fp == NULL){
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Student ID: ");
    scanf("%d", &s.id);

    if(idExists(s.id)){
        printf("Student ID already exists! \nPlease use a unique ID.\n");
        fcolse(fp);
        return;
    }

    printf("Enter Student Name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter Course: ");
    scanf(" %[^\n]", s.course);

    do{
        printf("Enter Marks: ");
        scanf("%f", &s.marks);
    } while (s.marks < 0 || s.marks > 100);

    // grade calculation

    if(s.marks >= 90) s.grade = 'A';
    else if(s.marks >= 75) s.grade = 'B';
    else if(s.marks >= 50) s.grade = 'C';
    else if(s.marks >= 35) s.grade = 'D';
    else s.grade = 'F';

    fprintf(fp, "%d,%s,%s,%.2f,%c\n",
        s.id, s.name, s.course, s.marks, s.grade);  
    
    fclose(fp);
    printf("Student added successfully!\n");
}

void viewStudent(){
    FILE *fp = fopen(File_Name, "r");
    struct Student s;
    if(fp ==NULL){
        printf("No Record Found\n");
        return;
    }

    fscanf(fp, "%*[^\n]\n"); // Skip header line

    printf("\nID\tName\t\t\tCourse\t\t\tMarks\t  Grade\n");
    printf("--------------------------------------------------------------------------\n");

    while(fscanf(fp,"%d,%49[^,],%49[^,],%f,%c\n",
        &s.id, s.name, s.course, &s.marks, &s.grade) != EOF){
            printf("%d\t%s\t\t%s\t\t\t%.2f\t    %c\n",
                s.id, s.name, s.course, s.marks, s.grade);
        }

    fclose(fp);
}

void searchStudent(){
    FILE *fp = fopen(File_Name, "r");
    struct Student s;

    int searchID, found = 0;

    if(fp == NULL){
        printf("File not found!\n");
        return;
    }

    printf("Enter Student ID to search: ");
    scanf("%d", &searchID);

    fscanf(fp, "%*[^\n]\n"); // Skip header line

    while(fscanf(fp, "%d, %49[^,], %49[^,], %f, %c\n",
        &s.id, s.name, s.course, &s.marks, &s.grade) != EOF){
            
            if(s.id == searchID){
                printf("Found Student Record:\n");
                printf("ID: %d\nName: %s\nCourse: %s\nMarks: %.2f\nGrade: %c\n",
                    s.id, s.name, s.course, s.marks, s.grade);
                found = 1;
                break;
            }
        }
    if(!found)
        printf("Student with ID %d not found.\n", searchID);
}

void updateStudent(){
    FILE *fp = fopen(File_Name, "r");
    FILE *temp = fopen("temp.csv", "w");
    fprintf(temp, "id,name,course,marks,grade\n"); // Write header to temp file
    struct Student s;
    int updateID, found = 0;

    if(fp == NULL || temp == NULL){
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Student ID to update: ");
    scanf("%d", &updateID);

    fscanf(fp, "%*[^\n]\n"); // Skip header line

    while(fscanf(fp, "%d,%49[^,],%49[^,],%f,%c\n",
        &s.id, s.name, s.course, &s.marks, &s.grade) != EOF){
            
            if(s.id == updateID){
                printf("Enter new details for Student ID %d:\n", updateID);

                printf("Enter Student Name: ");
                scanf(" %[^\n]", s.name);

                printf("Enter Course: ");
                scanf(" %[^\n]", s.course);

                printf("Enter Marks: ");
                scanf("%f", &s.marks);

                // grade calculation
                if(s.marks >= 90) s.grade = 'A';
                else if(s.marks >= 75) s.grade = 'B';
                else if(s.marks >= 50) s.grade = 'C';
                else if(s.marks >= 35) s.grade = 'D';
                else s.grade = 'F';

                found = 1;
            }
            fprintf(temp, "%d,%s,%s,%.2f,%c\n",
                s.id, s.name, s.course, s.marks, s.grade);
        }
        fclose(fp);
        fclose(temp);
        remove(File_Name);
        rename("temp.csv", File_Name);

        if (found)
        printf("Student record updated successfully!\n");
    else
        printf("Student not found.\n");

}

void deleteStudent(){
    FILE *fp = fopen(File_Name, "r");
    FILE *temp = fopen("temp.csv", "w");
    fprintf(temp, "id,name,course,marks,grade\n"); // Write header to temp file

    struct Student s ;
    int deleteID, found = 0;
    if(fp == NULL || temp == NULL){
        printf("Error opening file!\n");
        return;
    }
    printf("Enter Studnet ID to delete: ");
    scanf("%d", &deleteID);

    fscanf(fp, "%*[^\n]\n"); // Skip header line

    while (fscanf(fp, "%d,%49[^,],%49[^,],%f,%c\n",
                &s.id, s.name, s.course, &s.marks, &s.grade) != EOF) {

        if (s.id != deleteID) {
            fprintf(temp, "%d,%s,%s,%.2f,%c\n",
                    s.id, s.name, s.course, s.marks, s.grade);
        } 
        else
            found = 1;
        
    }
        fclose(fp);
        fclose(temp);
        remove(File_Name);
        rename("temp.csv", File_Name);

        if(found)
            printf("Student record deleted successfully!\n");
        else
            printf("Student not found.\n");

}
void report(){
    FILE *fp = fopen(File_Name, "r");
    struct Student s;
    int totalStudents = 0;
    float totalMarks = 0.0, averageMarks;
    float highestMarks = 0.0, lowestMarks = 100.0;
    int passCount = 0, failCount = 0;
    if(fp == NULL){
        printf("No Record Found\n");
        return;
    }
    fscanf (fp, "%*[^\n]\n"); // Skip header line
    while(fscanf(fp, "%d,%49[^,],%49[^,],%f,%c\n",
        &s.id, s.name, s.course, &s.marks, &s.grade) != EOF){
            totalStudents++;
            totalMarks += s.marks;
            if(s.marks > highestMarks)
                highestMarks = s.marks;
            if(s.marks < lowestMarks)
                lowestMarks = s.marks;
            if(s.grade != 'F')
                passCount++;
            else
                failCount++;
        }

    fclose(fp);
    if(totalStudents == 0){
        printf("No student records to generate report.\n");
        return;
    }   
    averageMarks = totalMarks / totalStudents;
    printf("\n--- Student Report ---\n");
    printf("Total Students: %d\n", totalStudents);  
    printf("Average Marks: %.2f\n", averageMarks);
    printf("Highest Marks: %.2f\n", highestMarks);
    printf("Lowest Marks: %.2f\n", lowestMarks);
    printf("Pass Count: %d\n", passCount);
    printf("Fail Count: %d\n", failCount);

}


int main(){
    int choice;

    while(1){
        printf("\n--- Student Record Management System ---\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Update Student\n");
        printf("5. Delete Student\n");
        printf("6. Generate Report\n");
        printf("0. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice){
            case 1:
                addStudent();
                break;
            case 2:
                viewStudent();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                deleteStudent();
                break;
            case 6:
                report();
                break;
            case 0:
                printf("Exiting the program... Goodbye!\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }


    return 0;
}
