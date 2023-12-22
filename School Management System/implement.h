#ifndef IMPLEMENT_H_INCLUDED
#define IMPLEMENT_H_INCLUDED
#include <stdbool.h>


//implement struct
typedef struct date {
    int day;
    int month;
    int year;
 }Date;

 typedef struct student_list {
    int id;
    char student_name [100];
    char address[100];
    int phoneNumber;
    int score;
    Date birthday;
 }Student;

 //implement node
typedef struct mynode {
    Student data;
    struct mynode *pNext;
}queueNode;

typedef struct myqueue{
    queueNode *front;
    queueNode *rear;
   // queueNode *Qsize;
}Queue;

void MAIN_MENU();
void creatQueue(Queue *pq);
void NEW_STUDENT(Queue *pq);
void DELETE_STUDENT (Queue *pq);
bool isFull(Queue *pq);
bool isempty(Queue *pq);
void STUDENT_LIST(Queue *pq);
void STUDENT_EDIT(Queue *pq);
void clearQueue(Queue *pq);
void searchItem(Queue *pq);
void RANK_STUDENT(Queue *pq);
#endif // IMPLEMENT_H_INCLUDED
