/************************Switch case: Double Linked list Operations******************************
1. Create ,2. Display ,

3. Add at begining, 4.Add at last, 5. Add after node 6. Add before node  7. insert node

8. Del begining node, 9. Del last node, 10. Del particular node

11. Search node 12. Del entire 13.count nodes 14. Reverse list

*/


#include<stdio.h>
#include<stdlib.h>

// function declaration
void creat_list(int *,int);
void display();
void add_at_beginning(int);
void add_at_last(int);
void add_before_node(int,int);
void add_after_node(int,int);
void insert_node(int);
void del_at_beginning();
void del_last_node();
void del_particular(int);
void search(int);
void del_entire();
void count_nodes();
void reverse_list();

// node data structure( structure + pointer)
struct node
{
	struct node *prev;
	int data;
	struct node *next;
};

// pointer to store new created node by using dynamic mem.
struct node *ptr_node;
// pointer to store linked list first node address
struct node *head = NULL;
// pointer to store linked list current node address
struct node *cur;

int main()
{
	//Array input taken from user
	int i;	// for loop counter
	int n;	// input: no of elements
	int input;	//input from user
	int new_data;
	int *arr;
	int option;

	while(1)
	{
		printf("\nEnter option of double link list operations:\n");
		printf("1. Create\n2. Display\n3. Add at begining\n4. Add at last\n5. Add before node\n6. Add after node\n7. insert node\n8. Del begining node\n9. Del last node\n10. Del particular node\n11. Search node\n12. Delete entire list\n13. Count nodes\n14. Reverse list\n");
		scanf("%d",&option);

		switch(option)
		{

			case 1:
				printf("Enter no of the elements");
				scanf("%d",&n);

				// Creating memory for array dynamically
				arr = (int *)malloc( n * sizeof(int));

				printf("dynamic array mem: %p\n",arr);

				printf("Enters numbers\n");

				for(i=0;i<n;i++)
				{
					scanf("%d",&arr[i]);
					printf("Entered element is: %d\n Enter next element\n",arr[i]);
				}

				// Integer array
				//int arr[4]={1,2,3,4};

				// function invocation -> to create single linked list from array data
				creat_list(arr,n);

				// function invocation:- Display single linked list data
				display();
				break;

			case 2:
				display();
				break;

			case 3:
				// function invocation:- add node to beginning of linked list
				printf("Enter data to add node at beginning:\n");
				scanf("%d",&input);

				add_at_beginning(input);
				display();
				break;

			case 4:
				// function invocation:- add node to last of linked list
				printf("Enter data to add node at last:\n");
				scanf("%d",&input);

				add_at_last(input);
				display();
				break;

			case 5:
				// function invocation:- add before node
				printf("Enter new node:\n");
				scanf("%d",&new_data);

				printf("Enter existing node:\n");
				scanf("%d",&input);

				add_before_node(new_data,input);
				display();
				break;


			case 6:
				// function invocation:- add after node
				printf("Enter new node:\n");
				scanf("%d",&new_data);

				printf("Enter existing node:\n");
				scanf("%d",&input);

				add_after_node(new_data,input);
				display();
				break;

			case 7:
				// function invocation:- insert node to appropriate position in linked list
				printf("Enter data to insert node:\n");
				scanf("%d",&input);

				insert_node(input);
				display();
				break;

			case 8:
				del_at_beginning();
				display();
				break;

			case 9:
				del_last_node();
				display();
				break;

			case 10:
				// function invocation:- delete particular node of linked list
				printf("\nEnter node for deletion :\n");
				scanf("%d",&input);

				del_particular(input);
				display();
				break;

			case 11:
				// function invocation:- Search node of linked list
				printf("\nEnter search node data :\n");
				scanf("%d",&input);

				search(input);
				display();
				break;

			case 12:
				// function invocation:- Delete entire linked list

				del_entire();
				display();
				break;

			case 13:
				// function invocation:-count no of nodes in linked list

				count_nodes();
				display();
				break;

			case 14:
				// function invocation:- Reverse linked list
				reverse_list();
				display();
				break;

			default:
				printf("Enter correct option\n");
				break;
		}

	}
}

// ************************** Creat linked list function **********************


void creat_list(int *ptr_arr,int n)
{
	int i;

	printf("In creat_list function\n");
	printf("Array address: %p, no of elements: %d, first: %d\n",ptr_arr,n,ptr_arr[0]);

	if(head != NULL)
	{
		cur = head;
		while(cur->next != NULL)
		{
			cur = cur->next;
		}
	}


	for(i=0;i<n;i++)
	{
		// creating mem. for new node which is type struct node
		ptr_node = (struct node*)malloc(1 * sizeof(struct node));

		printf("mem. created\n");

		ptr_node->data = ptr_arr[i];

		ptr_node->next = NULL;

		if(head == NULL)
		{
			ptr_node->prev = NULL;
			head = ptr_node;

		}
		else
		{
			ptr_node->prev = cur;

			printf("cur next:%p , ptr node: %p \n",cur,ptr_node);
			cur->next = ptr_node;
		}

		cur = ptr_node;
	}

}

