#include<stdio.h>
#include<stdlib.h>
#include"STD.h"
#include"SDB.h"


bool SDB_IsFull(uint8 count)
{
    struct SimpleDb *temp = Head;
    if(count>=MAX_SIZE)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//=========================================

bool SDB_IsIdExist(uint32 T1)
{
    if (Head == NULL)
    {
        return false;
    }

    struct SimpleDb *temp =malloc(sizeof(struct SimpleDb));

    temp = Head;

    while (temp!= NULL)
    {
        if (temp->Student_ID == T1)
        {
            return true;
        }
        temp = temp->Next;
    }
    return false;
}

//=========================================

uint8 SDB_GetUsedSize()
{
    uint8 count=0;
    struct SimpleDb *temp ;
    for(temp = Head; temp!= NULL; temp=temp->Next)
        count++;
    return count;
}

//=========================================

bool SDB_AddEntry(uint32 ID,uint32 year,uint32 *SN,uint32 *grades)
{
    if (SDB_IsIdExist(ID))
    {
        printf("This Id already Exists\n");
        return false;
    }
    if (SDB_IsFull(SDB_GetUsedSize()))
    {
        printf("\n");
        return false;
    }

    struct SimpleDb *temp=malloc(sizeof(struct SimpleDb));
    temp->Student_ID = ID;
    temp->Student_year = year;
    temp->Course1_ID=SN[0];
    temp->Course1_grade=grades[0];
    temp->Course2_ID=SN[1];
    temp->Course2_grade=grades[1];
    temp->Course3_ID=SN[2];
    temp->Course3_grade=grades[2];
    // Insert at Begin
    if (Head == NULL
            || (Head->Student_ID >= temp->Student_ID))
    {
        temp->Next = Head;
        Head = temp;
    }
    // Insert at middle or End
    else
    {
        struct SimpleDb *c = Head;
        while (c->Next != NULL
                && c->Next->Student_ID < temp->Student_ID)
        {
            c = c->Next;
        }
        temp->Next = c->Next;
        c->Next = temp;
    }
    return true;
}

//=========================================

uint32 SDB_DeleteEntry(uint32 ID)
{
    struct SimpleDb *temp = Head;
    struct SimpleDb *p=NULL;
    // Deletion at Begin
    if (temp != NULL && temp->Student_ID == ID)
    {
        Head = temp->Next;
        free(temp);
        printf("ID Data Deleted Successfully\n");
        return 0;
    }
    while (temp != NULL && temp->Student_ID != ID)
    {
        p = temp;
        temp = temp->Next;
    }
    if (temp == NULL)
    {
        printf("ID Data does not Exist\n");
        return -1;
        p->Next = temp->Next;
        free(temp);
        printf("ID Data Deleted Successfully\n");
        return 0;
    }
}

//=========================================

bool SDB_ReadEntry(uint32 ID)
{
    // if head is NULL
    if (!SDB_IsIdExist(ID))
    {
        printf("your ID does not Exists \n");
        return false;
    }
    // Otherwise
    else
    {
        struct SimpleDb* p = Head;
        while (p)
        {
            if (p->Student_ID == ID)
            {
                printf("Id Number : %d\n", p->Student_ID);
                printf("year : %d\n", p->Student_year);
                printf("course1_Id : %d\n", p->Course1_ID);
                printf("course1_grade : %d %\n", p->Course1_grade);
                printf("course2_Id : %d\n", p->Course2_ID);
                printf("course2_grade : %d %\n", p->Course2_grade);
                printf("course3_Id : %d\n", p->Course3_ID);
                printf("course3_grade : %d %\n\n", p->Course3_grade);
                return false;
            }
            p = p->Next;
        }
        if (p == NULL)
            printf("your ID does not Exists e\n\n");
    }
    return false;
}

//=========================================

void SDB_GetList(uint8 * count, uint32 * list[MAX_SIZE])
{
    struct SimpleDb *temp = Head;
    for(uint32 i=0; i<count; i++) //reading the list of IDs
    {
        list[i]=temp->Student_ID;
        temp=temp->Next;
    }
    printf("ID'S\n");
    for(uint32 i=0; i<count; i++)   //printing the list of IDs
    {
        printf("%d %d\n",i+1,list[i]);
    }
}

//=========================================
