#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int chooseStudent(unsigned student){
    printf("Choose a student: ");
    scanf("%d",&student);
    return 0;
}

void setAttendance(uint32_t* attendance, unsigned student){
    *attendance |= (1 << student);
}

int checkAttendance (uint32_t attendance, unsigned student){
    return !!(attendance & (1 << student));
}

void clearAttendance(uint32_t* attendance, unsigned student){
    *attendance &= ~(1 << student);
}

void changeAttendance(uint32_t* attendance, unsigned student){
    *attendance ^= (1 << student);
}

int main(void)
{
    uint32_t attendance = 0;
    int option;
    unsigned student;
    while (1)
    {
        printf("1. Set attendance\n");
        printf("2. Clear attendance\n");
        printf("3. Attendance info\n");
        printf("4. Change attendance\n");
        printf("5. Exit\n");
        scanf("%d", &option);
        if (option == 1)
        {
             chooseStudent(student);
             setAttendance(&attendance,student);

        }
        else if (option == 2)
        {
           chooseStudent(student);
           clearAttendance(&attendance,student);
        }
        else if (option == 3)
        {
           chooseStudent(student);
           int ifattend = checkAttendance(attendance,student);
           if (ifattend == 1)
           {
               printf("Student is here!\n");
           }else{
               printf("Student is missing!\n");
           }
           
        }else if (option == 4)
        {
            chooseStudent(student);
            changeAttendance(&attendance,student);
        }else if (option == 5)
        {
            break;
        }
        
        
    }
    return 0;
}
