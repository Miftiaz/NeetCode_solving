//link: https://neetcode.io/problems/kth-smallest-integer-in-bst/question?list=neetcode150

/* 
Inorder traversal 
*/

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        stack<TreeNode*>s;
        s.push(root);
        TreeNode* node = root;
        while(!s.empty()) {
            while(node) {
                if(node->left) s.push(node->left);
                node = node->left;
            }
            node = s.top();
            s.pop();
            k--;
            if (k == 0) return node->val;
            if(node->right){
                s.push(node->right);
                node = node->right;
            }
            else{
                node = nullptr;
            } 
        }
    }
};