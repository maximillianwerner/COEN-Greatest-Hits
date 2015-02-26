/*
 * Max Werner
 * COEN 12 Project 5
 * 5/23/14
 *
 * This is an ADT .c file that manipulates binary trees.
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include "tree.h"

//This declares what a tree is.
struct tree
{
	int data;
	struct tree *left;
	struct tree *right;
	struct tree *parent;
};
void detach();

//This function will create a tree in a runtime of O(1).  
struct tree *createTree(int data, struct tree *left, struct tree *right)
{
	struct tree *root;
	root=malloc(sizeof(struct tree));
	assert(root!=NULL);
	root->data=data;
	root->parent=NULL;
	//This allows the left and right children to be inserted even if they have parents.
	root->left=left;
	root->right=right;
	if(root->left!=NULL)
	{	
		detach(root->left);
		root->left->parent=root;
	}
	if(root->right!=NULL)	
	{	
		detach(root->right);
		root->right->parent=root;
	}	
	return root;
}

//This function recursively deallocates the memory for a tree in a runtime of O(n).
void destroyTree(struct tree *root)
{
	if(root!=NULL)
	{	
		destroyTree(root->left);
		destroyTree(root->right);
		free(root);
	}
}

//This function is not a reuired one but it helps sever the pointer to the parent. It has a runtime of O(1).
void detach(struct tree *root)
{
	root->parent=NULL;
}

//This returns the data in a leaf or root.  Runtime of O(1).
int getData(struct tree *root)
{
	return root->data;
}

//This returns the left child of a root. Runtime of O(1).
struct tree *getLeft(struct tree *root)
{
	return root->left;
}

//This returns the right child of a root. Runtime of O(1).
struct tree *getRight(struct tree *root)
{
	return root->right;
}

//This returns the parent of a given root. Runtime of O(1).
struct tree *getParent(struct tree *root)
{
	return root->parent;
}

//This updates the left child of a root by making sure the left value the new inserted value. Runtime of O(1).
void setLeft(struct tree *root, struct tree *left)
{
	if(root->left!=NULL)
	{
		root->left->parent=NULL;
		root->left=left;
		if(root->left!=NULL)
			detach(root->left);
	}
	root->left=left;
}
//This updates the right child of a root by making sure the right value the new inserted value. Runtime of O(1).
void setRight(struct tree *root, struct tree *right)
{
	if(root->right!=NULL)
	{	
		root->right->parent=NULL;
		root->right=right;
		if(root->right!=NULL)
			detach(root->right);
	}
	root->right=right;
}
