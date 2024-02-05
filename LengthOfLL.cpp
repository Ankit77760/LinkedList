#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(){
            this->data=0;
            this->next=NULL;
        }
        Node(int data){
            this->data=data;
            this->next=NULL;
        }
        Node(int data,Node*next){
            this->data=data;
            this->next=next;
        }
};

//tc-O(N*2*logn) sc-O(N)
int lengthOfLoop(Node *head) {
    Node* temp=head;
    unordered_map<Node*,int>mpp;
    int i=1;
    while(temp!=nullptr){
        if(mpp.find(temp)!=mpp.end()){
            return i-mpp[temp];
        }
        mpp[temp]=i;
        i++;
        temp=temp->next;
    }
    return 0;
}



int main(){

}