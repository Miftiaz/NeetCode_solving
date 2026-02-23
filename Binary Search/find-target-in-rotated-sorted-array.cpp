//link: https://neetcode.io/problems/find-target-in-rotated-sorted-array/question

/*

This implementation 
    First. checks if the left half of every iteration is sorted or has the rotated part
    Then, compares the target with mid and left or right to update l/r

But my Solution compares first, then checks the sorted or rotated, which makes the logics complex.

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while(l <= r) {
            if(target == nums[l]) return l;
            if(target == nums[r]) return r;
            int m = (l + r)/2;
            if (target < nums[m]) {
                if (target < nums[l] && nums[l] < nums[m]){
                    l = m + 1;
                }
                else {
                    if (target == nums[l]) return l;
                    r = m - 1;
                }
            }
            else if(target > nums[m]){
                if (target > nums[r] && nums[r] > nums[m]){
                    r = m - 1;
                }
                else {
                    if (target == nums[r]) return r;
                    l = m + 1;
                }
            }
            else return m;
        }
        return -1;
    }
};


/*

1. Calculate mid.
2. If target == nums[mid], return mid.
3. If nums[l] <= nums[mid] (left half is perfectly sorted, don't have the rotated part or mid is in l now. As m is floor of (l+r)/2, it can be same as l)
    i. If our target is less than nums[l] (which is the smallest number in the sorted left half)
       or, target is greater than nums[mid] (which is the largest number in the sorted left half)
       the target might be in the right half.
       So, l = m+1
    ii. else (the target can be in the range nums[l] <= target <= nums[m]), It's in the left half.
        r = m-1
4. else (the left half contains the rotated part)
    i. if target is less than nums[mid] (as it has the rotated part, left half has smaller numbers than nums[mid])
       or, target is greater than nums[l] (it has the greater numbers in the left half)
       target is in the left half.
       So, r = m - 1;
    ii. else (target can be in the right half)
        l = m + 1;

*/

class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = (l + r) / 2;
            if (target == nums[mid]) {
                return mid;
            }

            if (nums[l] <= nums[mid]) {
                if (target > nums[mid] || target < nums[l]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            } else {
                if (target < nums[mid] || target > nums[r]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            }
        }
        return -1;
    }
};