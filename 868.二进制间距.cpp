/*
 * @lc app=leetcode.cn id=868 lang=cpp
 *
 * [868] 二进制间距
 */

// @lc code=start
class Solution
{
public:
    int binaryGap(int n)
    {
        int maxGap = 0, last = INT_MAX;
        for (int i = 0; i < 32; i++)
        {
            if (n & (1 << i))
            {
                maxGap = max(maxGap, i - last);
                last = i;
            }
        }
        return maxGap;
    }
};
// @lc code=end
