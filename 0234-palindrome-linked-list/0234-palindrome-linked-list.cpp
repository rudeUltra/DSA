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
    
    ListNode* reverse(ListNode*head){
        ListNode*prev=NULL;
        while(head!=NULL){
            ListNode*temp=head->next;
            head->next=prev;
            prev=head;
            head=temp;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        ListNode*slow=head;
        ListNode*fast=head;
        
        if(head==NULL || head->next==NULL){
            return true;
        }
        ListNode*prev=NULL;
        while(fast && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
       
        prev->next=NULL;
        
        ListNode*second=reverse(slow);
        
        while(head!=NULL){
            
            if(second==NULL){
                return false; //uneven hm.
            }
            
            if(head->val!=second->val){
                return false;
            }
            head=head->next;
            second=second->next;
        }
        return true;
        
    }
};