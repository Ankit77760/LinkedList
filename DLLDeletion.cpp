#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node *next,*prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev= NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
        this->prev= NULL;
    }
    Node(int data, Node* next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev= prev;
    }
};

Node* delteAtHead(Node* head){
    if(head==NULL || head->next==NULL){
        return nullptr;
    }
    Node* temp=head;
    head=head->next;
    head->prev=nullptr;
    temp->next=nullptr;
    delete temp;
    return head;
}


Node* deleteLastNode(Node *head) {
    Node* temp=head;
    if(head==nullptr || temp->next==nullptr){
        return nullptr;
    }
    while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    temp->next=nullptr;
    return head;
}

Node* deleteAtPos(Node* head,int pos){
    if(head==nullptr){
        return nullptr;
    }
    int cnt=0;
    Node*temp=head;
    while(temp!=nullptr){
        cnt++;
        if(cnt==pos){
            break;
        }
        temp=temp->next;
    }
    Node* backwardN = temp->prev;
    Node* forwardN = temp->next;
    if(backwardN==NULL && forwardN==NULL){
        delete temp;
        return nullptr;
    }
    else if(backwardN==nullptr){
        return delteAtHead(head);
    }
    else if(forwardN==NULL){
        return deleteLastNode(head);
    }
    else{
        backwardN->next=forwardN;
        forwardN->prev=backwardN;
        temp->next=nullptr;
        temp->prev=nullptr;
        delete temp;
    }
    return head;
}

Node* deleteNode(Node* temp){
    Node* previous=temp->prev;
    Node* front=temp->next;
    if(front==NULL){
        previous->next=nullptr;
        temp->prev=nullptr;
        delete temp;
        return; 
    }
    previous->next=front;
    front->prev=previous;
    temp->next=temp->prev=nullptr;
    delete temp;
}



int main(){

}