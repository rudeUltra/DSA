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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy=new ListNode(0,head);
        ListNode *gprev=dummy; //group previous
        
        while(1){
            ListNode *kth=getkth(gprev,k);
            if(kth==NULL){
                break; //k size group doesnt exist so break loop
            }
            //k size group exists so perform reverse
            ListNode *gnext=kth->next;
            
            //reverse
            
            ListNode *prev=kth->next;
            ListNode *curr=gprev->next;
            while(curr!=gnext){
                ListNode *temp=curr->next;
                curr->next=prev;
                prev=curr;
                curr=temp;
            }
            
            //after reversing
            ListNode *temp=gprev->next; //K size group reversed move to the next
            gprev->next=kth;
            gprev=temp;
            
        }
        return dummy->next;
    }
    ListNode* getkth(ListNode *curr,int k){
        while(curr && k>0){
            curr=curr->next;
            k--;
        }
        return curr;
    }
};