#include <stdio.h>
#include <stdlib.h>
#include"implement.h"

int main()
{
    int x=0;
    Queue k;

    MAIN_MENU();
    creatQueue(&k);

    while(true)
    {
        printf("Enter your choose please ---> ");
        scanf("%d",&x);
        switch (x)
            {
            case 1 :
                printf("              ADD A NEW STUDENT                 \n");
                NEW_STUDENT(&k);
                printf("================================================\n");
                break;
            case 2 :
                printf("          PRINT THE LIST OF STUDENTS            \n");
                STUDENT_LIST(&k);
                printf("================================================\n");
                break;
            case 3:
                printf("          DELETE THE STUDENT WITH ID            \n");
                DELETE_STUDENT(&k);
                printf("================================================\n");
                break;
            case 4:
               printf("           UPDATE THE STUDENT WITH ID            \n");
               STUDENT_EDIT(&k);
               printf("=================================================\n");
               break;
            case 5:
               printf("             CLEAR THE STUDENT LIST              \n");
               clearQueue(&k);
               printf("=================================================\n");
               break;
            case 6:
               printf("         SEARCH ABOUT A STUDENT WITH ID          \n");
               searchItem(&k);
               printf("=================================================\n");
               break;
            case 7:
               printf("             RANK THE STUDENT LIST               \n");
               RANK_STUDENT(&k);
               printf("=================================================\n");
               break;
            default:
                printf("Wrong Input \n");
                break;

            }
    }



    return 0;
}
