/* A menu driven file handling program to 
   Create, read, update and delete records
   in a binary file  

Author: Archisman
Created: 16.05.2020   
   
*/

#include <stdio.h>

/* Defintion of record of type student */
struct student
{
    int rollno;
    char name[50];
    int test_score1, test_score2, test_score3;
    float average;
    char grade;
};

/* Global data variable */
FILE *file;

/* Function prototypes */
char calculate_grade(float average);
void input(struct student *s);
void display(struct student st);
void write_student();
void display_all();
void display_sp(int n);
void modify_student();
void delete_student();
void class_result();
void result_menu();
void entry_menu();


int main()
{
    int choice;
    do
    {
        printf("\n\nMain Menu");
        printf("\n1. Result Menu");
        printf("\n2. Entry/Edit Menu");
        printf("\n3. Exit");
        printf("\nPlease select your choice (1-3): ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                result_menu();
                break;
            case 2:
                entry_menu();
        }
    }while (choice != 3);
    return 0;
}

char calculate_grade(float average)
{
    if (average >= 90)
        return 'A';
    else if (average >= 70)
        return 'B';
    else if (average >= 50)
        return 'C';
    else
        return 'F';
}

void input(struct student *s)
{
    printf("\nEnter the roll number of student: ");
    scanf("%d", &s->rollno);
    fflush(stdin);
    printf("\nEnter the Name of student: ");
    gets(s->name);
    printf("\nEnter the marks in test 1: ");
    scanf("%d", &s->test_score1);
    printf("\nEnter the marks in test 2: ");
    scanf("%d", &s->test_score2);
    printf("\nEnter the marks in test 3: ");
    scanf("%d", &s->test_score3);
    s->average = (s->test_score1 + s->test_score2 + s->test_score3) / 3.0;
    s->grade = calculate_grade(s->average);
} 

void display(struct student st)
{
    printf("\nRoll Number of student : %d", st.rollno);
    printf("\nName of student : %s", st.name);
    printf("\nScore in test 1 : %d", st.test_score1);
    printf("\nScore in test 2 : %d", st.test_score2);
    printf("\nScore in test 3 : %d", st.test_score3);
    printf("\nAverage score : %0.2f", st.average);
    printf("\nGrade : %c", st.grade);
} 

void write_student()
{
    struct student data;
    file = fopen("student.dat", "ab");
    printf("\n\nPlease enter the details of student \n");
    input(&data);
    fwrite(&data, sizeof(data), 1, file);
    fclose(file);
    printf("\nStudent Record Has Been Created ");
}

void display_all()
{
    struct student data;
    printf("\n\nDISPLAY ALL RECORD !!!\n");
    file = fopen("student.dat", "rb");
    while ((fread(&data, sizeof(data), 1, file)) > 0)
    {
        display(data);
        printf("\n====================================\n");
    } fclose(file);
}

void display_sp(int n)
{
    struct student data;
    int flag = 0;
    file = fopen("student.dat", "rb");
    while ((fread(&data, sizeof(data), 1, file)) > 0)
    {
        if (data.rollno == n)
        {
            display(data);
            flag = 1;
        } 
    }
    fclose(file);
    if (flag == 0)
        printf("\nRecord not exist");
}


void modify_student()
{
    struct student data;
    int no, found = 0;

    printf("\nTo Modify ");
    printf("\nPlease Enter The roll number of student: ");
    scanf("%d", &no);
    file = fopen("student.dat", "rb+");
    while ((fread(&data, sizeof(data), 1, file)) > 0 && found == 0)
    {
        if (data.rollno == no)
        {
            display(data);
            printf("\nPlease enter the new details of student \n");
            input(&data);
            fseek(file,  - (long)sizeof(data), 1);
            fwrite(&data, sizeof(data), 1, file);
            printf("\n Record Updated");
            found = 1;
        } 
    }
    fclose(file);
    if (found == 0)
        printf("\n Record Not Found ");
}

void delete_student()
{
    int no;
    struct student data;
    FILE *file2;
    printf("\n\nDelete Record");
    printf("\nPlease Enter The roll number you want to delete: ");
    scanf("%d", &no);
    file = fopen("student.dat", "rb");
    file2 = fopen("temp.dat", "wb");
    rewind(file);
    while ((fread(&data, sizeof(data), 1, file)) > 0)
    {
        if (data.rollno != no)
        {
            fwrite(&data, sizeof(data), 1, file2);
        } 
    }
    fclose(file2);
    fclose(file);
    remove("student.dat");
    rename("temp.dat", "student.dat");
    printf("\nRecord deleted.");
}

void class_result()
{
    struct student data;
    file = fopen("student.dat", "rb");
    if (file == NULL)
    {
        printf(
            "ERROR!!! FILE COULD NOT BE OPEN\n\n Go To Entry Menu to create File");
        printf("\n\n Program is closing ....");
        return;
    } 

    printf("\nALL STUDENTS RESULT \n");
    printf("==============================================================\n");
    printf("R.No.\tName\t\tTest1\tTest2\tTest3\tAverage\tGrade\n");
    printf("==============================================================\n");

    while ((fread(&data, sizeof(data), 1, file)) > 0)
    {
        printf("%-7d %-15s %-7d %-7d %-7d %-7.2f  %-1c\n", data.rollno,
            data.name, data.test_score1, data.test_score2, data.test_score3,
            data.average, data.grade);
    }
    fclose(file);
}

void result_menu()
{
    int rno, ans;
    char choice;

    printf("\n\nResult Menu");
    printf("\n1. Class Result\n2. Student Report Card\n3.Back to Main Menu");
    printf("\nEnter Choice (1-3)? ");
    scanf("%d", &ans);
    switch (ans)
    {
        case 1:
            class_result();
            break;
        case 2:
            do
            {
                char ans;
                printf("\n\nEnter roll number of student: ");
                scanf("%d", &rno);
                display_sp(rno);
                printf("\nDo you want to see more result (y/n)?: ");
                fflush(stdin);
                scanf("%c", &choice);
            }while (choice == 'y' || choice == 'Y');
            break;
        case 3:
            break;
        default:
            printf("\a");
    }
}

void entry_menu()
{
    int choice;
    printf("\n\nEntry Menu");
    printf("\n1.Create Student Record");
    printf("\n2.Display all students records");
    printf("\n3.Search student record ");
    printf("\n4.Modify student record");
    printf("\n5.Delete Student record");
    printf("\n6.Back to main menu");
    printf("\nEnter your choice (1-6): ");
    scanf("%d",&choice);
    switch (choice)
    {
        case 1:
            write_student();
            break;
        case 2:
            display_all();
            break;
        case 3:
            {
                int num;
                printf("\n\nPlease enter the roll number: ");
                scanf("%d", &num);
                display_sp(num);
            }
            break;
        case 4:
            modify_student();
            break;
        case 5:
            delete_student();
            break;
        case 6:
            break;
        default:
            printf("\a");
            entry_menu();
    }
}
