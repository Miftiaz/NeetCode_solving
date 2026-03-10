//link: https://neetcode.io/problems/valid-binary-search-tree/question

/*

Main Idea:
1. Every node should satisfy a constrain.
2. If it came left from a node (it's a left child), if should be less than the node and greater than the last left parent node we've seen or LONG_MAX (for the root node)
    So, left = left, right = node->val
3. If it came right from a node (it's a right child), it should be greater than that node and less than last seen parent right node or LONG_MIN (for the root node)
    So, left = node->right, right = right

*/
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }

    bool dfs(TreeNode* node, long left, long right) {
        if(!node) return true;
        if(!(left < node->val && node->val < right)) return false;
        return dfs(node->left, left, node->val) && dfs(node->right, node->val, right);
    }
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root) return true;
        queue<tuple<TreeNode*, long, long>> q;
        q.push(make_tuple(root, LONG_MIN, LONG_MAX));
        while(!q.empty()){
            auto [node, left, right] = q.front();
            if(!(left < node->val && node->val < right)) return false;
            q.pop();
            if(node->left) q.push(make_tuple(node->left, left, node->val));
            if(node->right) q.push(make_tuple(node->right, node->val, right));
        }
        return true;
    }
};