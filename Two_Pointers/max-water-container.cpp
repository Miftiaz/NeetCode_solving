//link: https://neetcode.io/problems/max-water-container/question


//primary solution: It was accepted but took a bit more time than the optimal. Forgot to use the min function.
/*
class Solution {
public:
    int maxArea(vector<int>& heights) {
        int len = heights.size();

        int l = 0, r = len - 1, min_of_two;
        int dif = r-l;

        if (heights[l] <= heights[r]) {
            min_of_two = heights[l];
        }
        else  {
            min_of_two = heights[r];
        }

        int max_depth = min_of_two * dif;

        while (l < r){
            while (heights[l] <= min_of_two && l<r){
                l++;
            }
            while (heights[r] <= min_of_two && l<r){
                r--;
            }
            
            dif = r-l;

            if (heights[l] <= heights[r]) {
                min_of_two = heights[l];
                l++;
            }
            else  {
                min_of_two = heights[r];
                r--;
            }

            int temp_max_depth = min_of_two * dif;

            if (temp_max_depth > max_depth) max_depth = temp_max_depth;

            
        }
        return max_depth;
    }
};

*/


/*
This is more readable and performs better.
*/

class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int res = 0;

        while (l < r) {
            int area = min(heights[l], heights[r]) * (r - l);
            res = max(res, area);

            if (heights[l] <= heights[r]) {
                l++;
            } else {
                r--;
            }
        }
        return res;
    }
};