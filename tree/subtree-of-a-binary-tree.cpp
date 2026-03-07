//link: https://neetcode.io/problems/subtree-of-a-binary-tree/question

class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!subRoot) return true;
        if(!root) return false;

        if(isSameTree(root, subRoot)) return true;

        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }

private:
    bool isSameTree(TreeNode* a, TreeNode* b){
        if (!a && !b) return true;
        if (a && b && a->val == b->val) {
            return isSameTree(a->left, b->left) && isSameTree(a->right, b->right);
        }
        else return false;
    }
}


/*

Using Z-algorithm

1. First serialize both the main tree and the subtree.
2. combine them as subroot + '|' + root.
3. Compute the z array for the combined string.
4. If there's a value in the z array equal as the length of the subtree, return true, else false.

The main idea of z-algorithm:
1. z[0] is initilized 0 or n.
2. start from i=1, comparing z[0] and z[i].
    If match: z[i]++; compare z[1] and z[i+1];
    if they don't match increment i;
Z-algo just compares how many characters match starting at index i with the string from the very begining.

s = aaabaa
z = 021021

Here, it index = 1, substring from 1 = aabaa, main string = aaabaa
                    first two characters match so, z[1] = 2

But this approach takes O(n^2) time.


What's the z_function doing:
Optimizing the solution.
We maintain a window here.
Two cases, 1. we haven't yet found the z-values and outside the window.(calculate normally) (i> r)
           2. We are in the window and previously found the z-values. Reuse them. (i<=r)

i+z[i]-1 ---> index till we've found match.
r-i+1 --> remaining item in the window
z[i-l] ---> mirror point at the begining of the z array. 

1. If we are outside the window, keep comparing s[z[i]] and s[i+z[i]], if match, increment z[i]
    expand window, (till we've found match)
2. If we are inside the window, we already know the z[i]. in most cases it'd be z[i-l]
    but we can have max r-i+1 matches. so we just check minimum of z[i-l] and r-i+1


*/



class Solution {
public:
    string serialize(TreeNode* node) {
        if (!node) {
            return "$#";
        }
        return to_string(node->val) + serialize(node->left) + serialize(node->right);
    }

    vector <int> z_function(string s){
        int n = s.size();
        int l = 0, r = 0;
        vector <int> z(s.length());
        for(int i=1; i<n; i++) {
            if (i<=r) {
                z[i] = min(r-i+1, z[i-l]);
            }
            while(i+z[i] < n && s[z[i]] == s[i+z[i]]){
                z[i]++;
            }
            if(i+z[i]-1 > r) {
                l = i;
                r = i + z[i] - 1;
            }
        }
        return z;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        string serialized_root = serialize(root);
        string serialized_subRoot = serialize(subRoot);

        string combined = serialized_subRoot + '|' + serialized_root;
        vector <int> z_values = z_function(combined);

        int sub_len = serialized_subRoot.size();

        for(int i = sub_len + 1; i< combined.size(); i++) {
            if (z_values[i] == sub_len) return true;
        }
        return false;
    }
};