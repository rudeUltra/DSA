class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* start = nullptr;
        ListNode* end = list1;

        // Set start to node a - 1 and end to node b
        for (int index = 0; index < b; index++) {
            if (index == a - 1) {
                start = end;
            }
            end = end->next;
        }
        // Connect the start node to list2
        start->next = list2;

        // Find the tail of list2
        ListNode* tail = list2;
        while (tail->next != nullptr) {
            tail = tail->next;
        }
        // Set the tail of list2 to end.next
        tail->next = end->next;
        end->next =  nullptr;

        return list1;
    }
};