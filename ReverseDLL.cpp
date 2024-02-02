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

void printLL(Node*head){
    while(head!=nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
}


//tc-O(2N) sc-O(N)
Node* reverseDLL(Node* head)
{   
    stack<int>st;
    Node* temp=head;
    while(temp!=NULL){
        st.push(temp->data);
        temp=temp->next;
    }
    Node* x=head;
    while(x!=NULL){
        x->data=st.top();
        st.pop();
        x=x->next;
    }
    return head;
}

//tc-O(N) sc-O(1)
Node* reverseDLLL(Node* head){   
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node*prev=NULL;
    Node*curr=head;
    while(curr!=NULL){
        prev=curr->prev;
        curr->prev=curr->next;
        curr->next=prev;
        curr=curr->prev; //incrementing current
    }
    return prev->prev;
    return head;
}

int main(){

}