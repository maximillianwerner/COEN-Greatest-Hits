/*
 * Max Werner
 * COEN 12 Project 5
 * 5/23/14
 *
 *This is the implementation of the tree.c ADT that uses Huffman coding with a binary heap. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "tree.h"
#include "pack.h"

#define PARENT(i) ((i-1)/2)
#define RIGHTCHILD(i) (2*i+2)
#define LEFTCHILD(i) (2*i+1)

//Protoptypes.
void insert();
void printTree();
struct tree *deleteMin();

//This is the count for how many elements are in the heap.
int heapCount=0;

int main(int argc,char *argv[])
{
	if(argc!=3)
	{
		printf("Incorrect number of files passed. Please run again.\n");
		return 1;
	}
	FILE *fp,*fp2;
	int c;
	int i;
	int k;
	int count[257];
	struct tree *leaves[257];
	struct tree *heap[257];
	struct tree *left;
	struct tree *right;
	struct tree *new;
	//Initializations.
	for(i=0;i<257;i++)
	{	
		count[i]=0;
		leaves[i]=NULL;
		heap[i]=NULL;
	}
	fp=fopen(argv[1],"r");
	fp2=fopen(argv[2],"w");
	if(fp==NULL)
	{
		printf("Empty input file.\n");
		return 1;
	}							
	//This reads through the text file and puts every character into an array as an int.
	while((c=getc(fp))!=EOF)
		count[c]++;
	//This loop creates a tree for every character that occurs once or more and then inserts that tree into a heap.
	for(i=0;i<257;i++)
	{	
		if(count[i]>0)
		{	
			leaves[i]=createTree(count[i],NULL,NULL);
			insert(heap,leaves[i]);
		}
	}
	//The is for the end of file character.
	leaves[256]=createTree(0,NULL,NULL);
	insert(heap,leaves[256]);
	//This loop is where the huffman tree is created.  It deletes the two lowest priority elements, combines them, and then inserts the new tree back into the heap until there is only 1 root.
	while(heapCount>1)
	{
		left=deleteMin(heap);
		right=deleteMin(heap);
		new=createTree(getData(left)+getData(right),left,right);
		insert(heap,new);	
	}
	//This is for the printing out of the bit path for each character.
	for(k=0;k<257;k++)
	{
		if(leaves[k]!=0)	
		{	
			//The isprint function checks to see if the ASCII value is printable. If not, the numerical value for the character is printed.
			if(isprint(k))
				printf("'%c': %d ",k, count[k]);	
			else
				printf("%o: %d",k, count[k]);
			printTree(leaves[k]);
			printf("\n");
		}	
	}
	//This calls the pack funtion which compresses the text file.
	pack(argv[1],argv[2],leaves);
	fclose(fp);
	fclose(fp2);
	return 1;

}

//This function inserts elements into a binary heap.
void insert(struct tree **heap,struct tree *newTree)
{
	int i;
	i=heapCount;
	//Loop while i is not zero and the data of the parent is greater than the data in the new tree.
	while(i>0 && getData(heap[PARENT(i)])>(getData(newTree)))
	{
		heap[i]=heap[PARENT(i)];
		//Decrement i in a binary fashion.
		i=PARENT(i);
	}	
	//Now insert the tree.
	heap[i]=newTree;
	heapCount++;
}

//This function removes the minimum values from the binary heap and returns the pointer to that subtree.
struct tree *deleteMin(struct tree **heap)
{
	int i,child;
	struct tree *x;
	struct tree *min;
	min=heap[0];
	//I decremented here so that way I can still reference heapCount with out going outside the array.
	x=heap[--heapCount];
	i=0;
	//Loop while the the left child is smaller than the end of the array, looking for the smallest child.
	while(LEFTCHILD(i)<heapCount)
	{
		child=LEFTCHILD(i);
		//Set the variable child to the right child if the right is smaller.
		if(RIGHTCHILD(i)< heapCount && getData(heap[LEFTCHILD(i)])>getData(heap[RIGHTCHILD(i)]))
			child=RIGHTCHILD(i);
		if(getData(x)>getData(heap[child]))
		{
			heap[i]=heap[child];
			i=child;
		}
		else
			break;
	}
	//Finish swaping so the next min is the root.
	heap[i]=x;
	return min;
}	

//This function prints the binary pattern for each character.
void printTree(struct tree *leaf)
{
	struct tree *parent;
	struct tree *left;
	struct tree *right;
	//Get the parent of the left about to be printed.
	parent=getParent(leaf);

	//Make sure there the parent exists
	if(parent!=NULL)
	{	
		left=getLeft(parent);
		right=getRight(parent);
		//Recurse post order and then print the bit path.
		printTree(parent);
		if(left==leaf)
			printf("0");
		if(right==leaf)
			printf("1");
	}
}	
