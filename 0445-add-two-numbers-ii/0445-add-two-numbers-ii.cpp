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
    
    
    ListNode* reverse_list(ListNode*curr){
        ListNode* prev=NULL;
        while(curr){
            ListNode*temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
    
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //the point where there is no hope we create hope
        //this is what hard feels like this is where champions are born
        
        //less go
        //reverse linked list then traverse ok 
        
        ListNode*curr1=reverse_list(l1);
        ListNode*curr2=reverse_list(l2);
        
        
        int carry=0;
        ListNode*ans=new ListNode();
        ListNode*curr=ans;
        
        while(curr1 || curr2 || carry){
            
            int sum=0;
            if(curr1!=NULL){
                sum+=curr1->val;
                curr1=curr1->next;
            }
            
            if(curr2!=NULL){
                sum+=curr2->val;
                curr2=curr2->next;
            }
            
            sum+=carry;
            
            ListNode*temp=new ListNode(sum%10);
            
            carry=sum/10;
            
            curr->next=temp;
            curr=curr->next;
            
            
        }
        
        return reverse_list(ans->next);
        
        
        
        
    }
};