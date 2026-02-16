//Link: https://neetcode.io/problems/minimum-window-with-characters/question

/*
Using Dynamic Window size.

example, s = "aabbc", t="abc"

Some definition:
1. countT - frequencies of the characters in the target string
2. window[c] - frequency of character c in the current window
3. have - how many unique character count has been fulfilled.

   eg. 
   we need a --> 1
           b --> 1
           c --> 1

  so, if in the current window, we have 1 'a', the window['a'] = 1
  and have = 1, as we needed 1 a.

1. if target string length is greater than s, return empty string as it's not possible.
2. store the frequencies of the target string characters in countT
3. Keep a pair to keep the left and right window pointer.
4. Increment the right window. 
5. Increment the frequency of the s[r] as it's in the window now.
6. if the character s[r] exists in the target (it will be in the countT) and the frequencies of target and current window
   matches, increment 'have'
7. If we found every character with needed frequencies, (have == need) enter while loop until a needed character is deleted.
    (i) if current window length is less than previously found result length, update it.
    (ii) keep shrinking the left window.
    (iii) update have if needed.
8. Return result.

Some Optimization:

1. Keeping pairs to avoid determining the substring every time we find a l, r.
2. As we are decrementing window[s[l]], it will be less than frequency we need. no need of checking ==.
3. Defined resLen as the s.size() + 1. as result can't be greater than s.size().

*/

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        unordered_map <char, int> countT, window;

        for(char c: t){
            countT[c]++;
        }

        int have = 0, need = countT.size(), resLen= s.size() + 1, l = 0;
        pair <int, int> res{-1, -1};

        for (int r = 0; r<s.size(); r++){
            char c = s[r];
            window[c]++;

            if(countT.count(c) && countT[c] == window[c]){
                have++;
            }

            while (have == need) {
                if((r - l + 1 < resLen)){
                    resLen = r - l + 1;
                    res = {l, r};
                }

                window[s[l]]--;
                if( countT.count(s[l]) && window[s[l]] < countT[s[l]]){
                    have--;
                }
                l++;
            }
        }

        return resLen == s.size() + 1 ? "" : s.substr(res.first, resLen);

    }
};
