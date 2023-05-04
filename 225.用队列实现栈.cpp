/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
// class MyStack
// {
// public:
//     queue<int> q;
//     MyStack()
//     {
//     }

//     void push(int x)
//     {
//         q.push(x);
//     }

//     int pop()
//     {
//         int size = q.size();
//         for (int i = 0; i < size - 1; i++)
//         {
//             int v = q.front();
//             q.pop();
//             q.push(v);
//         }
//         int v = q.front();
//         q.pop();
//         return v;
//     }

//     int top()
//     {
//         return q.back();
//     }

//     bool empty()
//     {
//         return q.empty();
//     }
// };
class MyStack
{
public:
    queue<int> q1;
    queue<int> q2;
    MyStack()
    {
    }

    void push(int x)
    {
        if (!q1.empty())
            q1.push(x);
        else
            q2.push(x);
    }

    int pop()
    {
        if (!q1.empty())
        {
            while (q1.size() > 1)
            {
                int temp = q1.front();
                q2.push(temp);
                q1.pop();
            }
            int v = q1.front();
            q1.pop();
            return v;
        }
        else
        {
            while (q2.size() > 1)
            {
                int temp = q2.front();
                q1.push(temp);
                q2.pop();
            }
            int v = q2.front();
            q2.pop();
            return v;
        }
    }

    int top()
    {
        if (!q1.empty())
            return q1.back();
        else
            return q2.back();
    }

    bool empty()
    {
        return q1.empty() && q2.empty();
    }
};
/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
