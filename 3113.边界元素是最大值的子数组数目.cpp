/*
 * @lc app=leetcode.cn id=3113 lang=cpp
 *
 * [3113] 边界元素是最大值的子数组数目
 */

// @lc code=start
class Solution
{
public:
    long long numberOfSubarrays(vector<int> &nums)
    {
        long long ans = 0LL;
        ans += nums.size(); // 每个单独的元素都是边界元素是最大值的子数组
        stack<pair<int, int>> stk;
        // 无穷大哨兵，不可能被弹出栈
        stk.push(make_pair(INT_MAX, 0));
        // 遍历
        for (int &x : nums)
        {
            // 比 x 小的元素都不可能构成边界
            while (x > stk.top().first)
                stk.pop();
            if (x == stk.top().first)
            {
                ans += stk.top().second;
                stk.top().second++;
            }
            else
                stk.push(make_pair(x, 1));
        }
        return ans;
    }
};
// @lc code=end
