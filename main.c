/**************************************************************************************************************************************************************
Name: B SAI CHARAN REDDY
*Title		: main function(Driver function)
*Description	: This function is used as the driver function for the all the functions
***************************************************************************************************************************************************************/
#include "apc.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	/* Declare the pointers */
	Dlist *head1=NULL, *tail1=NULL, *head2=NULL, *tail2=NULL, *headR=NULL, *tailR=NULL;
	char option, operator;


		/* Code for reading the inputs */

		/* Function for extracting the operator */
		if(argc == 4)
		{
			operator = argv[2][0];
			char *opend1 = argv[1];
			char *opend2 = argv[3];

			if((create_operand(opend1,&head1,&tail1)==SUCCESS)&&(create_operand(opend2,&head2,&tail2)==SUCCESS))
			{

			}
		}
		else
		{
			printf("Invalid arguments\n");
			return 1;
		}

		switch (operator)
		{
			case '+':
				/* call the function to perform the addition operation */
				if ( addition( &head1, &tail1, &head2, &tail2, &headR , &tailR ) == SUCCESS )
				{
					printf("Result of Addition : ") ;
					print_list( headR ) ;
					printf("\n") ;
				}
				break;
			case '-':	
				/* call the function to perform the subtraction operation */
				if( subtraction( &head1 , &tail1 , &head2 , &tail2 , &headR , &tailR ) == SUCCESS ) 
				{
					printf("Result of Subtraction : ") ;
					print_list( headR ) ;
					printf("\n") ;
				}
				break;
			case 'x':	
				/* call the function to perform the multiplication operation */
				if ( multiplication( &head1, &tail1, &head2, &tail2, &headR , &tailR ) == SUCCESS )
				{
					
					printf("Result of Multiplication: ") ;
					print_list( headR ) ;
					printf("\n") ;
					
				}
				break;
			case '/':	
				/* call the function to perform the division operation */
				if( division( &head1, &tail1, &head2, &tail2, &headR , &tailR )  == SUCCESS ) 
				{
		
					printf("Result of Division : ") ;
					print_list( headR ) ; 
					printf("\n") ;
					
				}
				break;
			default:
				printf("Invalid Input:-( Try again...\n");
		}

	return 0;
}

