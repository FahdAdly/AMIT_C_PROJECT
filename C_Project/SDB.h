#ifndef SDB_H_INCLUDED
#define SDB_H_INCLUDED
#include"STD.h"

typedef struct SimpleDb
{
    uint32 Student_ID;
    uint32 Student_year;
    uint32 Course1_ID;
    uint32 Course1_grade;
    uint32 Course2_ID;
    uint32 Course2_grade;
    uint32 Course3_ID;
    uint32 Course3_grade;
    struct SimpleDb *Next;
} student;
 struct SimpleDb *Head;

bool SDB_IsFull(uint8 count);
uint8 SDB_GetUsedSize();
bool SDB_AddEntry(uint32 ID,uint32 year,uint32 *SN,uint32 *grades);
bool SDB_ReadEntry(uint32 ID);
void SDB_GetList (uint8 * count, uint32 * list[MAX_SIZE]);
bool SDB_IsIdExist(uint32 T1);
void SDB_DeleteEntry(uint32 ID);

void SDB_APP();
void SDB_action(uint8 choice);

#endif // SDB_H_INCLUDED
