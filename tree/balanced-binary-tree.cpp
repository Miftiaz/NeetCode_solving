//link: https://neetcode.io/problems/balanced-binary-tree/question


class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if (!root) return true;
        unordered_map <TreeNode*, int> mp;
        mp[nullptr] = 0;
        stack <TreeNode*> stack;
        stack.push(root);
        while(!stack.empty()) {
            TreeNode* node = stack.top();
            if (node->left && mp.find(node->left) == mp.end()) {
                stack.push(node->left);
            }
            else if (node->right && mp.find(node->right) == mp.end()) {
                stack.push(node->right);
            }
            else{
                if(abs(mp[node->left] - mp[node->right]) > 1) return false;
                mp[node] = max(mp[node->left], mp[node->right]) + 1;
                stack.pop();
            }
        }
        return true;
    }
};

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return dfs(root)[0] == 1;
    }

private:
    vector <int> dfs(TreeNode* root) {
        if(!root) return {1, 0};

        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);

        bool balanced = (left[0]==1 && right[0]==1) && abs(left[1]-right[1]) <=1;
        int height = 1 + max(left[1], right[1]);

        return {balanced? 1:0, height};
    }
};


/*

Definitions:
1. A map for storing the height of the nodes;
2. a stack to visit nodes in DFS 
3. Last pointer to point to the last visited node.

Steps:
1. Loop until 
    node is nullptr (we are in the leaf node or a node whose childrens are visited)
    and stack is empty (we've visited all the nodes)
2. If node is not null pointer,
    keep going to the left nodes untill we reach the left most child from the current node.
3. Else,
    (meaning we have reached the leaf node's left child which is nullptr)
    get back to the leaf node by stack.top();
    i. if node->right is null (the node don't have any right subtree)
          or, last = node->right (so the right subtree is already visited)
          means, we have the enough data of left and right subtree to calculate depth of the current node.
          Do so.
          and check if it's balanced.
          mark the node as last visited.
          make node = nullptr, as if it's leaf node.
    ii. Else, node = node->right, keep diving into right subtree.

*/
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        unordered_map < TreeNode*, int > depth;
        stack < TreeNode* > stack;
        depth[nullptr] = 0;
        TreeNode* node = root;
        TreeNode* last = nullptr;

        while(!stack.empty() || node != nullptr) {
            if(node!=nullptr) {
                stack.push(node);
                node = node->left;
            }
            else {
                node = stack.top();
                if(node->right == nullptr || last == node->right) {
                    stack.pop();
                    int left = depth[node->left];
                    int right = depth[node->right];
                    if (abs(left-right) > 1) return false;
                    depth[node] = max(left, right)+1;
                    last = node;
                    node = nullptr;
                } 
                else{
                    node = node->right;
                }
            }
        }
        return true;
    }
};
