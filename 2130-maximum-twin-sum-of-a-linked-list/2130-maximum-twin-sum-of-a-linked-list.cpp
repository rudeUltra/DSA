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
    int pairSum(ListNode* head) {
        //using stack no need to reverse it
        
        stack<int>st;
        int n=0;
        ListNode*p1=head;
        while(p1){
            p1=p1->next;
            n++;
        }
        
        
        p1=head;
        int i=0;
        while(p1 && i<n/2){
            st.push(p1->val);
            p1=p1->next;
            ++i;
        }
       
        
        int ans=0;
        while(p1){
            int temp=st.top()+p1->val;
            st.pop();
            ans=max(ans,temp);
            p1=p1->next;
        }
        return ans;
    }
};