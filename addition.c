/*******************************************************************************************************************************************************************
*Title			: Addition
*Description		: This function performs addition of two given large numbers and store the result in the resultant list.
*Prototype		: int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR);
*Input Parameters	: head1: Pointer to the first node of the first double linked list.
			: tail1: Pointer to the last node of the first double linked list.
			: head2: Pointer to the first node of the second double linked list.
			: tail2: Pointer to the last node of the second double linked list.
			: headR: Pointer to the first node of the resultant double linked list.
*Output			: Status (SUCCESS / FAILURE)
*******************************************************************************************************************************************************************/
#include "apc.h"
#include <stdio.h>

int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR,Dlist **tailR)
{
	/* Definition goes here */
	int num1,num2,carry=0,sum=0;
	Dlist *temp1=*tail1;
	Dlist *temp2=*tail2;

	if ((*head1)->data < 0 && (*head2)->data < 0)
    	{
        	(*head1)->data = -(*head1)->data;
        	(*head2)->data = -(*head2)->data;
        	addition(head1, tail1, head2, tail2, headR, tailR);
        	(*headR)->data = -(*headR)->data; 
        	return SUCCESS;
    	}
    	else if ((*head1)->data < 0)
    	{
        	(*head1)->data = -(*head1)->data;
        	return subtraction(head2, tail2, head1, tail1, headR, tailR); 
   	}
    	else if ((*head2)->data < 0)
    	{
       	 	(*head2)->data = -(*head2)->data;
        	return subtraction(head1, tail1, head2, tail2, headR, tailR);
    	}
	while(temp1!=NULL || temp2!=NULL)
	{
		num1 = (temp1 != NULL) ? temp1->data : 0;
        	num2 = (temp2 != NULL) ? temp2->data : 0;
	
		sum=num1+num2+carry;
		create_result_node(headR,tailR,(sum%10));
		carry=sum/10;

		if (temp1 != NULL) temp1 = temp1->prev;
        	if (temp2 != NULL) temp2 = temp2->prev;
	}
	if(carry!=0)
	{
		create_result_node(headR,tailR,carry);
	}
	 remove_zeros(headR, tailR);
	 return SUCCESS;
}

