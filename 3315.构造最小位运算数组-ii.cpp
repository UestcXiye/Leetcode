/*
 * @lc app=leetcode.cn id=3315 lang=cpp
 *
 * [3315] 构造最小位运算数组 II
 */

// @lc code=start
class Solution
{
public:
    vector<int> minBitwiseArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 2)
                ans[i] = -1;
            else
            {
                // 求从最低位开始的连续 1
                int p = 0;
                while (nums[i] >> p & 0x1)
                    p++;
                // 把连续 1 的最后一位变成 0
                ans[i] = nums[i] ^ (1 << (p - 1));
            }
        }

        return ans;
    }
};
// @lc code=end
