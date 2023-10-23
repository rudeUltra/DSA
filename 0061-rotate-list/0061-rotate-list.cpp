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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || head==NULL || head->next==NULL){
            return head;
        }
        int n=1;
        //count no of nodes
        ListNode *temp=head;
        while(temp->next){
            temp=temp->next;
            n++;
        }
        temp->next=head; //loop
        k=k%n;
        k=n-k; //position of node which we have to edit
        while(k--){
            temp=temp->next;
        }
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};