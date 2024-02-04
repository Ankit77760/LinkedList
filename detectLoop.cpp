#include <bits/stdc++.h>
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
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

//tc-O(2*logn)   sc-o(n)
bool detectCycle(Node *head)
{
    Node *temp = head;
    unordered_map<Node *, int> mpp;
    while (temp != nullptr)
    {
        if (mpp.find(temp) != mpp.end())
        {
            return true;
        }
        mpp[temp] = 1;
        temp = temp->next;
    }
    return false;
}

//tc-O(N) sc-O(1)
bool detectCycle(Node *head)
{
    if(head==nullptr||head->next==nullptr){
        return false;
    }
    Node* fast=head;
    Node* slow=head;

    Node* temp=head;
    while(temp != nullptr && fast!=nullptr && fast->next!=nullptr){
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow){
            return true;
        }
        temp=temp->next;
    }
    return false;
}

int main()
{
}