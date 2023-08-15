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
    ListNode* partition(ListNode* head, int x) {
        ListNode *left=new ListNode();
        ListNode *right=new ListNode();
        ListNode *second=left;
        ListNode *third=right;
        while(head){
            if(head->val<x){
                second->next=head;
                second=second->next;
            }
            else{
                third->next=head;
                third=third->next;
            }
            head=head->next;
        }
        second->next=right->next;
        third->next=NULL;
        return left->next;
        
    }
};