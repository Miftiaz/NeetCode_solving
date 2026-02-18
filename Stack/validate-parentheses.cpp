//link: https://neetcode.io/problems/validate-parentheses/question

/*

My Solution, uses ASCII values. 
) = ( + 1

but ] = [ + 2 
    } = { + 2

so, if we get a opening bracket, we push the closing of it to the stack.
If we encounter a closing bracket in the string, if it's closing one is on top of the stack and the stack is not empty (for corner case), then we pop. else return false
    as, the top of stack indicates which opening bracket was recent in the string.

Finally at last if we find the stack empty, return true. else false.

Another case: If no opening bracket was there in the string.
    So stack is empty. So we have to check if the stack is already empty, if we encounter the closing brackets.

*/

class Solution {
public:
    bool isValid(string s) {
        stack <char> end;

        for(char c: s){
            if (c == '(') end.push(c+1);
            else if (c=='{' || c=='[') end.push(c+2);
            else{
                if (!end.empty() && end.top() == c){
                    end.pop();
                }
                else return false;
            }
        }
        
        return end.empty();
    }
};

/*

More Readable. But uses hashmap. Scalable as we can add more things in the map.

*/

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stack;
        std::unordered_map<char, char> closeToOpen = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char c : s) {
            if (closeToOpen.count(c)) {
                if (!stack.empty() && stack.top() == closeToOpen[c]) {
                    stack.pop();
                } else {
                    return false;
                }
            } else {
                stack.push(c);
            }
        }
        return stack.empty();
    }
};