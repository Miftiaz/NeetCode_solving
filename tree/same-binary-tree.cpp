//link: https://neetcode.io/problems/same-binary-tree/question
/*

Recursive solution:
1. If current nodes are null, then simply return true;
2. If current nodes are not null and their values match, check the left subtrees and the right subtrees matches or not.
3. In any other case, return false;
   (any one node is null but the other one isn't)
   (the values don't match)

*/
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        
        if( p && q && p->val == q->val) {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        else{
            return false;
        }
        return false;
    }
};

/*

Iterative DFS:
Use the same logic as the recursive solution. Just use a stack.
1. If both nodes are null, continue iterating.
2. If they are not null and their values match, push their childrens to the stack.
3. In any other case return false;

*/

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack < pair<TreeNode*, TreeNode*>>stack;
        stack.push({p, q});

        while(!stack.empty()){
            auto [a, b] = stack.top();
            stack.pop();
            if( !a && !b) continue;
            if (a && b && a->val == b->val) {
                stack.push({a->right, b->right});
                stack.push({a->left, b->left});
            }
            else return false;
        }
        return true;
    }
};