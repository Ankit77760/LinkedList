#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(){
            this->data=0;
            this->next=NULL;
        }
        Node(int data){
            this->data=data;
            this->next=NULL;
        }
        Node(int data,Node*next){
            this->data=data;
            this->next=next;
        }
};

void printLL(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

Node* deleteAtHead(Node* head){
    if(head==NULL) return head;

    Node* temp=head;
    head=head->next;
    temp->next=NULL;
    delete temp;
    return head;
}

Node* deleteAtTail(Node*head){
    if(head==NULL || head->next=NULL){ 
        return NULL;
    }
    Node*temp=head;
    while (temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
    return head;
}

Node* deleteAtPos(Node* head,int k){
    if(head==NULL) {
        return head;
    }
    if(k==1){
        deleteAtHead(head);
    }
    Node*temp=head;
    Node*prev=NULL;
    int cnt=1;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

Node* delPos(Node* head,int val){
    if(head==NULL){
        return head;
    }
    if(head->data==val){
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
        return head;
    }
    Node* temp=head;
    Node* prev=NULL;
    while(temp != NULL){
        if(temp->data==val){
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

int main(){
    
    
}