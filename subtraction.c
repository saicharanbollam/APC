/*******************************************************************************************************************************************************************
*Title			: Subtraction
*Description		: This function performs subtraction of two given large numbers and store the result in the resultant list.
*Prototype		: int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"
#include <stdio.h>
#include <stdlib.h>
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR) 
{
    int borrow = 0, diff, flag = 0;
    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;
    if ((*head1)->data < 0 && (*head2)->data < 0)
    {
        (*head1)->data = -(*head1)->data;
        (*head2)->data = -(*head2)->data;
        subtraction(head2, tail2, head1, tail1, headR, tailR); 
        return SUCCESS;
    }
    else if ((*head1)->data < 0)
    {
        (*head1)->data = -(*head1)->data;
        addition(head1, tail1, head2, tail2, headR, tailR); 
        (*headR)->data = -(*headR)->data;
        return SUCCESS;
    }
    else if ((*head2)->data < 0)
    {
        (*head2)->data = -(*head2)->data;
        return addition(head1, tail1, head2, tail2, headR, tailR); 
    }

    
    // Check which number is greater
    if (find_larger(head1, head2) == FAILURE) {
        // Swap the lists if the second number is larger
        temp1 = *tail2;
        temp2 = *tail1;
        flag = 1;  // Set flag for negative result
    }
    else if(find_larger(head1, head2) == EQUAL) 
    {
	diff=0;
	create_result_node( headR , tailR , diff ) ;
	return SUCCESS ;
    }
	
    while (temp1 != NULL || temp2 != NULL) 
    {
        int num1 = (temp1 != NULL) ? temp1->data : 0;
        int num2 = (temp2 != NULL) ? temp2->data : 0;

        if (num1 < num2 + borrow) {
            diff = num1 + 10 - num2 - borrow;
            borrow = 1;
        } else {
            diff = num1 - num2 - borrow;
            borrow = 0;
        }

        create_result_node(headR, tailR, diff);

        if (temp1 != NULL) temp1 = temp1->prev;
        if (temp2 != NULL) temp2 = temp2->prev;
    }

    // Removing zeros
   	remove_zeros(headR, tailR);

    // If flag is set, multiply with - for negative result
    if (flag == 1) {
        (*headR)->data = -(*headR)->data;
    }

    return SUCCESS;
}

