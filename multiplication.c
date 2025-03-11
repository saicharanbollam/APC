/*******************************************************************************************************************************************************************
*Title			: Multiplication
*Description		: This function performs multiplication of two given large numbers and store the result in the resultant list.
*Prototype		: int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
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
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR)
{

    // If multiplying by 1, result is the same as head1
    if ((*head2)->data == 1 && (*tail2)->prev == NULL)
    {
        *headR = *head1;
        *tailR = *tail1;
        return SUCCESS;
    }
    if ((*head1)->data == 1 && (*tail1)->prev == NULL)
    {
        *headR = *head2;
        *tailR = *tail2;
        return SUCCESS;
    }

    int neg_flag= 0;
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
    Dlist *temp2 = *tail2;  // Start from the least significant digit
    Dlist *partialHead = NULL, *partialTail = NULL;
    Dlist *sumHead = NULL, *sumTail = NULL;
    int Count = 0; // Track number of zeros to add (like shifting left in multiplication)

    while (temp2 != NULL)
    {
        Dlist *temp1 = *tail1;
        partialHead = NULL;
        partialTail = NULL;
        int carry = 0;

        // Multiply head1 with single digit from head2
        while (temp1 != NULL)
        {
            int product = (temp1->data * temp2->data) + carry;
            int digit = product % 10;
            carry = product / 10;

            create_result_node(&partialHead, &partialTail, digit);
            temp1 = temp1->prev;
        }
        if (carry > 0)
        {
            create_result_node(&partialHead, &partialTail, carry);
        }

        // Add zeros (shift left)
        for (int i = 0; i < Count; i++)
        {
            add_zero_at_last(&partialHead, &partialTail);
        }
        Count++;

        // Add current partial result to final sum
        if (sumHead == NULL)
        {
            sumHead = partialHead;
            sumTail = partialTail;
        }
        else
        {
            Dlist *newSumHead = NULL, *newSumTail = NULL;
            addition(&sumHead, &sumTail, &partialHead, &partialTail, &newSumHead, &newSumTail);

            // Delete the old sum list after addition
            if(sumHead !=NULL)
                delete_list(&sumHead, &sumTail);

            // Update sum list with new result
            sumHead = newSumHead;
            sumTail = newSumTail;
        }


        temp2 = temp2->prev;
    }

    // Store the final result
    *headR = sumHead;
    *tailR = sumTail;
    remove_zeros(headR, tailR);
    if (neg_flag && *headR != NULL)
    {
        (*headR)->data = -(*headR)->data;
    }
    return SUCCESS;
}


