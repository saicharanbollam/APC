#include <stdio.h>
#include "apc.h"
#include <stdlib.h>
#include <ctype.h>

int create_operand( char *opend , Dlist **head , Dlist **tail )
{
    /*int i=0;
    while(opend[i]!='\0')
    {
	    if(opend[i] == '-')
	    {
		    i++;
		    continue;
	    }		
	    if(isdigit(opend[i])==0)
	    {
	    	printf("Invalid operand\n");
	    	exit(0);
	    }
	    i++;
    }*/
    int is_negative = 0;
    if (*opend == '-') {
        is_negative = 1;
        opend++;
    }
    while (*opend) {
        if (*opend >= '0' && *opend <= '9') 
	{
            insert_at_last(head, tail, *opend - '0');
        }
	else
	{
		printf("Invalid operand\n");
		exit(0);
	}
        opend++;  
    }
    remove_zeros(head, tail);
    if (is_negative && *head != NULL)
    {
        (*head)->data = -((*head)->data);
    }	
    return SUCCESS;
}
int create_result_node( Dlist **headR , Dlist **tailR , data_t data )  // insert_at_first 
{
	Dlist *new = malloc(sizeof(Dlist)) ;
	if ( new == NULL )
		return FAILURE ;
	new->data = data ;
	new->prev = NULL ;
	new->next = NULL ;
		
	if ( *headR == NULL )
	{
		*headR = new ;
		*tailR = new ;
		return SUCCESS ;
	}
	else
	{
		(*headR)->prev  = new ;
		new->next = *headR ;
		*headR = new ;
		return SUCCESS ;
	}
	return FAILURE ;
}
int insert_at_last( Dlist **headR , Dlist **tailR , data_t data )
{
    Dlist *new = malloc(sizeof(Dlist));
    new->data = data;
    new->next = NULL;
    new->prev = NULL;

    if (*headR == NULL)
    {  
        *headR = *tailR = new;
	return SUCCESS;
    } 
    else 
    {
	new->prev = *tailR;
        (*tailR)->next = new;
        *tailR = new;
	return SUCCESS;
    }
    return FAILURE;
}
void print_list(Dlist *head)
{
	/* Cheking the list is empty or not */
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
	else
	{
	   // printf("Head -> ");
	    while (head)
	    {
		    /* Printing the list */
		    printf("%d", head -> data);

		    /* Travering in forward direction */
		    head = head -> next;
	    }
    	}	
}
void  remove_zeros( Dlist **headR , Dlist **tailR )
{

	Dlist *temp = *headR ;

	while (temp->next !=NULL && temp->data == 0 )
	{
		*headR = temp->next ;
		(*headR)->prev = NULL ;
		free( temp) ;
		temp = *headR ;
	}
	return;

}

int delete_list(Dlist **head, Dlist **tail)
{
    if (*head == NULL)
        return FAILURE;

    Dlist *temp = *head;
    while (temp != NULL)
    {
        Dlist *next = temp->next;
        free(temp);
        temp = next;
    }

    *head = NULL;  
    *tail = NULL;
    return SUCCESS;
}

void add_zero_at_last(  Dlist **head , Dlist **tail  )
{
	
    Dlist *new = malloc( sizeof(Dlist)) ;
    if ( new == NULL )
    {
	printf("memory allocation failed\n");
        return ;
    }
    new->data = 0 ;
    new->prev = NULL ;
    new->next = NULL ;

    if ( *head == NULL )
    {
        *head = new ;
        *tail = new ;
        return;
    }
    
    (*tail)->next = new ;
    new->prev = *tail ;
    *tail = new ;
    return;
    
}
int find_larger( Dlist **head1 , Dlist **head2 )
{
	// Find the size of the two lists
	int size1 = 0 ;
	int size2 = 0 ;

	Dlist *temp1 = *head1 ;
	while ( temp1 != NULL )
	{
		size1++ ;
		temp1 = temp1->next ;
	}

	Dlist *temp2 = *head2 ;
	while ( temp2 != NULL )
	{
		size2++ ;
		temp2 = temp2->next ;
	}

	if ( size1 > size2 )
	{
		return SUCCESS ;
	}

	if ( size2 > size1 )
	{
		return FAILURE ;
	}

	temp1 = *head1 ;
	temp2 = *head2 ;

	while (temp1 != NULL && temp2 != NULL)
    	{
        	if (temp1->data > temp2->data)
            		return SUCCESS;
        
        	else if (temp1->data < temp2->data)
        		return FAILURE;
        
        	temp1 = temp1->next;
        	temp2 = temp2->next;
    	}	

    return EQUAL;
}
