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
    
    ListNode*merge(ListNode*head,ListNode*slow){
        ListNode*temp=new ListNode();
        ListNode *ptr1=temp;
        
        while(head!=NULL && slow!=NULL){
            if(head->val<slow->val){
                //basic merge algorithm
                ptr1->next=head;
                ptr1=ptr1->next;
                head=head->next;
            }
            else{
                ptr1->next=slow;
                ptr1=ptr1->next;
                slow=slow->next;
            }
        }
        
        //for remaining elements if any
        while(head){
            ptr1->next=head;
            ptr1=ptr1->next;
            head=head->next;
        }
        while(slow){
            ptr1->next=slow;
                ptr1=ptr1->next;
                slow=slow->next;
        }
        return temp->next;
    }
    
    
    ListNode* sortList(ListNode* head) {
        
        if(head==NULL){
            return NULL;
        }
        if(head->next==NULL){
            return head;
        }
        //basically merge sort siu
        ListNode *slow=head;
        ListNode *fast=head;
        ListNode *prev=NULL;
        
        while(fast && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            
            fast=fast->next->next;
        }
        
        //split the linked list
        prev->next=NULL;
        
        head=sortList(head);
        slow=sortList(slow);
        
        return merge(head,slow);
        
        
    }
};