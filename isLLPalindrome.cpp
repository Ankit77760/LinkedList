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

//tc-O(3n) sc-O(2n)
bool isPalindrome(Node *head){
    Node* temp=head;
    vector<int>vt;
    while(temp!=NULL){
        vt.push_back(temp->data);
        temp=temp->next;
    }
    vector<int>vtt;
    for(int i=0;i<vt.size();i++){
        vtt.push_back(vt[i]);
    }
    reverse(vtt.begin(),vtt.end());
    int n=vtt.size();
    int flag=0;
    for(int i=0;i<n;i++){
        if(vt[i]!=vtt[i]){
            return false;
        }
    }
    return 1;
}

//using stack tc-O(2n) sc-O(n)
bool isPalindrome(Node *head){
    Node* temp=head;
    stack<int>st;
    while(temp!=nullptr){
        st.push(temp->data);
        temp=temp->next;
    }
    Node* temp2=head;
    while(temp2!=nullptr){
        if(temp2->data!=st.top()){
            return false;
        } else {
            st.pop();
            temp2 = temp2->next;
        }
    }
    return true;
}

int main(){

}