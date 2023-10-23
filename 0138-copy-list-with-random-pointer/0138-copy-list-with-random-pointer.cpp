/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        //Teenage kicks the boy with the world at his feet Siuu
        unordered_map<Node*,Node*>mp;
        Node*curr=head;
        
        while(curr){
            mp[curr]=new Node(curr->val);
            curr=curr->next;
        }
        Node *ans=new Node(-1);
        
        Node*temp=ans;
        
        while(head){
            temp->next=mp[head];
            mp[head]->next=mp[head->next];
            mp[head]->random=mp[head->random];
            head=head->next;
            temp=temp->next;
        }
        return ans->next;
        
        
    }
};