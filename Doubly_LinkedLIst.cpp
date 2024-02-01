#include<bits/stdc++.h>
using namespace std;

class Node
{
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


Node* constructDLL(vector<int>& arr) {
    Node*head=new Node(arr[0],nullptr,nullptr);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        temp->prev=mover;
        mover=temp;
    }
    return head;
}



void print(Node* head){
    while(head!=NULL){
        cout<<head->data>>" ";
        head=head->next;
    }
}

int main(){

    vector<int>arr={12,5,6,8};

    return 0;
}