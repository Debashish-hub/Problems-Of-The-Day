// Rearrange a linked list 

// Given a singly linked list, the task is to rearrange it in a way that all odd position nodes are together and all 
// even positions node are together.
// Assume the first element to be at position 1 followed by second element at position 2 and so on.

// { Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};



 // } Driver Code Ends
/* Node structure

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution
{
    public:
    void rearrangeEvenOdd(Node *head)
    {
       // Your Code here
       Node *es = NULL, *ee = NULL, *os = NULL, *oe = NULL;
       Node *curr = head;
       int i = 1;
       while(curr != NULL){
           if(i%2 == 0){
               if(es == NULL){
                   es = curr;
                   ee = curr;
               }else{
                   ee->next = curr;
                    ee = curr;
               }
               
           }else{
               if(os == NULL){
                   os = curr;
                   oe = curr;
               }else{
                   oe->next = curr;
                    oe = curr;
               }
               
           }
           curr = curr->next;
           i++;
       }
       if(os == NULL){
           ee->next = NULL;
           head = es;
           return;
       }
       else if(es == NULL){
           oe->next = NULL;
           head = os;
           return;
       }else{
           head = os;
           oe->next = es;
           ee->next = NULL;
       }
       
    }
};


// { Driver Code Starts.

/* Driver program to test above function*/
int main()
{
    int T,i,n,l;

    cin>>T;

    while(T--)
    {
        struct Node *head = NULL;
        struct Node *temp = head;
        cin>>n;
        for(i=1; i<=n; i++)
        {
            cin>>l;

            if (head == NULL)
            {   
                head = temp = new Node(l); 
                
            }
            else
            {  temp->next = new Node(l);
               temp = temp->next;
            }
        }
        Solution ob;
        ob.rearrangeEvenOdd(head);
        while(head != NULL)
        {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
    return 0;
}
  // } Driver Code Ends