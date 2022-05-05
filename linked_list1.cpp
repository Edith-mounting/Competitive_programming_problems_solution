#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;    
};

void append(Node** head,int value){
    //creating new node which we have to append 
    Node* new_node=new Node();
    new_node->data=value;
    new_node->next=NULL;

    Node *last=*head;
    if(*head ==NULL){
        *head=new_node;
        return;
    }

    while(last->next!=NULL){
        last=last->next;
    }
    last->next=new_node;
    return;
}
void printnode(Node *node){
    while(node!= NULL){
        cout<<node->data<<" ";
        node=node->next;
    }
}
void push(Node** head,int value){
    Node* new_node=new Node();
    new_node->data= value;
    new_node->next=*head;

    *head = new_node;
}
int main(){ 
   Node* head=NULL;
   append(&head,6);
   push(&head,7);
   printnode(head);
}