// *************************** Display function (Single linked list) **********************


void display()
{
	int pos = 0;
	cur = head;

	printf("\nIn Display function\n");

	//Case 1st: list is empty
	if(head == NULL)
	{
		printf("List is empty\n");
		return;
	}

	//Case 2nd:- List contain nodes (traversing and diplay)

	while(cur != NULL)
	{
		// Displaying linked list node data
		printf("Node pos:%d, Data:%d\n",pos,cur->data);
		// updating cur pointer to next node base address
		cur = cur->next;
		pos++;
	}

}




// *************************** Node to Add at beginning **********************

void add_at_beginning(int val)
{
	printf("In add at beginning function\n");

	ptr_node = (struct node *) malloc( 1*sizeof(struct node) );

	//updating data part
	ptr_node->data = val;

	ptr_node->next = head;
	ptr_node->prev = NULL;

	if(head == NULL)
	{
		head = ptr_node;
		return;
	}

	head->prev = ptr_node;

	head = ptr_node;

}


// *************************** New Node to Add at last **********************

void add_at_last(int val)
{
	printf("In add at last function\n");

	// Request mem. for new node(Heap segment)
	ptr_node = (struct node*) malloc( 1*sizeof(struct node*));

	// Updating new node data and link part
	ptr_node->data = val;
	ptr_node->next = NULL;

	// case 1st: Check linked list empty or not
	if(head == NULL)
	{
		head = ptr_node;
		ptr_node->prev = NULL;
		return;
	}

	// Traversing till last node
	cur = head;
	while(cur->next != NULL)
	{
		cur = cur->next;
	}
	// Adding new node to last of linkded list
	cur->next = ptr_node;
	ptr_node->prev = cur;

}


// *************************** Add before node **********************

void add_before_node(int val,int node_data)
{

	printf("IN add before node fun\n");

	//case 1: list is empty
	if(head == NULL)
	{
		printf("list is empty\n");
		return;
	}

	// Requesting mem. and update new node data part
	ptr_node = malloc( 1*sizeof(struct node) );

	ptr_node->data = val;

	//case 2: If add before first node
	if(head->data == node_data)
	{
		ptr_node->next = head;
		ptr_node->prev = NULL;

		head->prev = ptr_node;

		head = ptr_node;
		return;
	}

	//case 3: list contain nodes
	// first node check in case 2 ,now move to next node

	//prev = head;
	cur = head->next;

	while(cur != NULL)
	{
		if(cur->data == node_data)
		{
			// Add new node before node
			// previous node
			(cur->prev)->next = ptr_node;
			//new node
			ptr_node->prev = cur->prev;
			ptr_node->next = cur;
			// current node
			cur->prev = ptr_node;
			return;
		}

		//prev = cur;
		cur = cur->next;
	}
	printf("Node not found\n");
	free(ptr_node);
}




// *************************** Add after node **********************


void add_after_node(int val,int node_data)
{

	printf("IN add after node fun\n");

	//case 1: list is empty
	if(head == NULL)
	{
		printf("list is empty\n");
		return;
	}

	// Requesting mem. and update new node data part
	ptr_node = malloc( 1*sizeof(struct node) );

	ptr_node->data = val;

	//case 2: list contain nodes
	cur = head;

	while(cur != NULL)
	{
		if(cur->data == node_data)
		{
			// Add new node after node
			// new node
			ptr_node->next = cur->next;
			ptr_node->prev = cur;
			// next node
			if(cur->next != NULL)
			{
				(cur->next)->prev = ptr_node;
			}
			//current node
			cur->next = ptr_node;

			return;
		}

		cur = cur->next;
	}
	printf("Node not found\n");
	free(ptr_node);
}



// ***************************  Insert node  **********************

	//case 1: list is empty, case2: if add before first node, case3: if its middle node, case4: if add after last node

