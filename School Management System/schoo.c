#include<stdio.h>
#include<stdlib.h>
#include"implement.h"

void MAIN_MENU()
{
    printf("=================================================\n");
    printf("                    WELCOME                      \n");
    printf("=================================================\n");
    printf("              CHOOSE FROM THE MENU               \n");
    printf("=================================================\n");
    printf("FOR ADD A NEW STUDENT ENTER               ---> 1 \n");
    printf("FOR PRINT THE LIST OF STUDENTS ENTER      ---> 2 \n");
    printf("FOR DELETE THE A STUDENT ENTER            ---> 3 \n");
    printf("FOR UPDATE THE STUDENT WITH ID  ENTER     ---> 4 \n");
    printf("FOR CLEAR THE STUDENT LIST  ENTER         ---> 5 \n");
    printf("FOR SEARCH ABOUT A STUDENT WITH ID  ENTER ---> 6 \n");
    printf("FOR RANK THE STUDENT LIST  ENTER          ---> 7 \n");
    printf("=================================================\n");


}
void creatQueue(Queue *pq)
{
    pq->front=NULL;
    pq->rear=NULL;
}
void NEW_STUDENT(Queue *pq)
{
   queueNode* pn= (queueNode *)malloc(sizeof(queueNode));

   if (pn==NULL)
   {
       printf("heap is full\n");
       return;
   }
   studentInfo(pn);
   pn->pNext=NULL;
   if (isempty(pq))
   {
       pq->front=pn;
   }
   else
   {
       pq->rear->pNext=pn;
   }
   pq->rear=pn;
}
void DELETE_STUDENT (Queue *pq)
{
    int ID;
    queueNode *temp1;
    queueNode *temp2;
    temp1=pq->front;
    temp2=pq->front;
    if (isempty(pq))
    {
        printf("student list is empty\n");
        return;
    }

    printf("Enter the ID to delete it ---> ");
    scanf("%d",&ID);

    while (temp1 != NULL)
    {
        if (temp1->data.id==ID )
        {
            printf("=====The ID %d of student is found=====\n",ID);

            if(temp1==temp2)
            {
                // remove first / front element
                pq->front=temp1->pNext;
                free(temp1);
            }
            else
            {
                temp2->pNext = temp1->pNext;
                free(temp1);
            }

            printf("Record Successfully Deleted !!!\n");
            return;

        }
        temp2 = temp1;
        temp1=temp1->pNext;
    }
    printf("Student with ID %d is not found !!!\n", ID);
}
bool isFull(Queue *pq)
{
    return 0;
}
bool isempty(Queue *pq)
{
    return(pq->front==NULL);
}

int studentInfo(Student *pq)
{
    printf("   Student Information  \n");
    printf("\n");
    printf("please enter your name           : ");



    scanf("%s",pq->student_name);
    fflush(stdin);
    printf("please enter your ID             : ");
    scanf("%d",&pq->id);
    printf("please enter your phone number   : ");
    scanf("%d",&pq->phoneNumber);
    printf("please enter your score          : ");
    scanf("%d",&pq->score);
    printf("please enter your day of birth   : ");
    scanf("%d",&pq->birthday.day);
    printf("please enter your month of birth : ");
    scanf("%d",&pq->birthday.month);
    printf("please enter your year of birth  : ");
    scanf("%d",&pq->birthday.year);
    printf("please enter your address        : ");
    scanf("%s",pq->address);
    fflush(stdin);
    return 0;
}
void printInfo(Student *pq)
{
    printf("student name     is :%s\n",pq->student_name);
    printf("student ID       is :%d\n",pq->id);
    printf("student phone    is :%d\n",pq->phoneNumber);
    printf("student score    is :%d\n",pq->score);
    printf("student data     is :%d/%d/%d\n",pq->birthday.day,pq->birthday.month,pq->birthday.year);
    printf("student address  is :%s\n",pq->address);

}

