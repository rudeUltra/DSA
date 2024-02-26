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
    
    ListNode* merge(ListNode*left,ListNode*right){
        ListNode*ans=new ListNode(0); //DummY noice
        ListNode*head=ans;
        
        while(left && right){
            if(left->val<right->val){
                head->next=left;
                left=left->next;
                head=head->next;
            }
            else{
                head->next=right;
                right=right->next;
                head=head->next;
            }
        }
        while(left){
            head->next=left;
            left=left->next;
            head=head->next;
        }
        while(right){
            head->next=right;
            right=right->next;
            head=head->next;
        }
        
        return ans->next;
        
    }
    
    
    
    
    ListNode* sortList(ListNode* head) {
        //Bruh this question who tf asks this BC xD but ok.
        if(head==NULL || head->next==NULL){
            return head;
        }
        
        ListNode*slow=head;
        ListNode*fast=head;
        ListNode *prev=NULL;
        
        while(fast && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        
        //Now divide SIu
        prev->next=NULL;
        
        //it will return a new list also na SIU
        ListNode*newLeft=sortList(head);
        ListNode*newRight=sortList(slow);
        
        //nOW merge NOice
        ListNode*ans=merge(newLeft,newRight);
        
        return ans;
    }
};