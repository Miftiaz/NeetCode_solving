//link: https://neetcode.io/problems/trapping-rain-water/question

/*
Finally solved it but in a peculiar way :3
*/


class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r=1, tot = 0, len = height.size(), left_l;
        while (height[l] == 0 || height[l+1] >= height[l]){
            l++;
            r++;
        }
        left_l = l;
        int max = height[l], area=0;
        while (l < r && r < len-1){
            while (height[r] < height[l] && r <= len-1){
                area = area + (height[l] - height[r]);
                r++;
                if(r> len-1) {
                    break;
                }
            }

            if(r <= len-1){
                tot += area;
            }
            else continue;
            
            area = 0;
            l = r;
            r = l+1;

            while(height[r] >= height[l] && r < len-1){
                l++;
                r++;
            }
            if (height[l] >= max){
                left_l = l;
                max = height[l];
            }
        }

        r = len-1;
        l = r-1;

        area = 0;

        while(height[r] <= height[l] && l>left_l){
            r--;
            l--;
        }

        while (l < r && l > 0 && l>left_l){
            while (height[r] > height[l] && l>left_l){
                area = area + (height[r] - height[l]);
                l--;
                if(l == 0) break;
            }

            if(l >= 0){
                tot += area;
            }
            
            area = 0;
            r = l;
            l = r-1;

            while(height[l] >= height[r] && l > 0 && l > left_l){
                l--;
                r--;
            }
        }

        int min_two;

        if(height[l] > height[left_l]) min_two = height[left_l];
        else if (height[l] > height[left_l]) min_two = height[l];
        else min_two = height[l];

        for(int i = left_l; i<=l; i++){
            tot += (min_two - height[i]);
        }

        return tot; 
    }
};
