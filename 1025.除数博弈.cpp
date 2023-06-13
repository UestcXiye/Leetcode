/*
 * @lc app=leetcode.cn id=1025 lang=cpp
 *
 * [1025] 除数博弈
 */

// @lc code=start
class Solution
{
public:
    bool divisorGame(int n)
    {
        if (n % 2)
            return false;
        else
            return true;
    }
};
// @lc code=end
