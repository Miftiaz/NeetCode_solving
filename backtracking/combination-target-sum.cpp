//link: https://neetcode.io/problems/combination-target-sum/question

/*

Solved using backtracking 

In every step:

We'll add the current indexed value to the string or won't.

- if we add, pass the same index and target = target - arr[i]
- if we don't add it, then increment the index.

- If the target < 0 that means we added more than needed. so, STOP!
- If i is out of bound, STOP!

Check all combinations.

*/

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        backtrack(nums, 0, curr, target);
        return res;    
    }

    void backtrack(vector<int>& arr, int i, vector<int>& curr, int target){
        if(target == 0) {
            res.push_back(curr);
            return;
        }

        if(target < 0 || i >= arr.size()){
            return;
        }

        curr.push_back(arr[i]);
        backtrack(arr, i, curr, target - arr[i]);

        curr.pop_back();
        backtrack(arr, i+1, curr, target);

    }
};

/*

Optimal Backtracking.

1. Sort the array. So that if we encounter a value that makes our sum greater than target, the later values will face the same thing. So, it ensures early stop.
2. In every step, we go level wise. Add all combinations the adding the values in the array (including index j and more)

*/

class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, curr, 0, target);
        return res;    
    }

    void backtrack(vector<int>& arr, int i, vector<int>& curr, int sum, int target){
        if(sum == target) {
            res.push_back(curr);
            return;
        }

        for(int j=i; j<arr.size(); j++) {
            if(sum + arr[j] > target){
                return;
            }
            curr.push_back(arr[j]);
            backtrack(arr, j, curr, sum+arr[j], target);
            curr.pop_back();
        }

    }
};