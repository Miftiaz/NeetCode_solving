//Link:https://neetcode.io/problems/products-of-array-discluding-self/question

/*
//The solution I came up with and it works but takes much space.:

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        vector <int> left_to_right(length), right_to_left(length), result(length);

        left_to_right[0] = nums[0];
        right_to_left[length-1] = nums[length-1];

        for(int i = 1; i< length; i++){
            left_to_right[i] = left_to_right[i-1]*nums[i];
        }

        for (int i = length - 2; i>=0 ; i--){
            right_to_left[i] = right_to_left[i+1]*nums[i];
        }

        result[0] = right_to_left[1];
        result[length-1] = left_to_right[length-2];
        
        for (int i = 1; i<length-1 ; i++){
            result[i] = left_to_right[i-1]*right_to_left[i+1];
        }

        return result;   
    }
};

*/

/*
This solution has better time complexity but still got the space complexity

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector <int> result(n);

        result[0] = 1;

        for(int i =1; i<n; i++){
            result[i] = result[i-1] * nums[i-1];
        }

        int suffix = 1;
        for (int i = n-1; i>=0; i--){
            result[i] *= suffix;
            suffix *= nums[i];
        }

        return result;   
    }
};

*/

//Best one! Used one logic

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        vector <int> left_to_right(length), right_to_left(length), result(length);

        left_to_right[0] = nums[0];
        right_to_left[length-1] = nums[length-1];

        for(int i = 1; i< length; i++){
            left_to_right[i] = left_to_right[i-1]*nums[i];
            right_to_left[length-i-1] = right_to_left[length-i]*nums[length-i-1];
        }

        result[0] = right_to_left[1];
        result[length-1] = left_to_right[length-2];
        
        for (int i = 1; i<length-1 ; i++){
            result[i] = left_to_right[i-1]*right_to_left[i+1];
        }

        return result;   
    }
};


