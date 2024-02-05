#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node *next;
        Node()
        {
            this->data = 0;
            next = NULL;
        }
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
        Node(int data, Node* next)
        {
            this->data = data;
            this->next = next;
        }
}

Node* reverseL(Node* head){
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=nullptr){
        Node* front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}

Node* getKNode(Node* temp,int k){
    k--;
    while(temp!=nullptr && k>0){
        k--;
        temp=temp->next;
    }
    return temp;
}

Node* kReverse(Node* head, int k) {
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=nullptr){
        Node* kNode=getKNode(temp, k);
        if(kNode==nullptr){
            if(prev){
                prev->next=temp;
            }
            break;
        }
        Node* nextNode=kNode->next;
        kNode->next=nullptr;
        reverseL(temp);
        if(temp==head){
            head=kNode;
        }
        else{
            prev->next=kNode;
        }
        prev=temp;
        temp=nextNode;
    }
    return head;
}

int main(){

}