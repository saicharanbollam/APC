/*******************************************************************************************************************************************************************
*Title			: Division
*Description		: This function performs division of two given large numbers and store the result in the resultant list.
*Prototype		: int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"
#include <stdio.h>
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{
    int count = 0;
    int neg_flag= 0;
    if (((*head1 == NULL) &&  (*head2 == NULL)) || ((*head1)->data == 0 && (*head2)->data == 0))
    {
        printf("Result is undefined\n");
        return FAILURE;

    }
    if (*head1 == NULL || (*head1)->data == 0)
    {
        create_result_node(headR, tailR, 0);
        return SUCCESS;
        
    }
    // Case: Division by zero
    if (*head2 == NULL || (*head2)->data == 0)
    {
        printf("Error: Division by zero\n");
        return FAILURE;
    }

    // Case: Division by one
    if ((*head2)->data == 1 && (*head2)->next == NULL)
    {
        *headR = *head1;
        *tailR = *tail1;
        return SUCCESS;
    }
     if ((*head1)->data < 0)
    {
        (*head1)->data = -(*head1)->data;
        neg_flag = !neg_flag;
    }
    if ((*head2)->data < 0)
    {
        (*head2)->data = -(*head2)->data;
        neg_flag = !neg_flag;
    }
    if (find_larger(head1, head2) == FAILURE)
    {
        create_result_node(headR, tailR, 0);
        return SUCCESS;
    }

    if (find_larger(head1, head2) == EQUAL)
    {
	if(neg_flag)
		create_result_node(headR, tailR, -1);
	else
        	create_result_node(headR, tailR, 1);
        return SUCCESS;
    }

    Dlist *temp1 = *head1;
    Dlist *temp2 = *tail1;
    Dlist *res1 = NULL, *res2 = NULL;

    // **Repeated Subtraction Method**
    while (find_larger(&temp1, head2) != FAILURE)
    {
        subtraction(&temp1, &temp2, head2, tail2, &res1, &res2);

        // Ensure subtraction did not return NULL
        if (res1 == NULL)
        {
            printf("Error: Subtraction failed\n");
            return FAILURE;
        }

        temp1 = res1;
        temp2 = res2;
        res1= NULL;
        res2 = NULL;
        count++;
    }

    // Store quotient in result list
    create_result_node(headR, tailR, count);
    if (neg_flag && *headR != NULL)
    {
        (*headR)->data = -(*headR)->data;
    }

    return SUCCESS;
}

