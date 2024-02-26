/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return NULL;
        }
        //if no cycle return nuLL
        ListNode *slow=head;
        ListNode *fast=head; 
        ListNode *start=head;
        
        while(fast && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                cout<<slow->val;
                //cycle detectd
                //move start and slow by 1 until they meet
                while(slow!=start){
                    slow=slow->next;
                    start=start->next; //slow moves=L1 + L2
                    //fast moves 2(L1+L2)
                    //BUT fast also moves L1 + L2 +n*Loop length
                    //equate fast we get LHS=RHS => L1=n2-lc which is the length of the left out part
                    //therefore head and slow pointer are bound to meet at L1 or n2-lc distance
                }
                return start;
            }
        }
        return NULL;
    }
};