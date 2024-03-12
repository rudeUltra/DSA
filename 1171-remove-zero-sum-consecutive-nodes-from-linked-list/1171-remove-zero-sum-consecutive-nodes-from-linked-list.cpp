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
    ListNode* removeZeroSumSublists(ListNode* head) {
        //Start from each node check valid or not kind of brute force Siu
        ListNode*ans=new ListNode(); //dummy node
        ListNode*temp=ans;
        
        ListNode*curr=head;
        //Make new nOdes
        if(head->next==NULL && head->val==0){
            return head->next;
        }
        
        while(curr!=NULL){
            long long sum=0;
            
            ListNode*nextNode=curr;
            bool flag=true;
            while(nextNode!=NULL){
                sum+=nextNode->val;
                if(sum==0){
                    //Fok
                    cout<<"called";
                    curr=nextNode->next;
                    
                    flag=false;
                    break;
                }
                nextNode=nextNode->next;
            }
            if(flag==true){
                //no subarray hm.
                ListNode*prev=new ListNode(curr->val);
                temp->next=prev;
                temp=temp->next;
                curr=curr->next;
            }
            
        }
        
        return ans->next;
    }
};