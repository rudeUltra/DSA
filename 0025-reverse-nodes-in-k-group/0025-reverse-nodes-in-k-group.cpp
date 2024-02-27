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
    ListNode* getKth(ListNode*gprev,int k){
        ListNode*curr=gprev;
        while(k && curr!=NULL){
            curr=curr->next;
            k--;
        }
        return curr;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode*ans=new ListNode(0);
        ListNode*gprev=ans;
        gprev->next=head; //connected nOice
        
        while(1){
            ListNode*kth=getKth(gprev,k);
            
            if(kth==NULL){
                //Not enough NOdes sed
                break;
            }
            
            ListNode*gnext=kth->next;
            
            //reverse Now NOice
            ListNode*prev=gnext; //nOICE not null like normal Reverse AahA.
            ListNode*curr=gprev->next;
            while(curr && curr!=gnext){
                ListNode*temp=curr->next;
                curr->next=prev;
                prev=curr;
                curr=temp; 
            }
            
            //reverseD nOice now what.
            ListNode*temp=gprev->next;
            gprev->next=kth;
            gprev=temp;
            
        }
        
        return ans->next;
    }
};