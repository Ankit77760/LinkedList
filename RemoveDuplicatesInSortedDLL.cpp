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
};

Node * removeDuplicates(Node *head)
{
    Node* temp=head;
    while(temp!=nullptr && temp->next!=nullptr){
        Node* newN=temp->next;
        while(newN!=nullptr && newN->data==temp->data){
            newN=newN->next;
        }
        temp->next=newN;
        if(newN){
            newN->prev=temp;  
        }
         temp=temp->next;
    }   
    return head;
}

int main(){

}