#include<bits/stdc++.h>
using namespace std;

class Node{
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
};

//tc-O(2n) sc-O(1)
Node* sortList(Node *head){
    int count0=0;
    int count1=0;
    int count2=0;
    Node* temp=head;
    while(temp!=nullptr){
        if(temp->data==0){
            count0++;
        }
        if(temp->data==1){
            count1++;
        }
        if(temp->data==2){
            count2++;
        }
        temp=temp->next;
    }
    
    Node*newN=new Node(0,nullptr);
    Node*headH=newN;
    for(int i=0;i<count0-1;i++){
        Node*newNN=new Node(0);
        newN->next=newNN;
        newN=newNN;
    }
    for(int i=0;i<count1;i++){
        Node*newNN=new Node(1);
        newN->next=newNN;
        newN=newNN;
    }
    for(int i=0;i<count2;i++){
        Node*newNN=new Node(2);
        newN->next=newNN;
        newN=newNN;
    }
    return headH;
}

//tc-O(N) sc-O(1)
Node* sortList(Node *head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    Node* temp=head;
    Node* zeroH=new Node(-1);
    Node* oneH=new Node(-1);
    Node* twoH=new Node(-1);
    Node* zero=zeroH;
    Node* one=oneH;
    Node* two=twoH;
    while(temp){
        if(temp->data==0){
            zero->next=temp;
            zero=temp;
        }
        else if(temp->data==1){
            one->next=temp;
            one=temp;
        }
        else if(temp->data==2){
            two->next=temp;
            two=temp;
        }
        temp=temp->next;
    }
    zero->next=(oneH->next) ? oneH->next : twoH->next;
    one->next=twoH->next;
    two->next=nullptr;
    Node* newH=zeroH->next;
    delete zeroH;
    delete oneH;
    delete twoH;
    return newH;
}



int main(){
    
}