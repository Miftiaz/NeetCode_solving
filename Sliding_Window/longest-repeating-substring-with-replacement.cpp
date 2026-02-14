//link: https://neetcode.io/problems/longest-repeating-substring-with-replacement/question?list=neetcode150

/*
Things to define:

1. count[character] ---> count of the character in the current window
2. maxf ---> count of the most found character in the current window.
3. (r-l+1) ---> current window size/length
4. ((r - l + 1) - maxf) ---> number of replacement needed to make the current window full with the max character.

Steps:
1. Iterate r;
2. Increment the count of s[r] as it is now in the window;
3. Check if s[r] has the highest frequency, if so, max = frequency of s[r] in the current window.
4. If replacement needed is greater than capability k, increase the l to shrink the window to right.
   Before that, decrement the left window character's count by one, as it's not in the window now.
5. Repeat 4 until, replacement needed is equal to our capability k.
6. check if the current window length is greater than res or previously found windows.
7. Return res.

*/

class Solution {
public:
    int characterReplacement(std::string s, int k) {

        unordered_map <char, int> count;

        int res = 0, maxf = 0, l = 0;

        for (int r=0; r<s.size(); r++){
            count[s[r]]++;
            maxf = max(maxf, count[s[r]]);

            while ((r - l + 1) - maxf > k){
                count[s[l]]--;
                l++;
            }

            res = max(res, r - l + 1);
        }

        return res;
    }
};