#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node()
    {
        this->data = 0;
        next = NULL;
        prev = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};

Node *rotate(Node *head, int k)
{
    if (k == 0)
    {
        return head;
    }
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *temp = head;
    vector<int> vt;
    int cnt = 0;
    while (temp != nullptr)
    {
        cnt++;
        temp = temp->next;
    }
    if (cnt == k)
    {
        return head;
    }
    k = k % cnt;
    if (k > cnt)
    {
        return head;
    }
    int count = cnt;
    temp = head;
    int i = cnt - k;
    while (i)
    {
        i--;
        temp = temp->next;
    }
    vector<int> ans;
    while (temp != nullptr)
    {
        ans.push_back(temp->data);
        temp = temp->next;
    }
    temp = head;
    Node *newN = new Node(ans[0]);
    Node *mover = newN;
    int n = ans.size();
    for (int i = 1; i < n; i++)
    {
        Node *newNN = new Node(ans[i]);
        mover->next = newNN;
        mover = newNN;
    }
    mover->next = temp;

    Node *temp2 = newN;
    while (count > 1)
    {
        count--;
        temp2 = temp2->next;
    }
    temp2->next = nullptr;

    return newN;
}

int main()
{
}