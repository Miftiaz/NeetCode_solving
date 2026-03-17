//link: https://neetcode.io/problems/subsets/question

/*

Backtracking

For every step:
1. We will add the current indexed value to the current subset
2. We won't add it

Push the current subset if Iwe have iterated all the numbers.

*/

class Solution {
public:
    vector <vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>curr;
        backtrack(nums, 0, {});
        return res;
    }

    void backtrack(vector<int>& nums, int i, vector<int> subset){

        if(i >= nums.size()){ 
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        backtrack(nums, i+1, subset);

        subset.pop_back();
        backtrack(nums, i+1, subset);
    }
};

/*

Iteration

Iterate every number and add it to the existing subsets to create new subsets.

{1, 2, 3}

Start: res = {{}}

for number 1,
res.size = 1; Loop 1 time
        i. i = 0
        ii. Copu res[0], which is {}
        iii. push 1 in it {1}
        iv. push {1} to the res.

now res = {{}, {1}}

for number 2,
res.size = 2; Loop 2 times
        i. i = 0
        ii. Copy res[0], which is {}
        iii. push 2 in it {2}
        iv. push {2} to the res.

        i. i = 1
        ii. Copy res[1], which is {1}
        iii. push 2 in it {1, 2}
        iv. push {1, 2} to the res.        

*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        for(int num: nums) {
            int size = res.size();
            for(int i = 0; i<size; i++){
                vector<int> subset = res[i];
                subset.push_back(num);
                res.push_back(subset);
            }
        }
        return res;
    }
};


/*

Bit manipulation

An array with n numbers will have 2^n subsets.

So, we will create these subsets where 0 at position i means don't include the nums[i] in the current subset. 
                                        1 -------------------------------------include.

If n = 3

000 
001
010
011
100
101
110
111

outer loop just iterates till number 0 - 7.
Inner loop creates 0 - (n-1)

000 & 001 --> checks bit 0
000 & 010 --> checks bit 1
000 & 100 --> checks bit 2

*/

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;
        for(int i=0; i < (1 << n); i++) {
            vector <int> subset;
            for (int j = 0; j<n; j++) {
                if( i & (1 << j)){
                    subset.push_back(nums[j]);
                }
            }
            res.push_back(subset);
        }
        return res;
    }
};
