
//link: https://neetcode.io/problems/longest-consecutive-sequence/question

/*

The main issue was to find the point from where we'll start the loop to find sequences.
We simply identified the start of a sequence.
The logic: n will be a starting point if there's no n-1 value in the array.

*/


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set <int> values;
        for(int x: nums){
            values.insert(x);
        }

        int res = 0, count;

        for(int x: values){
            if (values.count(x-1)) continue;
            count = 0;
            while(values.count(x)) {
                count++;
                x++;
            }
            if (count> res) res = count;
        }
        return res;
    }
};
