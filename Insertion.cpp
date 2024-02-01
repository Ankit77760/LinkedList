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

Node* insertAtHead(Node*head,int val){
    Node*temp=new Node(val);
    temp->next=head;
    temp=head;
    return head;
}

Node* insertAtTail(Node* head,int val){
    if(head==NULL){
        return new Node(val,head);
    }
    Node*temp=new Node(val);
    Node* prev=head;
    while(prev->next!=NULL){
        prev=prev->next;
    }
    prev->next=temp;
    temp->next=NULL;
    return head;
}

Node* insertAtPos(Node* head,int pos,int val){
    if(head==NULL){
        if(pos==1){
            return new Node(val);
        }
        else{
            return NULL;
        }
    }
    if(pos==1){
        insertAtHead(head,val);
    }
    Node* newNode=new Node(val);
    Node*temp=head;
    Node*prev=head->next;
    int cnt=0;
    while(temp!=NULL){
        cnt++;
        if(cnt==pos){
            newNode->next=prev;
            temp->next=newNode;
            return head;
        }
        temp=temp->next;
        prev=prev->next;
    }
    return head;
}

Node* insertByval(Node* head,int el,int val){
    if(head==NULL){
        return NULL;
    }
    if(head->data==val){
        return new Node(el,head);
    }
    Node* temp=head;
    int cnt=0;
    while(temp->next != NULL){
        if(temp->next->data==val){
            Node* newN=new Node(el,temp->next);
            temp->next=newN;
            break;
        }
        temp=temp->next;
    }
    return head;
}



int main(){

}