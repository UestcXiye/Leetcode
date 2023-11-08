/*
 * @lc app=leetcode.cn id=2917 lang=cpp
 *
 * [2917] 找出数组中的 K-or 值
 */

// @lc code=start
class Solution
{
public:
    int findKOr(vector<int> &nums, int k)
    {
        int k_or = 0;
        for (int i = 0; i < 32; i++)
        {
            int count = 0;
            for (const int &num : nums)
                if (num & (1 << i))
                    count++;
            if (count >= k)
                k_or += (1 << i);
        }
        return k_or;
    }
};
// @lc code=end
