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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *list3=new ListNode();
        
        ListNode *ptr=list3;
        
        while(list1 && list2){
            if(list1->val<list2->val){
                ptr->next=list1;
                ptr=ptr->next;
                list1=list1->next;
                
            }
            else{
                ptr->next=list2;
                ptr=ptr->next;
                list2=list2->next;
            }
        }
        
        while(list1){
             ptr->next=list1;
                ptr=ptr->next;
                list1=list1->next;
            
        }
        while(list2){
             ptr->next=list2;
                ptr=ptr->next;
                list2=list2->next;
        }
        
        return list3->next;
    }
};