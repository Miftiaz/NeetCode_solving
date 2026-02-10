// link: https://neetcode.io/problems/three-integer-sum/question?list=neetcode150

/*
It could be same as two sum but just having a different target every time.
But using a hash map would need O(n) space.

So, we went for Two pointer.

1. Sorted the array.
2. Selected a number as target = -number1
    number1 + number2 + number3 = 0; 
    number2 + number3 = -number1
3. left pointer = i+1, right pointer = length -1
4. If nums[l] + nums[r] > target, then we have to take a smaller number which can be done by r--;
    if nums[l] + nums[r] < target, we have to take a bigger number by l++;
5. if found a sum, push the values, and find for more combo of the sum.

Some optimization:
1. If the very first value in the sorted array is > 0, no negative number. so, no result possible.
2. Take l = i+1, if a combo exists in l<i+1, it's already pushed in the result.
3. If a combo is found, and after l++, r--, we find the same nums[l], we just skip it as it would return same combo.

*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector <vector<int>> res;

        sort(nums.begin(), nums.end());
        int length = nums.size();
        for(int i = 0; i<length; i++) {
            if (nums[i] > 0) break;
            if (i> 0 && nums[i] == nums[i-1]) continue;
            int target = -nums[i];
            int l = i+1, r = length-1;
            while(l< r){
                if (nums[l] + nums[r] > target){
                    r--;
                }
                else if (nums[l] + nums[r] < target){
                    l++;
                }
                else {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while (l< r && nums[l] == nums[l-1]) {
                        l++;
                    }
                }
            }
        }

        return res;
        
    }
};

