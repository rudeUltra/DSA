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
        //siuuu
        //priority_queue with linked list less go
        
        int n=lists.size();
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        
        for(int i=0;i<n;++i){
            ListNode*temp;
            temp=lists[i];
            
            while(temp){
                pq.push({temp->val,temp});
                temp=temp->next;
            }
        }
        
        //all linked lists are in the pq 
        ListNode* ptr=NULL;
        ListNode*head=NULL;
        
        if(pq.size()==0){
            return NULL;
        }
        ptr=pq.top().second; //we have to assign first siu
        head=pq.top().second;
        pq.pop();
        
        while(!pq.empty()){
            auto it=pq.top();
            ptr->next=it.second;
            pq.pop();
            ptr=ptr->next;
        }
        ptr->next=NULL; //to finish the list
        
        return head;
        
        
    }
};