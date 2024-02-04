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
        this->next = NULL;
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

//tc-O(n) sc-o(n) recursive approach
int helper(Node *temp)
{
    if (temp == nullptr)
    {
        return 1;
    }

    int carry = helper(temp->next);
    temp->data = temp->data + carry;
    if (temp->data < 10)
    {
        return 0;
    }
    temp->data = 0;
    return 1;
}

Node *addOne(Node *head)
{
    int carry = helper(head);
    if (carry == 1)
    {
        Node *newN = new Node(1);
        newN->next = head;
        return newN;
    }
    return head;
}
