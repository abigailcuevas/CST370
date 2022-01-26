/*
*Title: hw8_2.cpp
*Abstract: Program provides a few functions(append, isBST, height, inOrder, postOrder, preOrder, etc.) for a binary tree
*Author: Abigail Cuevas
*ID: 9999
*Date: 10/25/2021
*references:
*https://www.geeksforgeeks.org/insertion-in-a-binary-tree-in-level-order/
*https://www.geeksforgeeks.org/level-order-tree-traversal/
*https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
*https://replit.com/@YBYUN/InorderTraversal
*/

#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

struct Node
{
	// Data part for a node.
    int data;
    Node* left;
    Node* right;
    // Constructor for a new node.
    Node(int d)
    {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

//function to add inputted nodes to tree
//add left to right, check sides to see where to input node
//use a queue
void append(Node* first, Node* other)
{
    //create queue
    queue<Node*> Q;
    //add the root to the queue
    Q.push(first);
    //while queue is not empty
    while (!Q.empty()){
        
        Node* curr= Q.front();
        Q.pop();
        //check whether left side is null
        //if yes insert the node and return
        if(curr->left == nullptr){
            curr->left = other;
            return;
        }else{//if not push it to the queue
            Q.push(curr->left);
        //check if the right side is null 
        //if yes insert node and return
        }if(curr->right == nullptr){
            curr->right = other;
            return;
        //if not push to the queue
        }else{
            Q.push(curr->right); 
        }
    }
}
//function returns the height of tree
//use recursion
int height(Node* root){
    //check to make sure not null
    if(root != nullptr){
        //add one every recursion
        return (height(root->left)) + 1;
    }else{
        //return
        return -1;
    }
}

//============traversals section =============
//function prints left, root, right
void inOrder(Node* root){
    if(root != nullptr){
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}
//function prints root, left, right
void preOrder(Node* root){
    if(root != nullptr){
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
//function prints left, right, root
void postOrder(Node* root){
    if(root != nullptr){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}
//function print first number in an inorder traversal function
void firstNode(Node* root)
{
    if(root != nullptr){
        if(!root->left){
            cout << root->data;
        }else{
            firstNode(root->left);
        }
    }
}
// ============= end =========================
//function returns whether tree is a BST tree
//used reference
bool isBST(Node* root){
    static Node *prev = NULL;

    if(root){
        if(!isBST(root->left))
            return false;
        if(prev != NULL && root->data <= prev->data)
            return false;

        prev = root;

        return isBST(root->right);
    }
    return true;
}
//funtion uses bfs
//check left and right side
void levelOrders(Node* root){
    if(root != nullptr){
        //variable declared
        queue<Node*> q;
        //push to queue
        q.push(root);
        //while queue is not empty do while loop
        while (!q.empty()){
            //get the front of queue
            Node* n3 = q.front();
            //print num
            cout << n3->data << " ";
            q.pop();
            //check left if they're null
            //if not push to queue
            if(n3->left != nullptr){
                q.push(n3->left);
            }
            //check right if they're null
            //if not push to queue
            if(n3->right != nullptr){
                q.push(n3->right);
            }
        }
    }
}


int main()
{
    //variables declared
    int rootVal = 0;
    int commands = 0;
    int number  = 0;
    string inputComm = "";
    
    //user input
    cin>> rootVal;
    cin>> commands;

    //create the root
    Node* n1 = new Node(rootVal);
    
    //for loop to insert commands
    for(int i = 0; i < commands; i++){
        //user input
        cin>> inputComm;
        //if the command is append 
        //ask the user for number to append 
        if(inputComm == "append"){//done
            cin>> number;
            Node* n2 = new Node(number);
            append(n1, n2);
        }else{
            //check the user input if they equal the functions below
            
            //to check if its a bst
            if(inputComm == "isBST"){//done
                if(isBST(n1))
                    cout << "true";
                else
                    cout << "false";
            //to print preOrder traversal        
            }if(inputComm == "preOrder"){//done
                preOrder(n1);
            //to print the height of the tree
            }if(inputComm == "height"){//done
                int tHeight = height(n1);
                cout << tHeight;
            //to print the levelOrder
            }if(inputComm == "levelOrder"){//done
                levelOrders(n1);
            //to print the first node
            }if(inputComm == "findFirstNode"){//done
                firstNode(n1);
            //to print the postOrder
            }if(inputComm == "postOrder"){//done
                postOrder(n1);
            }
            //to print the inOrder
            if(inputComm == "inOrder"){//done
                inOrder(n1);
            }
        cout<<endl;
        }
    }
    return 0;//exit
}