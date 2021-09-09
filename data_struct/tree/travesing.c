/*********************** Non linear Data Structure - Tree *******************************
		Traversing Technique: A. In-order
							  B. Pre-order
							  C. Post-order

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
void inorder(struct node *);
void preorder(struct node *);

int main()
{
	struct node *root;

	//Requesting mem. for first node of tree
	root = (struct node *) malloc(sizeof(struct node));

	// Updating data to node;
	root->left = NULL;
	root->data = 50;
	root->right = NULL;

	// Adding new node
	traverse(root,30);
	traverse(root,70);
	traverse(root,20);
	traverse(root,40);
	traverse(root,60);
	traverse(root,80);
	traverse(root,65);

	// Traverse tree to get all node data
	// Inoreder technique
	printf("\nInorder travesersing: \n");
	inorder(root);
	printf("\nPreorder travesersing:  \n");
	preorder(root);
	printf("\nPostorder travesersing: \n");
	postorder(root);
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
			traverse(tnode->left,val);
		else
			insert(tnode,val,'l');
	}
	else
	{
		//check, if empty -> Add new node to right subtree
		if(tnode->right != NULL)
			traverse(tnode->right,val);
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
		printf("Adding node to left side\n");
		//Add new node to left subtree
		tnode->left = new_node;
	}
	else
	{
		printf("Adding node to right side\n");
		//Add new node to right subtree
		tnode->right = new_node;
	}
}


/******************** Inorder technique *********************
Ones we get access to a node
	1. With the help of  left address part, traverse left subtree
	2. After complete traversing left subtree access data part
	3. With the help of right address part, traverse right subtree
*/

void inorder(struct node *cur)
{
	// break condition(for recursively call)
	if(cur != NULL)
	{
		// traverse to left subtree
		inorder(cur->left);

		printf("%d\t",cur->data);

		// traverse to right subtree
		inorder(cur->right);
	}
}


/******************** Pre-order technique *********************
Ones we get access to a node
	1. Access data part
	2. With the help of  left address part, traverse left subtree
	3. With the help of right address part, traverse right subtree
*/

void preorder(struct node *cur)
{
	// break condition(for recursively call)
	if(cur != NULL)
	{

		printf("%d\t",cur->data);

		// traverse to left subtree
		preorder(cur->left);

		// traverse to right subtree
		preorder(cur->right);
	}
}



/******************** Post-order technique *********************
Ones we get access to a node
	1. With the help of  left address part, traverse left subtree
	2. With the help of right address part, traverse right subtree
	3. Access data part
*/

void postorder(struct node *cur)
{
	// break condition(for recursively call)
	if(cur != NULL)
	{
		// traverse to left subtree
		postorder(cur->left);

		// traverse to right subtree
		postorder(cur->right);

		printf("%d\t",cur->data);
	}
}
