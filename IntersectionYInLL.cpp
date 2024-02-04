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

// tc-O(n^2) sc-O(1)
Node *findIntersection(Node *firstHead, Node *secondHead)
{
    while (secondHead != nullptr)
    {
        Node *temp = firstHead;
        while (temp != nullptr)
        {
            if (temp == secondHead)
            {
                return secondHead;
            }
            temp = temp->next;
        }
        secondHead = secondHead->next;
    }
    return nullptr;
}

// tc-O(n1*logn)+(n2*logn)   sc-O(N)
Node *findIntersection(Node *firstHead, Node *secondHead)
{
    unordered_set<Node *> st;
    while (firstHead != nullptr)
    {
        st.insert(firstHead);
        firstHead = firstHead->next;
    }

    while (secondHead != nullptr)
    {
        if (st.find(secondHead) != st.end())
        {
            return secondHead;
        }
        secondHead = secondHead->next;
    }
    return nullptr;
}

// by bringing them at equivalent tc-O(n1+n2)+(n1-n2)+O(n1) sc-o(1)
Node *findIntersection(Node *firstHead, Node *secondHead)
{
    Node *temp1 = firstHead;
    Node *temp2 = secondHead;

    int cnt1 = 0;
    int cnt2 = 0;

    while (temp1 != nullptr)
    {
        cnt1++;
        temp1 = temp1->next;
    }
    while (temp2 != nullptr)
    {
        cnt2++;
        temp2 = temp2->next;
    }

    temp1 = firstHead;
    temp2 = secondHead;
    if (cnt1 > cnt2)
    {
        for (int i = 0; i < (cnt1 - cnt2); i++)
        {
            temp1 = temp1->next;
        }
    }
    else if (cnt2 > cnt1)
    {
        for (int i = 0; i < (cnt2 - cnt1); i++)
        {
            temp2 = temp2->next;
        }
    }

    while (temp1 != nullptr && temp2 != nullptr)
    {
        if (temp1->next == temp2->next)
        {
            return temp1->next;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return nullptr;
}

// tc-O(n1+n2) sc-O(1)
Node *findIntersection(Node *firstHead, Node *secondHead)
{
    Node *temp1 = firstHead;
    Node *temp2 = secondHead;

    while (temp1 != nullptr && temp2 != nullptr)
    {
        if (temp1->next == nullptr)
        {
            temp1 = secondHead;
        }
        else if (temp2->next == nullptr)
        {
            temp2 = firstHead;
        }
        if (temp1->next == temp2->next)
        {
            return temp1->next;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    return nullptr;
}

int main()
{
}