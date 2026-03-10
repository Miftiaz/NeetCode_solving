//link: https://neetcode.io/problems/count-good-nodes-in-binary-tree/question

/*

Idea: 
We'll keep track of the highest value found till now in the path from a node to the root.
If it's greater than the current node's value, then the node is not a good node.
Otherwise it is.

*/

/*Recursive Solution*/

class Solution {
public:
    int res = 0;
    int goodNodes(TreeNode* root) {
        if(root) dfs(root, root->val);
        return res;
    }
    void dfs(TreeNode* node, int highest){
        if(!node) return;
        if(node->val >= highest) res++;
        highest = max(highest, node->val);
        dfs(node->left, highest);
        dfs(node->right, highest); 
    }
};

/*Iterative Solution*/

class Solution {
public:
    int goodNodes(TreeNode* root) {
        int res = 0;
        if(!root) return res;
        queue <pair<TreeNode*, int>> queue;
        queue.push({root, root->val});
        while(!queue.empty()) {
            auto [node, max_so_far] = queue.front();
            queue.pop();
            if(node->val >= max_so_far) res++;
            max_so_far = max(max_so_far, node->val);
            if(node->left) queue.push({node->left, max_so_far});
            if(node->right) queue.push({node->right, max_so_far});
        }
        return res;
    }
};