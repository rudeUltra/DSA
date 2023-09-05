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
        //Store everyones duplicate copies hm
        unordered_map<Node*,Node*>mp;
        
        Node*curr=head;
        while(curr){
            Node*temp=new Node(curr->val);
            mp[curr]=temp;
            curr=curr->next;
        }
        //Make the new List
        Node *list=new Node(-1);
        
        curr=head;
        Node*temp=list;
        while(curr){
            Node *curr2=mp[curr];
            curr2->random=mp[curr->random];
            curr2->next=mp[curr->next];
            temp->next=curr2;
            temp=curr2;
            curr=curr->next;
        }
        
        return list->next;
    }
};