//link: https://neetcode.io/problems/reorder-linked-list/question

/*

1. First, we determine the middle node of the list using slow, fast pointer algorithm.
2. Slow will be (n/2)th node (0-indexed)
3. The nodes after the slow node, needs to be reversed.
4. End the first half by pointing slow->next to null pointer.
5. Change the ->nexts to reorder the list.

*/

class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second_half = slow->next;
        ListNode* prev = slow->next = nullptr;
        while (second_half != nullptr) {
            ListNode* temp = second_half->next;
            second_half->next = prev;
            prev = second_half;
            second_half = temp;
        }

        ListNode* first_half = head;
        second_half = prev;  //as prev is the head of reversed list.

        while(second_half != nullptr) {
            ListNode* tmp1 = first_half->next;
            ListNode* tmp2 = second_half->next;
            first_half->next = second_half;
            second_half->next = tmp1;
            first_half = tmp1;
            second_half = tmp2;
        }
    }
};