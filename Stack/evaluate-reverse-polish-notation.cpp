//link: https://neetcode.io/problems/evaluate-reverse-polish-notation/question

/*

for iterating the String, we used 
    const string& token : tokens
instead of
    string token : tokens
as it directly gets the strings, no need of copying. Adding the 'const' part also makes it impossible to change the original vector (as we don't need to).


The solution is quite simple:
1. If a operator is found:
    - get the topmost 2 integers, calculate the result
    - push the result to the stack
2. If a operand is found,
    - simply push the operand in the stack.
3. Result is the top of the stack at the end.

*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (const string& token : tokens) {
            if (token == "+" || token == "-" ||
                token == "*" || token == "/") {

                int b = st.top(); st.pop();
                int a = st.top(); st.pop();

                if (token == "+") st.push(a + b);
                else if (token == "-") st.push(a - b);
                else if (token == "*") st.push(a * b);
                else st.push(a / b);
            }
            else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};