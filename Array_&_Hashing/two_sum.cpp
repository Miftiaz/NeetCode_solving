/*
Link:https://neetcode.io/problems/two-integer-sum/question?list=neetcode150
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> values;
        for (int i=0; i<nums.size(); i++){
            int comp = target-nums[i];
            if(values.find(comp) != values.end()){
                return {values[comp], i};
            }
            else{
                values[nums[i]] = i;
            }
        }
    }
};
