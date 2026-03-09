//link:https://neetcode.io/problems/binary-tree-right-side-view/question
/*

Recursive solution (DFS)
1. call the rightmost tree first, 
2. If depth == res.size(); (which will be for the rightmost node of the level) push the value.
3. res size will change, so left node values won't be inserted.

*/
class Solution {
public:
    vector<int> res;
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return res;
    }

    void dfs(TreeNode* node, int depth){
        if(!node) return;

        if(res.size() == depth) res.push_back(node->val);

        dfs(node->right, depth+1);
        dfs(node->left, depth+1);
    }
};

/*

BFS solution (Iterative):

1. Iterate normally.
2. push the value only if it's the last node of the level (i=1)

*/
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};

        queue <TreeNode*> queue;
        vector <int> res;

        queue.push(root);

        while(!queue.empty()){
            for(int i = queue.size(); i>0; i--){
                TreeNode* node = queue.front();
                if (i==1) res.push_back(node->val);
                queue.pop();
                if(node->left) queue.push(node->left);
                if(node->right) queue.push(node->right);
            }
        }

        return res;
    }
};