void STUDENT_LIST(Queue *pq)
{
    if (isempty(pq))
    {
        printf("student list is empty\n");
        return;
    }

    queueNode *temp;
    temp = pq->front;
    while(temp!=NULL)
    {
        printInfo(temp);

        temp =temp->pNext;
        printf("\n");
    }

}
void STUDENT_EDIT(Queue *pq)
{
    int x=0;
    int ID;
    queueNode *temp = pq->front;


    if (isempty(pq))
    {
        printf("student list is empty\n");
        return;
    }

    printf("Enter the ID to update the informations ---> ");
    scanf("%d",&ID);

    while (temp != NULL)
    {
        if (temp->data.id==ID)
        {
             printf("=====The ID %d of student is found=====\n",ID);
             printf("\n");

                printf("              CHOOSE FROM THE MENU THE ITEM TO UPDATE               \n");
                printf("====================================================================\n");
                printf("FOR UPDATE THE NAME            ---> 1 \n");
                printf("FOR UPDATE THE ID              ---> 2 \n");
                printf("FOR UPDATE THE PHONE NUMBER    ---> 3 \n");
                printf("FOR UPDATE THE SCORE           ---> 4 \n");
                printf("FOR UPDATE THE DAY OF BIRTH    ---> 5 \n");
                printf("FOR UPDATE THE MANTH OF BIRTH  ---> 6 \n");
                printf("FOR UPDATE THE YEAR OF BIRTH   ---> 7 \n");
                printf("FOR UPDATE THE ADDRESS         ---> 8 \n");
                printf("if you finished your update    ---> 0 \n");
                printf("====================================================================\n");


           do
           {
                printf("Enter your choose please for update ---> ");
                scanf("%d",&x);
            switch (x)
                {
                case 1 :
                    printf("              UPDATE THE NAME                   \n");
                    printf("please enter your name : ");
                    // ask the doctor about this front->data.student_name
                    scanf("%s",temp->data.student_name);
                    fflush(stdin);
                    printf("================================================\n");
                    break;
                case 2 :
                    printf("          FOR UPDATE THE ID                     \n");
                    printf("please enter your ID : ");
                    scanf("%d",&temp->data.id);
                    printf("================================================\n");
                    break;
                case 3:
                    printf("         FOR UPDATE THE PHONE NUMBER            \n");
                    printf("please enter your phone number : ");
                    scanf("%d",&temp->data.phoneNumber);
                    printf("================================================\n");
                    break;
                case 4:
                    printf("         FOR UPDATE THE  SCORE                  \n");
                    printf("please enter your score : ");
                    scanf("%d",&temp->data.score);
                    printf("================================================\n");
                    break;
                case 5:
                    printf("         FOR UPDATE THE  DAY OF BIRTH           \n");
                    printf("please enter your day of birth : ");
                    scanf("%d",&temp->data.birthday.day);
                    printf("================================================\n");
                    break;
                case 6:
                    printf("         FOR UPDATE THE MANTH OF BIRTH          \n");
                    printf("please enter your month of birth : ");
                    scanf("%d",&temp->data.birthday.month);
                    printf("================================================\n");
                    break;
                case 7:
                    printf("         FOR UPDATE THE YEAR OF BIRTH           \n");
                    printf("please enter your year of birth : ");
                    scanf("%d",&temp->data.birthday.year);
                    printf("================================================\n");
                    break;
                case 8:
                    printf("         FOR UPDATE THE ADDRESS                 \n");
                    printf("please enter your address : ");
                    scanf("%s",temp->data.address);
                    fflush(stdin);
                    printf("================================================\n");
                    break;
                case 0:
                    break;
                }

        }while(x!=0);

    }
            temp=temp->pNext;
    }
    printf("Student with ID %d is updated !!!\n", ID);
}
void clearQueue(Queue *pq)
{

    if (isempty(pq))
    {
        printf("student list is empty\n");
        return;
    }
    pq->front=NULL;
    pq->rear=NULL;
}
void searchItem(Queue *pq)
{

    Student *temp2=pq->front;
    queueNode *temp=pq->front;
    int ID;
    if (isempty(pq))
    {
        printf("student list is empty\n");
        return;
    }
    printf("Please enter the student ID to search --->");
    scanf("%d",&ID);
    while (temp!=NULL)
    {
        if (temp->data.id==ID)
        {
             printf(" the student of ID %d is founded\n",ID);
             printInfo(temp2);
        }
        temp = temp->pNext;

    }

        printf(" the student of ID %d not founded !!!\n",ID);
}
/*void swap(queueNode *a, queueNode *b)
{
    queueNode temp = a->data;
    a->data = b->data;
    b->data = temp;
}*/
void RANK_STUDENT(Queue *pq)
{
        queueNode *temp1;
        queueNode *temp2;
        Student hold;
        if (isempty(pq))
        {
            printf("student list is empty\n");
            return;
        }
         for (temp1=pq->front;temp1!=NULL;temp1=temp1->pNext)
         {
             for (temp2=temp1->pNext;temp2!=NULL;temp2=temp2->pNext)
             {
                 if ((temp2->data.score) > (temp1->data.score))
                 {
                     hold = temp1->data;
                     temp1->data=temp2->data;
                     temp2->data=hold;
                     //swap(temp1,temp2);
                 }
             }
         }
         printf("RANK IS DOND ENTER 2 AT NEXT TO CHECK\n");
         //STUDENT_LIST(temp2);

}
