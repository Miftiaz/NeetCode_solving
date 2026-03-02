//link: https://neetcode.io/problems/binary-tree-diameter/question

/*

1. We keep a map to store max height and max diameter of a node.
2. Defined max height and diameter of a null pointer to 0.
3. Just like DFS, we keep stacking up the nodes untill we reach a leaf node. But don't pop any node.
4. Only pop a node if we know it's left and right nodes are visited (we know mp[left_node] and mp[right_node]).
    also, calculate the max height and diameter of the node.
    max height is simple, max of left, right subtree + 1.
    but max diameter can be:
    - diameter of the left tree (it may have the larget one.)
    - diameter of the right subtree.
    - or sum of max height of left and right subtree.
5. Lastly return the root node's max diameter.

*/


class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        unordered_map <TreeNode*, pair<int, int>> mp;
        mp[nullptr] = {0, 0};
        stack <TreeNode*> stack;
        stack.push(root);

        while(!stack.empty()) {
            TreeNode* node = stack.top();
            if(node->left && mp.find(node->left) == mp.end()) {
                stack.push(node->left);
            }
            else if(node->right && mp.find(node->right) == mp.end()) {
                stack.push(node->right);
            }
            else{
                stack.pop();
                auto[left_height, left_dia] = mp[node->left];
                auto[right_height, right_dia] = mp[node->right];

                int height, dia;
                height = max(left_height, right_height) + 1;
                dia = max(left_height+right_height, max(left_dia, right_dia));
                mp[node] = {height, dia};
            }
        }
        return mp[root].second;
    }
};