void insert_node(int val)
{

	struct node *prev;

	printf("In insert node function\n");

	// Request mem. for new node(Heap segment)
	ptr_node = malloc( 1 * sizeof(struct node) );
	//Updating data part with user enter data
	ptr_node->data = val;

	// Case 1st: list is empty
	if(head == NULL)
	{
		printf("List is empty\n");

		head = ptr_node;
		ptr_node->next = NULL;
		ptr_node->prev = NULL;
		return;
	}

	// traversing & searching perticular node
	cur = head;

	while(cur != NULL)
	{
		prev = cur;
		if(val > cur->data)
		{
			cur = cur->next;
		}

		else
		{
			// Insert node before current node
			if(cur == head)
			{	// case 2: if its first node
				head = ptr_node;
			}
			else
			{
				(cur->prev)->next = ptr_node;
			}
			ptr_node->prev = cur->prev;
			ptr_node->next = cur;

			cur->prev = ptr_node;

			return;
		}


	}
	//case4: If its last node
	// Add after last node
	ptr_node->next = NULL;
	ptr_node->prev = prev;

	prev->next = ptr_node;

}



// *************************** Delete beginning node **********************

void del_at_beginning()
{

	printf("\nDeleting beginnig node\n");

	if(head == NULL)
	{
		printf("List is empty\n");
		return;
	}

	// Case 2: IF its first and last node
	if(head-> next == NULL)
	{
		free(head);
		head = NULL;
		return;
	}


	//case 3: list contine nodes
	// Get beginning node base address
	cur = head;
	// Updating head pointer to 2nd node
	head = head->next;
	head->prev = NULL;
	// Deallocating first node
	free(cur);
}


// *************************** Delete last node **********************


void del_last_node()
{

	printf("Deleting last node");

	// Case 1: List is empty
	if(head == NULL)
	{
		printf("List is empty\n");
		return;
	}

	//Case 2: If its first and last node
	if(head->next == NULL)
	{
		// Getting first & last node structure base address to temporary pointer
		cur = head;
		// Updating head pointer with NULL(Linked list empty)
		head = NULL;
		// Deallocating node
		free(cur);
		return;
	}


	//case 3: list contain nodes
	// first node check in case 2, now check from 2nd node
	cur = head->next;

	// traversing till last node
	while(cur->next != NULL)
	{
		cur = cur->next;
	}

	cur->prev->next = NULL;
	free(cur);
}


//  *************************** Delete particular node **********************


void del_particular(int val)
{

	printf("In del particular function, Val: %d\n",val);
	// case 1: list is empty
	if(head == NULL)
	{
		printf("list is empty\n");
		return;
	}

	//case 2: If its first & check if its last node
	if(head->data == val)
	{
		// Getting particular node strut. base addr to temp pointer
		cur = head;
		// update head pointer with next node base addr
		head = head->next;
		if(head == NULL)
		{	//last node
			// Deallocate particular node
			free(cur);
			return;
		}
		else
		{
			head->prev = NULL;
		}

		// Deallocate particular node
		free(cur);
		//return;
	}

	//case 3: middle node

	// check first node in case 2, now move forward

	cur = head->next;

	while(cur!= NULL)
	{
		if(cur->data == val)
		{
			// updating previous node link part with next node base address
			cur->prev->next = cur->next;
			if(cur->next != NULL)
			{
				cur->next->prev = cur->prev;
			}
			// check any duplicate nodes
			cur = cur->prev;

			//free(cur);
		}

		cur = cur->next;
	}
}


// *************************** Serch node **********************

void search(int val)
{
	int pos = 0;

	//case 1: list is empty
	if(head == NULL)
	{
		printf("List is empty\n");
		return;
	}

	cur = head;
	//case 2: List contain nodes

	while(cur!= NULL)
	{
		if(cur->data == val)
		{
			printf("Node found at pos: %d\n",pos);
			return;
		}

		cur = cur->next;
		pos++;
	}
	printf("Search node not found\n");
}

// *************************** Delete entire linked list **********************


void del_entire()
{

	while(head != NULL)
	{
		// Updating cur pointer to first node for deltion
		cur = head;
		// Updation head to next node base address
		head = head->next;

		free(cur);
	}
	printf("Linked list deleted succesfully\n");
}

// *************************** Count nodes **********************

void count_nodes()
{
	int pos = 0;

	printf("\nIn count nodes function\n");

	cur = head;

	while(cur != NULL)
	{
		// updating cur pointer to next node base address
		cur = cur->next;
		pos++;
	}

	printf("Nodes count is: %d\n",pos);
}



// *************************** Reverse linked list **********************



void reverse_list()
{
	struct node *temp;

	printf("In reverse list function\n");

	//case 1: list is empty
	if(head == NULL)
	{
		printf("List is empty\n");
		return;
	}

	cur = head;

	while(cur != NULL)
	{

		if(cur->next == NULL)
		{
			head = cur;
		}
		temp = cur->next;
		cur->next = cur->prev;
		cur->prev = temp;

		cur = temp;
	}


}


