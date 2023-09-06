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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        if (!head) return vector<ListNode*>(k, nullptr); // if nullptr return empty vector of size k
        
        /* Step 1: Count how many nodes are in the linked list*/
        ListNode* itr = head;
        int count = 0;
        while (itr) {
            count++;
            itr = itr->next;
        }
        
        /* Step 2: Count how many should be in each section, and how many additional there are*/
        int amount = count / k;
        int additional = count % k;
        
        /* Step 3: Initialize output vector and pointers to be used, find first seperation point, */
        
        vector<ListNode*> output; // output vectpr
        ListNode* curr = head; // leading pointer
        ListNode* prev = nullptr; // trailing pointer
        
        // finding first seperation point
        int next_start = amount + (additional > 0 ? 1 : 0);
        if (additional > 0) {
            additional--;
        }
        
        /* Step 4: Loop through linked list and seperate when neccesary*/
        for (int i = 0; i < count; i++) {
            // if we are at a seperation point
            if (i == next_start) {
                prev->next = nullptr; // unlink the previous (trailing pointer)
                output.push_back(curr); // add this starting node into out output vector

                // calculate next seperation point
                next_start += amount + (additional > 0 ? 1 : 0);
                if (additional > 0) {
                    additional--;
                }
            }
            // increment pointers
            prev = curr;
            curr = curr->next;
            
            // case to handle the start of the LL
            if (i == 0) {
                output.push_back(head);
            }
        }
        
        // Additional Step: if we still have left over spaces fill with nullptrs
        while (output.size() < k) {
            output.push_back(nullptr);
        }
        
        return output;
    }
};
