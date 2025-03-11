#ifndef APC_H
#define APC_H
#define SUCCESS 0
#define FAILURE -1
#define EQUAL -2

typedef int data_t;
typedef struct node
{
	struct node *prev;
	data_t data;
	struct node *next;
}Dlist;

/* Include the prototypes here */
int addition(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR , Dlist **tailR ) ;
int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR , Dlist **tailR ) ;
int multiplication(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR , Dlist **tailR) ;
int division(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR , Dlist **tailR) ;
int create_operand( char *opnd , Dlist **head , Dlist **tail ) ;
void print_list(Dlist *head) ;
int create_result_node( Dlist **headR , Dlist **tailR , data_t data ) ;
void remove_zeros( Dlist **headR , Dlist **tailR ) ;
void add_zero_at_last(  Dlist **headR , Dlist **tailR  ) ;
int delete_list(  Dlist **head , Dlist **tail ) ;
int find_larger( Dlist **head1 , Dlist **head2 ) ;
int insert_at_last( Dlist **headR , Dlist **tailR , data_t data );
#endif
