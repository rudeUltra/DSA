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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum=0;
        int carry=0;
        ListNode *dummy=new ListNode(0); //initialize with 0
        ListNode *temp=dummy;
        while(l1!=NULL || l2!=NULL || carry){
            sum=0;
            if(l1!=NULL){
                sum=sum+l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum=sum+l2->val;
                l2=l2->next;
            }
            sum=sum+carry; //add previous carry
            carry=sum/10; //generate new carry
            ListNode *temp1=new ListNode(sum%10);
            temp->next=temp1;
            temp=temp->next;
        }
        return dummy->next;
    }
};