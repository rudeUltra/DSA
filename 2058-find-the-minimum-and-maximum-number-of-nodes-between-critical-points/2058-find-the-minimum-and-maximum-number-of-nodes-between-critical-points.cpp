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
    
    bool isCritical(ListNode*head,ListNode*next,ListNode*prev){
        if(head->val>prev->val && head->val>next->val){
            return true;
        }
        else if(head->val<prev->val && head->val<next->val){
            return true;
        }
        
        return false;
    }
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>ans;
        ListNode*curr=head;
        vector<int>list;
        ListNode*prev=NULL;
        int i=1;
        while(curr){
            if(prev!=NULL && curr->next!=NULL){
                if(isCritical(curr,curr->next,prev)){
                    list.push_back(i);
                }
            }
            prev=curr;
            curr=curr->next;
            i++;
        }
        if(list.size()<2){
            return {-1,-1};
        }
        int dist=INT_MAX;
        for(int j=0;j<list.size()-1;++j){
            cout<<list[j]<<" "<<list[j+1]<<" ";
            int temp=list[j+1]-list[j];
            dist=min(dist,temp);
        }
        ans.push_back(dist);
        ans.push_back(list[list.size()-1]-list[0]);
        
        return ans;
    }
};