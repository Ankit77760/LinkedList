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

//tc-O(2N) sc-O(N)
Node* removeKthNode(Node* head, int K)
{
    if(head==nullptr || head->next==nullptr){
        return nullptr;
    }
    Node*temp=head;
    vector<int>vt;
    while(temp!=NULL)
    {
        vt.push_back(temp->data);
        temp=temp->next;
    }
    int delE=vt.size()-K;
    vt.erase(vt.begin()+delE);

    Node*temp1=head;
    int index=0;
    int vts=vt.size();
    while(vts){
        temp1->data=vt[index];
        index++;
        vts--;
        if(vts==0){
            temp1->next=nullptr;
        } else {
            temp1 = temp1->next;
        }
    }
    return head;
}

//tc-O(n)+len-k (2n)    sc-o(1)
Node* removeKthNode(Node* head, int K)
{
    if(head==nullptr || head->next==nullptr){
        return nullptr;
    }
    Node*temp=head;
    int cnt=0;
    while(temp!=nullptr){
        cnt++;
        temp=temp->next;
    }
    int res=cnt-K;
    if(res==0){
        head=head->next;
    }
    Node* temp2=head;
    while(temp2!=NULL){
        res--;
        if(res==0){
            temp2->next=temp2->next->next;
            break;
        }
        temp2=temp2->next;
    }
    return head;
}

//tc-o(N) sc-O(1)
Node* removeKthNode(Node* head, int K)
{
    if(head==nullptr || head->next==nullptr){
        return nullptr;
    }
    Node*fast=head;
    Node*slow=head;
    for(int i=0;i<K;i++){
        fast=fast->next;
    }
    if(fast==NULL){
        return head->next;
    }
    while(fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    Node*delNode=slow->next;
    slow->next=slow->next->next;
    delete delNode;
    return head;
}


int main(){

}