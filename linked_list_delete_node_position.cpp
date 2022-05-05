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
void printList(Node* node){
    while(node!=NULL){
        cout<<node->data<<" ";
        node=node->next;
    }
    cout<<"\n";
}
void deleteNode(Node** head,int index){
    Node* last=*head;
    Node* pre=NULL;
    int count=0;
    if(index==0){
        if(last==NULL){
            return ;
        }
        *head=last->next;
        delete last;
        return;
    }
    while(count<index-1 && last!=NULL){
        count++;
        pre=last;
        last=last->next;
    }
    if(last==NULL){
        return ;
    }
    pre->next=last->next;
    delete last;
}
int main(){ 
   // Start with the empty list
    Node* head = NULL;
 
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    push(&head, 8);
 
    printList(head);
    deleteNode(&head, 0);
    printList(head);
}