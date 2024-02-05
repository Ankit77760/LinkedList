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

//tc-O(2N) sc-O(N)
vector<pair<int, int>> findPairs(Node* head, int k)
{
    vector<pair<int, int>> result;
    if (head==nullptr || head->next==nullptr) {
        return result;
    }
    unordered_set<int> seen;
    Node* current = head;
    while (current) {
        int complement = k - current->data;

        if (seen.find(complement) != seen.end()) {
            result.push_back({complement, current->data});
        }

        seen.insert(current->data);
        current = current->next;
    }
    return result;
}

//tc-O(2N) sc-O(1)
vector<pair<int, int>> findPairs(Node* head, int k)
{
    vector<pair<int,int>>ans;
    Node* temp1=head;
    Node* temp2=head;
    while(temp2->next!=nullptr){
        temp2=temp2->next;
    }

    while(temp1->data<temp2->data){
        if((temp1->data+temp2->data)==k){
            ans.push_back({temp1->data,temp2->data});
            temp1=temp1->next;
            temp2=temp2->prev;
        }
        else if((temp1->data+temp2->data)>k){
            temp2=temp2->prev;
        } else {
            temp1 = temp1->next;
        }
    }
    return ans;
}

int main(){

}