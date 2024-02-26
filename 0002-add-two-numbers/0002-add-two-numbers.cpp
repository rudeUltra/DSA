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
        //I wanna show u oFF Hold My HAnD Boi.
        
        int carry=0;
        
        ListNode*ans=new ListNode(0); //DUmmy NOice
        ListNode*temp=ans;
        
        while(l1 || l2 || carry){
            int sum=0;
            if(l1){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2){
                sum+=l2->val;
                l2=l2->next;
            }
            //IF because only caRRy also exists NOice last one pen and paper hm.
            sum+=carry;
            carry=sum/10;
            sum=sum%10;
            ListNode*curr=new ListNode(sum);
            temp->next=curr;
            temp=temp->next;
        }
        
        return ans->next;
    }
};