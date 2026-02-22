//link: https://neetcode.io/problems/find-minimum-in-rotated-sorted-array/question

/*

Intuition:
------------------------------------
In a rotated sorted array, the minimum element is the first element of the rotated portion.
Using binary search, we compare the middle value with the rightmost value:

If nums[mid] < nums[right], then the minimum lies in the left half (including mid). (that's why r = m not r = m-1)
Otherwise, the minimum lies in the right half (excluding mid). (l = m+1)
This behaves exactly like finding a lower bound, gradually shrinking the search space until only the minimum remains.

Algorithm
Set left = 0 and right = n - 1.
While left < right:
Compute mid.
If nums[mid] is less than nums[right], move right to mid (minimum is on the left).
Otherwise, move left to mid + 1 (minimum is on the right).
When the loop ends, left points to the smallest element.
Return nums[left].

*/

class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0, r = nums.size() - 1;

        while(l < r) {
            int m = (l+r)/2;
            if(nums[m] < nums[r]){
                r = m;
            }
            else {
                l = m + 1; 
            }
        }

        return nums[l];
    }
};
