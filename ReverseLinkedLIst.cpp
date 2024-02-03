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

//tc-O(2n) sc-O(N)
Node* reverseLinkedList(Node *head)
{
    Node* temp=head;
    stack<int>st;
    while(temp!=NULL){
        st.push(temp->data);
        temp=temp->next;
    }
    Node* temp2=head;
    while(temp2!=NULL){
        temp2->data=st.top();
        st.pop();
        temp2=temp2->next;
    }
    return head;
}

//tc-O(N) sc-O(1)
Node* reverseLinkedList(Node *head){
    Node* prev=nullptr;
    Node* temp=head;
    Node* front=head;
    while(temp!=nullptr){
        front=temp->next;
        temp->next=prev;
        prev=temp;
        temp=front;
    }
    return prev;
}


Node* reverseLinkedList(Node *head)
{
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    Node*newHead=reverseLinkedList(head->next);
    Node*front=head->next;
    front->next=head;
    head->next=nullptr;
    return newHead;
}


int main(){

}