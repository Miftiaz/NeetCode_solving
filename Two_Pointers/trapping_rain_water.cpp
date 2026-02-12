//link: https://neetcode.io/problems/trapping-rain-water/question

/*
Finally solved it but in a peculiar way :3 (both pointers at left, redundant code.)

1. Increment l, r until height[l+1] >= height[l], we get the max_left till a point.No water can be stored if height[l] only keeps incrementing
    as it has no left wall.
2. Had a left l iterator to mark until where we got.
3. We iterated to the last, until height[r] is equal or greater than our left max and added the area.
4. If we get height[r] >= left_max, we moved the l, r pointer to this r, r+1 as this is the new left max barier. updated the left l pointer
5. This worked for until we reached the first max value from the right.
6. For the right side, we did the same process until, we got the the left l iterator.
7. Till now we'd get the result if our left max != first max from the right.
8. But if we get that case, we'd have to add the areas between them.

*/


// class Solution {
// public:
//     int trap(vector<int>& height) {
//         int l = 0, r=1, tot = 0, len = height.size(), left_l;
//         while (height[l] == 0 || height[l+1] >= height[l]){
//             l++;
//             r++;
//         }
//         left_l = l;
//         int max = height[l], area=0;
//         while (l < r && r < len-1){
//             while (height[r] < height[l] && r <= len-1){
//                 area = area + (height[l] - height[r]);
//                 r++;
//                 if(r> len-1) {
//                     break;
//                 }
//             }

//             if(r <= len-1){
//                 tot += area;
//             }
//             else continue;
            
//             area = 0;
//             l = r;
//             r = l+1;

//             while(height[r] >= height[l] && r < len-1){
//                 l++;
//                 r++;
//             }
//             if (height[l] >= max){
//                 left_l = l;
//                 max = height[l];
//             }
//         }

//         r = len-1;
//         l = r-1;

//         area = 0;

//         while(height[r] <= height[l] && l>left_l){
//             r--;
//             l--;
//         }

//         while (l < r && l > 0 && l>left_l){
//             while (height[r] > height[l] && l>left_l){
//                 area = area + (height[r] - height[l]);
//                 l--;
//                 if(l == 0) break;
//             }

//             if(l >= 0){
//                 tot += area;
//             }
            
//             area = 0;
//             r = l;
//             l = r-1;

//             while(height[l] >= height[r] && l > 0 && l > left_l){
//                 l--;
//                 r--;
//             }
//         }

//         int min_two;

//         if(height[l] > height[left_l]) min_two = height[left_l];
//         else if (height[l] > height[left_l]) min_two = height[l];
//         else min_two = height[l];

//         for(int i = left_l; i<=l; i++){
//             tot += (min_two - height[i]);
//         }

//         return tot; 
//     }
// };


/*
Cleanest solution (Uses one pointer at the left, another at the right)

Basic intuition: 
If we compare the left_max and right_max, water can surely be stored as the height same as the minimum one of them.

1. move the pointer having the minimum height.
2. if the height is greater than the current max of the pointer being moved, change the max value. 
    This helps if we get a greater value than the current max, area won't be added of that height.
3. Store the area.
4. Again compare left max and right max.
5. Repeat until l>=r
*/

class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size(), res = 0;

        if(len == 0) return 0;

        int left_max = height[0], right_max = height[len - 1], l=0, r=len-1;

        while(l < r){
            if (left_max < right_max) {
                l++;
                left_max = max(left_max, height[l]);
                res += (left_max - height[l]);
            }
            else {
                r--;
                right_max = max(right_max, height[r]);
                res += (right_max - height[r]);
            }
        }
        return res;
    }
};