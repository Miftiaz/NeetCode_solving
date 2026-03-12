//link: https://neetcode.io/problems/kth-smallest-integer-in-bst/question?list=neetcode150

/* 
Inorder traversal 
*/

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> stack;
        TreeNode* curr = root;

        while (!stack.empty() || curr != nullptr) {
            while (curr != nullptr) {
                stack.push(curr);
                curr = curr->left;
            }
            curr = stack.top();
            stack.pop();
            k--;
            if (k == 0) {
                return curr->val;
            }
            curr = curr->right;
        }

        return -1;
    }
};

/*

Morris Traversal O(1) space.

*/

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return -1;
        TreeNode* curr = root;

        while(curr) {
            if(!curr->left) {
                k--;
                if(k==0) return curr->val;
                curr = curr->right;
            }
            else{
                TreeNode* pre = curr->left;
                while(pre->right && pre->right != curr) {
                     pre = pre->right;
                }
                if(!pre->right){
                    pre->right = curr;
                    curr = curr->left;
                }
                else {
                    pre->right = nullptr;
                    k--;
                    if(k==0) return curr->val;
                    curr = curr->right;
                }
            }
        }

        return -1;
    }
};