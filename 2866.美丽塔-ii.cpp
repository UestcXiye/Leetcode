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
        int n = maxHeights.size();
        vector<long long> suffix(n + 1, 0);
        vector<long long> prev(n + 1, 0);
        stack<int> s;
        // 单调栈求前缀
        for (int i = 0; i < n; i++)
        {
            // 弹出栈顶
            while (!s.empty() && maxHeights[s.top()] > maxHeights[i])
                s.pop();
            int j = s.empty() ? -1 : s.top();
            prev[i + 1] = prev[j + 1] + (long long)(i - j) * maxHeights[i];
            s.push(i);
        }
        // 清空栈
        while (!s.empty())
            s.pop();
        // 单调栈求后缀
        for (int i = n - 1; i >= 0; i--)
        {
            // 弹出栈顶
            while (!s.empty() && maxHeights[s.top()] > maxHeights[i])
                s.pop();
            int j = s.empty() ? n : s.top();
            suffix[i] = suffix[j] + (long long)(j - i) * maxHeights[i];
            s.push(i);
        }
        // 合并
        long long max_sum = 0;
        for (int i = 0; i < n; i++)
            max_sum = max(max_sum, prev[i + 1] + suffix[i] - maxHeights[i]);
        return max_sum;
    }
};
// @lc code=end
