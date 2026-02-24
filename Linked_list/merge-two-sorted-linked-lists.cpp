//link: https://neetcode.io/problems/merge-two-sorted-linked-lists/solution

/*

We don't use extra list here. Just update one of the list to be the merged one.
We will update the list having the smallest first value. use a flag to keep note which node to return at last.

curr is which node we are on (it may me in any list)
l2 is next candidate value of the other list. if curr is in list1, l2 will be on list2.
if the current->next is null, then just point current->next to l2.

If curr->next is equal or smaller than l2, just continue on the same list.
else, make curr->next as l2, and l2 as current node.

example:
list1 : 1 (curr), 3 (curr->next)
list2 : 1 (l2) , 2, 4

After Iteration 1: 
list1 : 1 , 3 (l2)                      //actually List1: 1, 1, 3 now. as 1 is inserted in the list.
list2 : 1 (curr) , 2(curr->next), 4

After Iteration 2: 
list1 : 1 , 3 (l2)                      //actually List1: 1, 1, 2, 3 now.
list2 : 1  , 2(curr), 4(curr->next)

After Iteration 3: 
list1 : 1 , 3(curr) , curr->next = nullptr            //actually List1: 1, 1, 2, 3 now.
list2 : 1  , 2, 4 (l2)

as we fount null-ptr, just add remaining list2.

List1: 1, 1, 2, 3, 4.

Return List1.
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *curr, *l2, *next1, *temp;
        int flag;

        if (!list1) return list2;
        if (!list2) return list1;

        if(list1->val <= list2->val) {
            l2 = list2;
            curr = list1;
            flag = 1;
        }
        else {
            l2 = list1;
            curr = list2;
            flag = 0;
        }

        while(curr) {
            next1 = curr->next;
            if(next1 == nullptr) {
                curr->next = l2;
                break;
            }
            
            if(next1->val <= l2->val) {
                curr = curr->next;
            } else{
                curr->next = l2;
                curr = l2;
                l2 = next1;
            }
        }
        
        return flag ? list1 : list2;
    }
};

/*

Standard Solution:

Take a dummy node with one value 0. If we took an empty linkedlist, node->next wouldn't be safe.

Until we reach the end of list1 or list2:
1. if list1 pointing value is smaller than list2, point the node->next to list1,
    mode list1 to the next node.
    Do the vice versa if other way around.
2. point the node to the updated or recent one.

If list1 ended, then point the node->next to list2 and vice versa.

return the dummy next as that is the merged list.

Not dummy->next. is dummy is not a pointer but an object.

*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* node = &dummy;

        while(list1 && list2) {
            if(list1->val < list2->val){
                node->next = list1;
                list1 = list1->next;
            }
            else {
                node->next = list2;
                list2 = list2->next;
            }
            node = node->next;
        }

        if(!list1) node->next = list2;
        else node->next = list1;

        return dummy.next;
    }
};