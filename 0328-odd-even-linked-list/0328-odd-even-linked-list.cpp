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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head; //bruh
        }
        ListNode*odd=head;
        ListNode *even=head->next; //second elemet even
        ListNode *evenhead=even;
        
        while(even && even->next!=NULL){
            odd->next=even->next;
            odd=odd->next;
            even->next=odd->next; //new position
            even=even->next;
        }
        odd->next=evenhead; //connect the linked lists siu
        
        return head;
        
    }
};