/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack
{
private:
    stack<int> s, minStack; // 额外建立一个新栈，栈顶表示原栈里所有值的最小值

public:
    MinStack()
    {
    }

    void push(int val)
    {
        s.push(val);
        // 每当在原栈里插入一个数字时，若该数字小于等于新栈栈顶，
        // 则表示这个数字在原栈里是最小值，我们将其同时插入新栈内
        if (minStack.empty() || val < minStack.top())
            minStack.push(val);
    }

    void pop()
    {
        int x = s.top();
        s.pop();
        // 每当从原栈里取出一个数字时，若该数字等于新栈栈顶，
        // 则表示这个数是原栈里的最小值之一，我们同时取出新栈栈顶的值
        if (!minStack.empty() && minStack.top() == x)
            minStack.pop();
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
