/*
 * @lc app=leetcode.cn id=946 lang=cpp
 *
 * [946] 验证栈序列
 */

// @lc code=start
class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        int j = 0;
        stack<int> s;
        for (int &in : pushed)
        {
            s.push(in);
            while (!s.empty() && popped[j] == s.top())
            {
                s.pop();
                j++;
            }
        }
        return s.empty();
    }
};
// @lc code=end
