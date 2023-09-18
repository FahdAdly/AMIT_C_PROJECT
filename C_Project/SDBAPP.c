#include<stdio.h>
#include<stdlib.h>
#include"STD.h"
#include"SDB.h"

 uint32 ID,year,T1;
 extern struct SimpleDb *Head= NULL;


/*This Function Is Super Loop Function Which Show User List Of Orders and Ask Him To Choose an Order From The List
and  It pass user choice To SDB_action Function To Do User Order It Will Be Run Until The User Choose To Exit  */

void SDB_APP(void)
 {
     while (true)
         {
         printf("\n=============================================== \n");
         printf("==== Welcome to AMIT-C Programming Project ==== \n");
         printf("==== DEV : FAHD ADLY ABO HAMADY            ==== \n");
         printf("=============================================== \n");
         printf(" To Edd Entry, Enter 1 \n");
         printf(" To Get Used Size in DataBase, Enter 2 \n");
         printf(" To Read Student Data, Enter 3 \n");
         printf(" To Get the List of all Student IDs, Enter 4 \n");
         printf(" To Check is ID is Existed, Enter 5 \n");
         printf(" To Delete Student Data, Enter 6 \n");
         printf(" To Check is DataBase is Full, Enter 7 \n");
         printf(" To Exit Enter 0\n");
         printf("=============================================== \n");
         printf("\t\t Enter your Choice\n");

         uint8 choice;
         uint8 count=0;
         scanf(" %c",&choice);
         SDB_action(choice);
         }
 }


/*This Function  Take User Choice and Select Which Function I Will Run  */

 void SDB_action(uint8 choice)
 {
     uint32 count=SDB_GetUsedSize();
     uint32 *list =malloc(sizeof(uint32)*count);

              switch (choice)
              {
        case '1':

             SDB_IsFull((uint8) count);
             printf("\nId Number : ");
             scanf("%d",&ID);

             printf("\nyear : ");
             scanf("%d",&year);
             uint32* SN =malloc(sizeof(uint32)*3);
             uint32* grades =malloc(sizeof(uint32)*3);

             printf("\n course1_Id :");
             scanf("%d",&SN[0]);

             printf("\n course1_grade :");
             scanf("%d",&grades[0]);

             printf("\n course2_Id : ");
             scanf("%d",&SN[1]);

             printf("\n course2_grade : ");
             scanf("%d",&grades[1]);

             printf("\n course3_Id : ");
             scanf("%d",&SN[2]);

             printf("\n course3_grade : ");
             scanf("%d",&grades[2]);

             SDB_AddEntry(ID,year,SN,grades);
             count++;
         break;

         case '2':

             SDB_GetUsedSize();
         break;

         case '3':

             printf("Enter id Number of Student whose record you want to Search\n");
             scanf("%d",&ID);
             SDB_ReadEntry(ID);
         break;

         case '4':

             SDB_GetList(count,list[MAX_SIZE]);
         break;

         case '5':

             printf("Enter ID Number to Check if it Exist\n");
             scanf("%d",&T1);
             if(SDB_IsIdExist((uint32) T1))
                {
                    printf("ID Number Exist\n");
                }else
                {
                    printf("ID Number not Exist\n");
                }
         break;

         case '6':

             printf("Enter ID Number of Student whose Record you want to Delete\n");
             scanf("%d",&ID);
             SDB_DeleteEntry(ID);
         break;

         case '7':

              if(SDB_IsFull(SDB_GetUsedSize()))
                {
                    printf("Database Is Full\n");
                }else
                {
                    printf("Database Is Not Full\n");
                }
         break;

         case '0':

             exit (0);
         break;

         default:

            printf("Invalid Choice\n");

         break;

              }
}
