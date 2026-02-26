//link: https://neetcode.io/problems/remove-node-from-end-of-linked-list/question

/*

1. Iterate the full list to know the total node N.
2. If remove index = 0, then just return the list without the node.
3. Iterate again to get to previous index of the remove index. 
4. Change the next to be next->next.

*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;

        int N = 0, i=0;

        while(curr != nullptr) {
            N++;
            curr = curr->next;
        }

        int remove_index = N-n;
        if(remove_index == 0) return head->next;

        curr = head;

        while(curr!=nullptr) {
            if(i+1 == (remove_index)) {
                curr->next = curr->next->next;
                break;
            }
            i++;
            curr = curr->next;
        }

        return head;
    }
};

/*

1. Add a dummy node before the list. Point l here.
2. Point r to the head. (r=0)
3. move r to n index. (r = n)
4. move r and l until r is nullptr. (So, we move r and l N-n times)
5. l is now the previous index of the removable index.

*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode (0, head);

        ListNode* left = dummy;
        ListNode* right = dummy->next;

        while(n>0) {
            right = right->next;
            n--;
        }

        while(right != nullptr) {
            left = left->next;
            right = right->next;
        }

        left->next = left->next->next;

        return dummy->next;
    }
};