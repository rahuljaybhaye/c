/*********************** Non linear Data Structure - Tree *******************************
*/

#include<stdio.h>
#include<stdlib.h>	//malloc()

struct node
{
	struct node *left;		// pointer to data structure
	int data;
	struct node *right;
};

//function declaration
void traverse(struct node *,int);
void insert(struct node *,int,char);

int main()
{
	struct node *root;

	//Requesting mem. for first node of tree
	root = (struct node *) malloc(sizeof(struct node));

	// Updating data to node;
	root->left = NULL;
	root->data = 10;
	root->right = NULL;

	traverse(root,20);


}
/********************* Traversing tree ********************
	1.If new node value < parent node(existing node)   -> add node to left side
	2.If new node value > parent node(existing node)   -> add node to right side
	3. If node is busy then traverse to next node in step 1 & 2

	Repeatedly (Recursively) follow above steps till get  correct empty node position
*/

void traverse(struct node *tnode,int val)
{
	if(val < tnode->data)
	{
		//check, if empty -> Add new node to left subtree
		if(tnode->left != NULL)
			traverse(tnode,val);
		else
			insert(tnode,val,'l');
	}
	else
	{
		//check, if empty -> Add new node to right subtree
		if(tnode->left != NULL)
			traverse(tnode,val);
		else
			insert(tnode,val,'r');
	}
}


/********************* Insert new node to tree ********************
	1. Request mem. for new node
	2. Update data to new node
	3. Add node to left/right part of subtree

*/

void insert(struct node *tnode,int x,char dirn)
{
	struct node *new_node;

	// Request mem. for new node
	new_node = malloc(1*sizeof(struct node));

	// Update data to new node
	new_node->left = NULL;
	new_node->data = x;
	new_node->right = NULL;


	if(dirn == 'l')
	{
		//Add new node to left subtree
		tnode->left = new_node;
	}
	else
	{
		//Add new node to right subtree
		tnode->right = new_node;
	}
}
