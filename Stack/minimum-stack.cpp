//link: https://neetcode.io/problems/minimum-stack/question

/*

To find the min of the stack, used two stacks. 
if we delete the top of a stack, the min value maybe deleted too.

    Stack       MinStack
      4         -2
      2         -2
      -2        -2  
      1         1   
      5         2
      2         2

In the minStack we keep the min till now of the stack.
*/

class MinStack {
private:
    stack <int> Stack;
    stack <int> minStack;

public:
    MinStack() {}
    
    void push(int val) {
        Stack.push(val);
        val = min(val, minStack.empty() ? val : minStack.top());
        minStack.push(val);
    }
    
    void pop() {
        Stack.pop();
        minStack.pop();
    }
    
    int top() {
        return Stack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
