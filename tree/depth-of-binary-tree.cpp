//link: https://neetcode.io/problems/depth-of-binary-tree/question

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

/*

Using DFS, We stored nodes, and their levels in the stack.
        1
      /   \
     2     3
    /      
   4  
  
Initially:
stack: [{1,1}]
res = 0

Then iteration 1:
stack: [{2, 2}, {3, 2}]
pop {1, 1} so, res = 1

Then iteration 2:
stack: [{2, 2}]
pop {3, 2} so, res = 2

Then iteration 3:
stack: [{4, 3}]
res = 2

Then iteration 4:
stack: []
Pop {4, 3}, so, res = 3

*/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        stack <pair <TreeNode*, int>> stack;
        int res = 0;

        stack.push({root, 1});

        while(!stack.empty()) {
            TreeNode* node = stack.top().first;
            int depth = stack.top().second;

            res = max(res, depth);
            stack.pop();

            if(node->left) stack.push({node->left, depth+1});
            if(node->right) stack.push({node->right, depth+1});
        }

        return res;
    }
};