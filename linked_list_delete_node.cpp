#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;    
};

void push(Node** head,int value){
    Node* newnode=new Node();
    newnode->data=value;
    
    newnode->next=*head;
    *head=newnode;
}
void printnode(Node* node){
    while(node!=NULL){
        cout<<node->data<<" ";
        node=node->next;
    }
    cout<<"\n";
}
void deletenode(Node** head,int value){
    Node* last=*head;
    Node* pre=NULL;
    if(last!=NULL && last->data==value){
        last=last->next;
        delete last;
        return ;
    }
    else{
        while(last!=NULL && last->data!=value){
            pre=last;
            last=last->next;
        }
        if(last==NULL){
            return;
        }
        pre->next=last->next;
        delete last;
    }
}
int main(){ 
   Node* head=NULL;
   push(&head,7);
   push(&head,1);
   push(&head,3);
   push(&head,2);
   printnode(head);
   deletenode(&head,1);
   printnode(head);
}