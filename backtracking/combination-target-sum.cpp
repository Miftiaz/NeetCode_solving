//link: https://neetcode.io/problems/combination-target-sum/question

/*

Solved using backtracking

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