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
    bool isPalindrome(ListNode* head) {
        //brute force is iterate through the entire list then reverse it and check or bleh but space o(n)
        //to do without space divide the linked list split from mid then reverse and check

        ListNode*slow=head;
        ListNode*fast=head;
        ListNode *prev;
        if(head->next==NULL){
            return true;
        }

        while(fast && fast->next!=NULL){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode *temp=head;
        int count=0;
        //odd lenght linked list or even length check
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        if(count%2==1){
            slow=slow->next; //a-b-a
        }
        
        
        prev->next=NULL; //split the list
        //reverse the linked list from head to split bc.
        prev=NULL;
        temp=NULL;
        while(head){
            temp=head->next;
            head->next=prev;
            prev=head;
            head=temp;
        }

        //now check
        while(prev!=NULL && slow!=NULL){
            if(prev->val!=slow->val){
                return false;
            }
            prev=prev->next;
            slow=slow->next;
        }

        return true;


    }
};