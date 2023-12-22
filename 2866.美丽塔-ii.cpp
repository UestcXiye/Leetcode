/*
 * @lc app=leetcode.cn id=2866 lang=cpp
 *
 * [2866] 美丽塔 II
 */

// @lc code=start
class Solution
{
public:
    long long maximumSumOfHeights(vector<int> &maxHeights)
    {
        if (maxHeights.empty())
            return 0;
        int n = maxHeights.size();
        vector<long long> prev(n + 1, 0);
        vector<long long> suffix(n + 1, 0);
        stack<int> stk;
        // 单调栈求前缀
        for (int i = 0; i < n; i++)
        {
            // maxHeights[i] 小于等于栈顶元素值
            while (!stk.empty() && maxHeights[i] < maxHeights[stk.top()])
            {
                // 不断弹出栈顶
                stk.pop();
            }
            // 假设现在栈顶下标是 j
            int j = stk.empty() ? -1 : stk.top();
            // 从 maxHeights[j] 到 maxHeights[i−1] 都必须是 maxHeights[i]
            prev[i + 1] = prev[j + 1] + (long long)(i - j) * maxHeights[i];
            stk.push(i);
        }
        // 清空栈
        while (!stk.empty())
            stk.pop();
        // 单调栈求后缀
        for (int i = n - 1; i >= 0; i--)
        {
            // maxHeights[i] 小于等于栈顶元素值
            while (!stk.empty() && maxHeights[i] < maxHeights[stk.top()])
            {
                // 不断弹出栈顶
                stk.pop();
            }
            // 假设现在栈顶下标是 j
            int j = stk.empty() ? n : stk.top();
            // 从 maxHeights[i] 到 maxHeights[j−1] 都必须是 maxHeights[i]
            suffix[i] = suffix[j] + (long long)(j - i) * maxHeights[i];
            stk.push(i);
        }
        // 合并
        long long max_sum = 0;
        for (int i = 0; i < n; i++)
            max_sum = max(max_sum, prev[i + 1] + suffix[i] - maxHeights[i]);
        return max_sum;
    }
};
// @lc code=end
