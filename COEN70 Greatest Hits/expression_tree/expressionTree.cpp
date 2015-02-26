/*By Max Werner and Parker Newton
 * 
 *INTERFACE and IMPLEMENTATION: expressiontree.cpp
 *
 */ 
#include <iostream>
#include <cstdlib>
#include <assert.h>
#include <cstdio>     
#include <cstring> 
using namespace std;
 
class eTree
{
    private:
		
		//tree node class declaration
		class tNode
		{       
			public:
				char data;
				tNode *leftChild, *rightChild;
				//tree node ctor
				tNode(char data)
				{
					this->data = data;
					this->leftChild = NULL;
					this->rightChild = NULL;
				}
		}; 
		
		//stack node class declaration
		class sNode
		{    
			public:
				tNode *tree;
				sNode *next;
				//stack node ctor 
				sNode(tNode *tree)
				{
					this->tree = tree;
					next = NULL;
				}
		};

        sNode *root;
    public:
        //ctor 
        eTree()
        {
            root = NULL;
        }
 
		//return the root
        tNode *getRoot()
        {
            return root->tree;
        }
 
        //clear the etree (this is called at the end of main rather than implementing a dtor, cctor, and an assignment operator
        void clear()
        {
            clearPostOrder(root->tree);
            delete root;
            
        }
    
        //traverse the tree post oder deallocating as you go
        void clearPostOrder(tNode *temp)
        {
            if(temp == NULL)
                return;
            clearPostOrder(temp->rightChild);
            clearPostOrder(temp->leftChild);
            delete temp;
        }
    
		//pop a new node from the tree
        tNode *pop()
        {
			assert(root != NULL);
            tNode *p = root->tree;
            root = root->next;
            return p;
        }
 
        //push a new node on to the tree
        void push(tNode *p)
        {
            if (root == NULL)
                root = new sNode(p);
            else
            {
                sNode *temp = new sNode(p);
                temp->next = root;
                root = temp;
            }
        }
 
		//check to see if the char is a digit
        bool checkDigit(char c)
        {
            return c >= '0' && c <= '9';
        }
 
		//convert the char to a digit
        int convToDigit(char c)
        {
            return c - '0';
        }
 
        //check to see if the char is an operator
        bool checkOp(char c)
        {
            return c == '+' || c == '-' || c == '*' || c == '/';
        }
 
		//the recursive function to evaluate the expression tree
        float evaluate(tNode *p)
        {
            if (p->leftChild == NULL && p->rightChild == NULL)
                return convToDigit(p->data);
            else
            {
                float result = 0.0;
                float left = evaluate(p->leftChild);
                float right = evaluate(p->rightChild);
                char op = p->data;
                switch (op)
                {
                    case '+':
                        result = left + right;
                        break;
                    case '-':
                        result = right - left;
                        break;
                    case '*':
                        result = left * right;
                        break;
                    case '/':
                        result = right / left;
                        break;
                    default:
                        result = left + right;
                        break;
                }
                return result;
            }
        }
 
		//a simple version of the real eval function
        float evaluate()
        {
            return evaluate(getRoot());
        }
 
        //insert a digit/operator from a string
        void insert(char x)
        {
            if (checkDigit(x))
            {
                tNode *temp = new tNode(x);
                push(temp);
            }
            else if (checkOp(x))
            {
                tNode *temp = new tNode(x);
                temp->leftChild = pop();
                temp->rightChild = pop();
                push(temp);
            }
            else
            {
                cout<<"Incorrect character passed"<<endl;
                return;
            }
        }
 
        //this creates the tree from the provided string
        void buildTree(string x)
        {
            for (int i = 0; i < x.length(); i++)
                insert(x[i]);
        }
    
        //call the pre order function
        void pre()
        {
            preOrder(getRoot());
        }
    
        //traverse the tree in pre order
        void preOrder(tNode *temp)
        {
            if(temp == NULL)
                return;
            cout << temp->data;
            preOrder(temp->rightChild);
            preOrder(temp->leftChild);
        }

        //call the post order function
        void post()
        {
            postOrder(getRoot());
        }
    
        //traverse the tree in post order
        void postOrder(tNode *temp)
        {
            if(temp == NULL)
                return;
            postOrder(temp->rightChild);
            postOrder(temp->leftChild);
            cout << temp->data;
        }
    
        //call the in order function
        void in()
        {
            inOrder(getRoot());
        }
    
        //traverse the tree in order
        void inOrder(tNode *temp)
        {
            if(temp == NULL)
                return;
            inOrder(temp->rightChild);
            cout << temp->data;
            inOrder(temp->leftChild);
        }
};
