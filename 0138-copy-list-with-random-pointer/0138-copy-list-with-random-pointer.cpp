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
        //basically just copy copy..ok
        unordered_map<Node*,Node*>mp;
        Node*curr=head;
        
        while(curr){
            Node*temp=new Node(curr->val);
            mp[curr]=temp; //my son xD
            curr=curr->next;
        }
        
        //basically in this loop give my son the connections xDD
        curr=head;
        while(curr){
            mp[curr]->next=mp[curr->next];
            mp[curr]->random=mp[curr->random];
            curr=curr->next;
            
        }
        return mp[head];
        
    }
};