//link: https://neetcode.io/problems/buy-and-sell-crypto/question

/*
1. Initialize left, right point of the window.
2. if price[r] >= price[l]
    check if it's sold, we'd get more profit than max or not. if so, replace max.
    r++;
3. If price[r] < price[l] and r!= end of array,
    make the r new left point of window.
    
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int l = 0, r =1, len = prices.size(), temp, max = 0;

        while (r<len) {
            while(prices[r] >= prices[l] && r<len){
                temp = prices[r] - prices[l];
                if(temp > max) max = temp;
                r++;
            }
            if (r<len-1) {
                l = r;
                r = l+1;
            }
            else return max;
        }
        return max;
    }
};
