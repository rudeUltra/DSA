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
        stack<ListNode*>st;
        ListNode*slow=head;
        ListNode*fast=head;
        
        while(fast && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        //sPLiit
        ListNode*curr=slow->next;
        slow->next=NULL; //gOTEmmm.
        
        while(curr!=NULL){
            st.push(curr);
            curr=curr->next;
        }
        
        //now time for the Memes
        curr=head;
        
        while(curr!=NULL && st.size()!=0){
            ListNode*temp=curr->next;
            ListNode*reversed=st.top();
            st.pop();
            reversed->next=temp;
            curr->next=reversed;
            curr=temp;
        }
        
        
        
    }
};