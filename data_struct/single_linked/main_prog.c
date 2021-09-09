/************************Switch case: Single Linked list Operations******************************
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
	int data;
	struct node *link;
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
		printf("\nEnter option of single link list operations:\n");
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

/*************************** Creat linked list function **********************
	case 1: list is empty
			1. Request os(/kernel/memory management) to create  mem. dynamically
			2. update node data from user array & node link with NULL
			3. if previous node available then update its link portion with new node base address
			4. repeat 1 to 3 step till no of array elements available for creation of node in linked list

	case 2: list contain nodes
				1. Traverse till last node
				2. follow case 1 steps

*/
void creat_list(int *ptr_arr,int n)
{
	int i;

	printf("In creat_list function\n");
	printf("Array address: %p, no of elements: %d, first: %d\n",ptr_arr,n,ptr_arr[0]);


	if(head != NULL)
	{
		cur = head;
		while(cur->link != NULL)
		{
			cur = cur->link;
		}
	}


	for(i=0;i<n;i++)
	{
		// creating mem. for new node which is type struct node
		ptr_node = (struct node*)malloc(1 * sizeof(struct node));

		printf("new mem: %p\n",ptr_node);

		// Update data part of new node with array element
		ptr_node->data = ptr_arr[i];
		// Update link part of new node with NULL adress(denoting last node)
		ptr_node->link = NULL;

		if(head == NULL)
		{
			// updating head with new first node base address
			head = ptr_node;
			// updating cur pointer with first node of linked list
			cur = head;
		}
		else
		{
			// updating current linked list node link part with new node base address(to add last)
			cur->link = ptr_node;
			// Now new node become last node
			cur = ptr_node;
		}
	}

}

/*************************** Display function (Single linked list) **********************
	case 1: list is empty

	case 2: list contine nodes
				1. Access each and every node, display its data part (traversing)

*/
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
		cur = cur->link;
		pos++;
	}

}


/*************************** Node to Add at beginning **********************
	1. Requst mem. for new node
	2. Update its data part
	3. Add the new node at the begnning of list

	case 1: list is empty
	case 2: list contine nodes

*/
void add_at_beginning(int val)
{
	printf("In add at beginning function\n");

	ptr_node = (struct node *) malloc( 1*sizeof(struct node *) );

	//updating data part
	ptr_node->data = val;

	//updating link part of node
	ptr_node->link = head;

	//adding node to beginning of list
	head = ptr_node;
}


/*************************** New Node to Add at last **********************
	1. Requst mem. for new node
	2. Update its data part and link part(NULL)
	3. Traverse the list and access last node
	4. Update last node link part to new node base address

	case 1: list is empty
	case 2: list contine nodes

*/
void add_at_last(int val)
{
	printf("In add at last function\n");

	// Request mem. for new node(Heap segment)
	ptr_node = (struct node*) malloc( 1*sizeof(struct node*));

	// Updating new node data and link part
	ptr_node->data = val;
	ptr_node->link = NULL;

	// case 1st: Check linked list empty or not
	if(head == NULL)
	{
		head = ptr_node;
		return;
	}

	// Traversing till last node
	cur = head;
	while(cur->link != NULL)
	{
		cur = cur->link;
	}
	// Adding new node to last of linkded list
	cur->link = ptr_node;
}


/*************************** Add before node **********************
	1. Requst mem. for new node
	2. Update its data part
	3. Traverse the list and find perticular node
	4. Add before node

	case 1: list is empty
	case 2: If add before first node
	case 3: list contain nodes

*/
void add_before_node(int val,int node_data)
{
	struct node *prev;

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
		ptr_node->link = head;
		head = ptr_node;
		return;
	}

	//case 3: list contain nodes
	// first node check in case 2 ,now move to next node

	prev = head;
	cur = head->link;

	while(cur != NULL)
	{
		if(cur->data == node_data)
		{
			// Add new node before node
			prev->link = ptr_node;
			ptr_node->link = cur;
			return;
		}

		prev = cur;
		cur = cur->link;
	}
	printf("Node not found\n");
	free(ptr_node);
}




/*************************** Add after node **********************
	1. Requst mem. for new node
	2. Update its data part
	3. Traverse the list and find perticular node
	4. Add after node

	case 1: list is empty
	case 2: list contain nodes

*/
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
			ptr_node->link = cur->link;
			cur->link = ptr_node;
			return;
		}

		cur = cur->link;
	}
	printf("Node not found\n");
	free(ptr_node);
}



/***************************  Insert node  **********************
	find appropriate position to insert node

	1. Requst mem. for new node
	2. Update its data part
	3. Traverse the list find appropriate node
	4. Insert node -
			new node link part update to perticular node link part &
			perticular node link part update to new node base address


	case 1: list is empty
	case 2: list contine nodes

*/
void insert_node(int val)
{
	struct node *prev;

	printf("In insert node function\n");

	// Request mem. for new node(Heap segment)
	ptr_node = malloc( 1 * sizeof(struct node*) );
	//Updating data part with user enter data
	ptr_node->data = val;

	// Case 1st: list is empty
	if(head == NULL)
	{
		printf("List is empty\n");

		head = ptr_node;
		ptr_node->link = NULL;
		return;
	}

	// traversing & searching perticular node
	cur = head;

	while(cur != NULL && cur->data < val)
	{
		prev = cur;
		cur = cur->link;
	}
	// Node found if cur != NULL


	ptr_node->link = cur;
	if(head == cur)
	{
		// found node is first node
		head = ptr_node;
	}
	else
	{
		// Inserting node before found node
		prev->link = ptr_node;
	}

}



