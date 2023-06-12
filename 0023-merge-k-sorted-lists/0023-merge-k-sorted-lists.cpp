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
        
        if(lists.empty()) return nullptr;
        
        priority_queue<pair<int,ListNode*>> pq; //by default heap is sorted by first element value 
        int n=lists.size();
        
        for(int i=0;i<n;i++)
        {
            while(lists[i]!=nullptr)
            {
                pq.push({-lists[i]->val,lists[i]});
                lists[i]=lists[i]->next;
            }
        }
        
        
        ListNode* head=nullptr;
        ListNode* k=nullptr;
        
        if(pq.empty()) return head;
        
        head=pq.top().second;
        k=pq.top().second;
        pq.pop();
        
     
        while(!pq.empty())
        {
            k->next=pq.top().second;
            k=pq.top().second;
            pq.pop();
            
        }
        k->next=NULL;
        
        return head==NULL?nullptr:head;
        
    }
};