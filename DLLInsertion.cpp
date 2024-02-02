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

Node* insertAtHead(Node* head,int val){
    Node* newN=new Node(val,head,nullptr);
    head->prev=newN;
    return newN;
}

Node* insertBeforeTail(Node* head,int val){
    if(head->next==nullptr){
        return insertAtHead(head,val);
    }
    Node* tail=head;
    while(tail->next != NULL){
        tail=tail->next;
    }
    Node* back=tail->prev;
    Node* newN=new Node(val,tail,back);
    back->next=newN;
    newN->next=tail;
    return head;
}

Node* insertAtKPosition(Node* head,int pos,int val){
    if(pos==1){
        return insertAtHead(head,val);
    }
    int cnt=0;
    Node* temp=head;
    while(temp!=nullptr){
        cnt++;
        if(cnt==pos){
            break;
        }
        temp=temp->next;
    }
    Node* back=temp->prev;
    Node* newN=new Node(val,temp,back);
    back->next=newN;
    temp->prev=newN;
    return head;
}

void insertBeforNode(Node* node,int val){
    Node* back=node->prev;
    Node* newN=new Node(val,node,back);
    back->next=newN;
    node->prev=newN;
}

int main(){

}