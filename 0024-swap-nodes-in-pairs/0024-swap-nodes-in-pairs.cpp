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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL){
            return head;
        }
        if(head->next==NULL){
            return head;
        }
        ListNode* prev=new ListNode(0);
        prev->next=head;
        ListNode *ans=prev;
        
        while(head && head->next!=NULL){
            ListNode*temp=head->next->next;
            head->next->next=head;
            prev->next=head->next;
            head->next=temp;
            prev=head;
            head=temp;
            
        }
        
        return ans->next;
        
        
    }
};