/*************************** Delete beginning node **********************
	1. Get first node base addr to temp pointer
	2. Update head to 2nd node of link list
	3. Deallocate first node by using temp pointer


	case 1: list is empty
	case 2: list contine nodes

*/
void del_at_beginning()
{
	struct node *temp;

	printf("\nDeleting beginnig node\n");

	if(head == NULL)
	{
		printf("List is empty\n");
		return;
	}


	//case 2: list contine nodes
	// Get beginning node base address
	temp = head;
	// Updating head pointer to 2nd node
	head = head->link;
	// Deallocating first node
	free(temp);
}


/*************************** Delete last node **********************
		Traversing list till last node
	1. Get last node base addr to temp pointer
	2. Update last 2nd node of link part with NULL
	3. Deallocate last node by using temp pointer


	case 1: list is empty
	case 2: If its first and last node
	case 3: list contain nodes

*/

void del_last_node()
{

	struct node *temp;
	struct node *prev;

	printf("Deleting last node");

	// Case 1: List is empty
	if(head == NULL)
	{
		printf("List is empty\n");
		return;
	}

	//Case 2: If its first and last node
	if(head->link == NULL)
	{
		// Getting first & last node structure base address to temporary pointer
		temp = head;
		// Updating head pointer with NULL(Linked list empty)
		head = NULL;
		// Deallocating node
		free(temp);
		return;
	}


	//case 3: list contain nodes
	// first node check in case 2, now check from 2nd node
	temp = head->link;
	prev = head;

	// traversing till last node
	while(temp->link != NULL)
	{
		prev = temp;
		temp = temp->link;
	}

	prev->link = NULL;
	free(temp);
}



/*************************** Delete particular node **********************
		Traversing and find node to delete

	case 1: list is empty
	case 2: If its first and last node
	case 3: middle node

	1.Treaverse and find node to delete
	2.If its middle node then update previous node link part with next node struc. base addr
	3. Deallocate found node
*/

void del_particular(int val)
{
	struct node *prev;
	struct node *temp;

	printf("In del particular function\n");
	// case 1: list is empty
	if(head == NULL)
	{
		printf("list is empty\n");
		return;
	}

	//case 2: If its first
	if(head->data == val)
	{
		// Getting particular node strut. base addr to temp pointer
		temp = head;
		// update head pointer with next node base addr
		head = head->link;
		// Deallocate particular node
		free(temp);
		//return;
	}

	//case 3: middle node

	// check first node in case 2, now move forward
	prev = head;
	temp = head->link;

	while(temp!= NULL)
	{
		if(temp->data == val)
		{
			// updating previous node link part with next node base address
			prev->link = temp->link;
			free(temp);
			// check any duplicate nodes
			temp = prev;
		}

		prev = temp;
		temp = temp->link;
	}
}



/*************************** Serch node **********************
		Traversing and find node

	case 1: list is empty
	case 2: List contain nodes

	1.Treaverse list and find node


*/

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

		cur = cur->link;
		pos++;
	}
	printf("Search node not found\n");
}

/*************************** Delete entire linked list **********************
		Traversing and find node

	case 1: list is empty
	case 2: List contain nodes

*/

void del_entire()
{

	while(head != NULL)
	{
		// Updating cur pointer to first node for deltion
		cur = head;
		// Updation head to next node base address
		head = head->link;
		free(cur);
	}
	printf("Linked list deleted succesfully\n");
}


/*************************** Count nodes **********************

	1. Treverse till last and count nodes simultaneously

*/
void count_nodes()
{
	int pos = 0;

	printf("\nIn count nodes function\n");

	cur = head;

	while(cur != NULL)
	{
		// updating cur pointer to next node base address
		cur = cur->link;
		pos++;
	}

	printf("Nodes count is: %d\n",pos);
}



/*************************** Reverse linked list **********************

	case 1: list is empty
	case 2: List contain nodes

		1. Update one by one node link part with prev node base address till last node
		2. Update only first node link part with NULL
*/

void reverse_list()
{
	struct node *prev,*next,*cur;

	printf("In reverse list function\n");

	//case 1: list is empty
	if(head == NULL)
	{
		printf("List is empty\n");
		return;
	}

	prev = NULL;
	cur = head;

	while(cur != NULL)
	{

		next = cur->link;
		// Update cur link part with prev node base address
		cur->link = prev;

		// Now cur become previous & next become current
		prev = cur;
		cur = next;
	}

	// At last node, update head with last node base address
	head = prev;

}
