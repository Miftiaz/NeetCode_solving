//link: https://neetcode.io/problems/two-integer-sum-ii/question

/*
As the array was sorted, we just added two pointers in the left and right. 
moved the right pointer if it was greater or equal to target-left
else, moved the left pointer.
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size()-1;

        while(l < r){
            while(l < r && numbers[r] >= (target-numbers[l])){
                if (numbers[l] + numbers[r] == target) return {l+1, r+1};
                r--;
            }
            l++;
        }
        
        return {};
    }
};
