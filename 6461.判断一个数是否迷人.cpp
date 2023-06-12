/*
 * @lc app=leetcode.cn id=6461 lang=cpp
 *
 * [6461] 判断一个数是否迷人
 */

// @lc code=start
class Solution
{
public:
    bool isFascinating(int n)
    {
        if (n < 123 || n > 329)
            return false;
        int mask = 0;
        for (char &c : to_string(n) + to_string(2 * n) + to_string(3 * n))
            mask |= 1 << (c - '0');
        return mask == (1 << 10) - 2;
    }
};
// @lc code=end
