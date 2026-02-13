//link: https://neetcode.io/problems/longest-substring-without-duplicates/question

/*
Using Set (Space complexity O(n))

1. Move the right window pointer gradually.
2. Insert a value to the set if it doesn't exist on the set.
3. If it exists, delete the current s[l], keep incrementing left window pointer, 
    keep deleting the values until the set doesn't contain the s[r].
    insert the value again in the set, as it was deleted.
4. get the result.

Example:

aaaba

intially: set = {} , l =0

after r=0, set = {a}, l=0;

      r=1; set = {}, l=1; ---while loop
           set = {a}, l=1; ---inserting the deleted value

      r=2; set = {}, l=2;
           set = {a}, l=2;

      r=3, set = {a,b}, l=2;

      r=4, set = {b}, l =3;
           set = {b, a}, l=3;

*/
// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         int l = 0, r = 0, res = 0;
//         unordered_set <char> val;
//         for(int r = 0; r< s.size(); r++){
//             while (val.find(s[r]) != val.end()){
//                 val.erase(s[l]);
//                 l++;
//             }

//             val.insert(s[r]);
//             res = max(res, r - l +1);
            
//         }
//         return res;
//     }
// };

/*
Using hash map (Space complexity O(1))

1. Move the right window pointer gradually.
2. Insert a value to the and its index to the map if it doesn't exist.
3. If it exists, replace the l with the max of l and the found value's index + 1; (why max? answer is in the example)
    Update the found character and it's index in the map.
4. get the result.

s = "abba"

after   r = 0, hash = {(a, 0)}, l=0, r=0, res = 1

        r = 1, hash = {(a, 0), (b, 1)}, l=0, r=1, res=2

        r = 2, hash = {(a, 0), (b, 2 ---updated)}, l = 2, r=2, res=2

        r = 3, hash = {(a, 3---updated), (b, 2)}, l= 2. r=3, res=2
                                                  here, if we didn't say max(val_with_i[s[r]] + 1, l),
                                                  and just say val_with_i[s[r]] + 1
                                                  we'd find l=1, as s[r] is a. 
                                                  and val_with_i[a] is 0 in the hash.
                                                  Max helps us to find where we are finding the left window.

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, res = 0;
        unordered_map <char, int> val_with_i;
        for(int r = 0; r< s.size(); r++){
            if (val_with_i.find(s[r]) != val_with_i.end()){
                l = max(val_with_i[s[r]] + 1, l);
            }
            val_with_i[s[r]] = r;
            res = max(res, r - l +1);
        }
        return res;
    }
};
