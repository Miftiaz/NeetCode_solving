//link: https://neetcode.io/problems/lowest-common-ancestor-in-binary-search-tree/question

//Recursive solution

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) return nullptr;

        if (max(p->val, q->val) < root->val) {
            return lowestCommonAncestor(root->left, p, q);
        }

        else if (min(p->val, q->val) > root->val) {
            return lowestCommonAncestor(root->right, p, q);
        }

        else return root;
    }
};

//Iterative solution

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || !p || !q) return nullptr;
        TreeNode* curr = root;
        while(curr){
            if (max(p->val, q->val) < curr->val) {
                curr = (curr->left);
            }
            else if(min(p->val, q->val) > curr->val) {
                curr = (curr->right);
            }
            else return curr;
        }
        return nullptr;
    }
};