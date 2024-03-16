/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //cant have k pointers can I xD
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq; //min-heap
        int n=lists.size();
        
        //keep adding these motherfuckers xD
        for(int i=0;i<n;++i){
            ListNode*temp=lists[i];
            while(temp!=NULL){
                pq.push({temp->val,temp});
                temp=temp->next;
            }
        }
        
        //make the list siu
        ListNode *l1=new ListNode();
        ListNode*curr=l1;
        
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            curr->next=it.second;
            curr=curr->next;
        }
        
        curr->next=NULL;
        return l1->next;
    }
};