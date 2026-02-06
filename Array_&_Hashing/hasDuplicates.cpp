//link: https://neetcode.io/problems/duplicate-integer/question

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set <int> arra;
        for ( int x: nums){
            if (arra.count(x)){
                return true;
            }
            else{
                arra.insert(x);
            }
        }
        return false;
    }
};