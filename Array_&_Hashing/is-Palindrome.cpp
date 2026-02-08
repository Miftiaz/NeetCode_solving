//link:https://neetcode.io/problems/is-palindrome/question

class Solution {
public:
    bool isPalindrome(string s) {
        int l, r;
        l = 0, r = s.size()-1;

        while(l < r) {
            
            while(l<r && !isalnum(s[l])){
                l++;
            }
            while(r> l && !isalnum(s[r])){
                r--;
            }
            if (tolower(s[l])!=tolower(s[r])) return 0;
            l++;
            r--;
        }
        return 1;
    }
};
