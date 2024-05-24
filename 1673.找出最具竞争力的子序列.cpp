/*
 * @lc app=leetcode.cn id=1673 lang=cpp
 *
 * [1673] 找出最具竞争力的子序列
 */

// @lc code=start
class Solution
{
public:
    vector<int> mostCompetitive(vector<int> &nums, int k)
    {
        int n = nums.size();

        stack<int> stk;
        for (int i = 0; i < n; i++)
        {
            int x = nums[i];
            while (!stk.empty() && x < stk.top() && stk.size() + n - i > k)
                stk.pop();
            if (stk.size() < k)
                stk.push(x);
        }

        vector<int> ans(stk.size());
        for (int i = stk.size() - 1; i >= 0; i--)
        {
            ans[i] = stk.top();
            stk.pop();
        }
        return ans;
    }
};
// @lc code=end
