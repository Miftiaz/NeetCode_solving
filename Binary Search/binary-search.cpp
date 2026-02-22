//link:https://neetcode.io/problems/binary-search/question

class Solution {
public:
    int search(vector<int>& nums, int target) {
       int l = 0, r=nums.size()-1;
       while (l <= r){
            int m = (l+r)/2;
            if(nums[m] > target){
                r = m - 1;
            }
            else if(nums[m] < target){
                l = m + 1; 
            }
            else return m;
       }
       return -1;
    }
};

/*

Using Lower Bound:

Lower bound binary search finds the first index where a value is greater than or equal to the target.
This means if the target exists in the array, this lower-bound index will point exactly to its first occurrence.
So instead of directly searching for equality, we search for the leftmost position where the target could appear, then verify it.

This approach is especially useful for sorted arrays because it avoids overshooting and naturally handles duplicates.

*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size();

        while (l < r) {
            int m = l + (r - l) / 2;
            if (nums[m] >= target) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return (l < nums.size() && nums[l] == target) ? l : -1;
    }
};