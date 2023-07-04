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
    void reorderList(ListNode* head) {
        ListNode *fast=head;
        ListNode *slow=head;
        
        while(fast && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *mid;
        stack<ListNode*>st;
        if(fast!=NULL){
            mid=slow->next;
        }
        else{
            mid=slow;
        }
        while(mid){
            st.push(mid);
            mid=mid->next;
        }
        ListNode*ans=head;
        
        while(st.size()){
            ListNode *temp=ans->next;
            ans->next=st.top();
            st.top()->next=temp;
            st.pop();
            ans=temp;
        }
        slow->next=NULL;
    
    }
};