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

//type 1- where even indexed nodes are segerated and odd indexed are segerated tc-O(2N) sc-O(N)
Node* segregateEvenOdd(Node* head)
{
    Node*temp=head;
    vector<int>vt;
    while(temp != NULL && temp->next!=NULL) {
        vt.push_back(temp->data);
        temp=temp->next->next;
    }
    if (temp) {
        vt.push_back(temp->data);
    }
    Node* temp2=head->next;
    while(temp2 !=NULL && temp2->next!=NULL){
        vt.push_back(temp2->data);        
        temp2=temp2->next->next;
    }
    if (temp2) {
        vt.push_back(temp2->data);
    }
    Node* temp3=head;
    int index=0;
    while(temp3!=NULL){
        temp3->data=vt[index];
        index++;
        temp3=temp3->next;
    }
    return head;
}

//tc-O(n/2)*2=n   sc-o(1)
Node* evenodD(Node* head){
    if(head==nullptr || head->next==nullptr){
        return head;
    }
    Node* odd=head;
    Node* even=head->next;
    Node* evenHead=head->next;
    while(even!=NULL && even->next !=nullptr){
        odd->next=odd->next->next;
        even->next=even->next->next;
        odd=odd->next;
        even=even->next;
    }
    odd->next=evenHead;
    return head;
}

//type 2 here even are placed at start and odd numbers are placed after that tc-O(2n+odd element size) sc-O(N)
Node* segregateEvenOdd(Node* head)
{
    Node* temp=head;
    vector<int>vt;
    vector<int>vtt;
    while(temp != NULL){
      int da=temp->data;
      if(da%2==0){
        vt.push_back(da);
      }
      else{
        vtt.push_back(da);
      }
      temp=temp->next;
    }
    for (int i = 0; i < vtt.size(); i++) {
      vt.push_back(vtt[i]);
    }
    Node* temp1=head;
    
    int index=0;
    while(temp1!=NULL){
      temp1->data=vt[index];
      index++;
      temp1=temp1->next;
    }
    return head;
}

int main(){

}