/************************ Single Linked list Operations******************************
1. Create ,2. Display ,

3. Add at begining, 4.Add at last, 5. Add after node (insert node) 6. Add before node

7. Del begining node, 8. Del last node, 9. Del particular node

10. Search node


*/


#include<stdio.h>
#include<stdlib.h>

// function declaration
void creat_list(int *,int);
void display();
void add_at_beginning(int);
void add_at_last(int);
void insert_node(int);
void del_at_beginning();
void del_last_node();
void del_particular(int);
void search(int);

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
	int *arr;

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

	// Deallocating dynamic memory which is present in heap segment after used
	free(arr);
	printf("after deallocate array, arr address: %x\n",arr);

	// function invocation:- Display single linked list data
	display();

	// function invocation:- add node to beginning of linked list
	printf("Enter data to add node at beginning:\n");
	scanf("%d",&input);

	add_at_beginning(input);
	display();

	// function invocation:- add node to last of linked list
	printf("Enter data to add node at last:\n");
	scanf("%d",&input);

	add_at_last(input);
	display();

	// function invocation:- add node to last of linked list
	printf("Enter data to insert node:\n");
	scanf("%d",&input);

	insert_node(input);
	display();

	del_at_beginning();
	display();

	del_last_node();
	display();


	// function invocation:- delete particular node of linked list
	printf("\nEnter node for deletion :\n");
	scanf("%d",&input);

	del_particular(input);
	display();

	// function invocation:- delete particular node of linked list
	printf("\nEnter search node data :\n");
	scanf("%d",&input);

	search(input);
	display();
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
		ptr_node = (struct node*)malloc(1 * sizeof(struct node*));

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
