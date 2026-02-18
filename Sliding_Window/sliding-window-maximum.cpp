//link:https://neetcode.io/problems/sliding-window-maximum/question

/*

Using Dynamic Programming

The idea is to keep two vectors for storing left max and right max for every k sized blocks.
For example:
nums = "1 2 1 0 4 2 6", k=3

so, we divide it in blocks of 3,

            1 2 1 | 0 4 2 | 6

Left Max:   1 2 2 | 0 4 4 | 6
Right Max:  2 2 1 | 4 4 2 | 6

So, The starting blocks last element will be 
    | 1 2 1 <-- this one | 0 4 2 6

We start iterating the leftmax from here (left_max index = 2) and right max from 0 (right_max index = 2) . So,Max is 2.

then, (left_max index = 3), (right_max index = 2), Max = 2
                                
To detemine left_max,
    - If it's starting of the block, then just keep the num[i]
    - else, compare the previous left max and num[i], keep the max.

To determine right_max,
    - If it's end of the block, then just keep the num[i]
    - else, compare the next right max and num[i], keep the max. 

*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        int n = nums.size();

        vector <int> left_max(n);
        vector <int> right_max(n);

        left_max[0] = nums[0];
        right_max[n-1] = nums[n-1];

        for(int i=0; i<n; i++){
            if(i%k == 0) left_max[i] = nums[i];
            else left_max[i] = max(left_max[i-1], nums[i]);

            if((n-i-1) % k == 0) right_max[n-i-1] = nums[n-i-1];
            else right_max[n-i-1] = max(nums[n-i-1], right_max[n-i]);
        }

        vector <int> res(n-k+1);
        for(int i = 0; i<n-k+1; i++){
            res[i] = max(left_max[i+k-1], right_max[i]);
        }
        return res;
    }
};
