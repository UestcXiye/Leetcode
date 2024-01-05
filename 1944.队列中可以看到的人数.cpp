/*
 * @lc app=leetcode.cn id=1944 lang=cpp
 *
 * [1944] 队列中可以看到的人数
 */

// @lc code=start
class Solution
{
public:
    vector<int> canSeePersonsCount(vector<int> &heights)
    {
        // 特判
        if (heights.empty())
            return {};

        stack<int> stk;
        int n = heights.size();
        vector<int> ans(n, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            int count = 0;
            while (!stk.empty() && stk.top() < heights[i])
            {
                stk.pop();
                count++;
            }
            if (!stk.empty())
                count++;
            stk.push(heights[i]);
            ans[i] = count;
        }
        return ans;
    }
};
// @lc code=end
