//link:https://neetcode.io/problems/level-order-traversal-of-binary-tree/question

/*

Recursive solution.

1. Keep a global result (nested vector).
2. Call the dfs using root and 0 depth.
3. In the dfs function, 
    Base case: if we encountered a nullptr, do nothing.
               if res.size() == depth 
                    (meaning: the result vector has 3 indices (0,1,2). but we'll now insert index 3 which doesn't exist.
                    we'll get segmentation error.)
                    simply pushback an empty vector at the depth index.
                push the value of the node to it's depth index.
    Call node->left and node->right tree.

*/
class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> levelOrder(TreeNode* root) {
        dfs(root, 0);
        return res;
    }

    void dfs(TreeNode* node, int depth) {
        if(!node) return;

        if(res.size() == depth) {
            res.push_back({});
        }

        res[depth].push_back(node->val);

        dfs(node->left, depth+1);
        dfs(node->right, depth+1);
    }

};

/*

Iterative solution using BFS.

*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        vector <vector <int>> res;

        queue <TreeNode*> queue;
        queue.push(root);

        while(!queue.empty()) {
            vector <int> level;
            for(int i = queue.size(); i>0; i--) {
                TreeNode* node = queue.front();
                queue.pop();
                level.push_back(node->val);
                if(node->left) queue.push(node->left);
                if(node->right) queue.push(node->right);
            }
            res.push_back(level);
        }

        return res;
    }
};