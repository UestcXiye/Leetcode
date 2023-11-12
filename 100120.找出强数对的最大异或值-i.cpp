/*
 * @lc app=leetcode.cn id=100120 lang=cpp
 *
 * [100120] 找出强数对的最大异或值 I
 */

// @lc code=start
class Solution
{
public:
    int maximumStrongPairXor(vector<int> &nums)
    {
        int ans = INT_MIN;
        for (const int &x : nums)
            for (const int &y : nums)
            {
                if (abs(x - y) <= min(x, y))
                    ans = max(ans, x ^ y);
            }
        return ans;
    }
};
// @lc code=end
