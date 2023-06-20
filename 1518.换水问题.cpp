/*
 * @lc app=leetcode.cn id=1518 lang=cpp
 *
 * [1518] 换水问题
 */

// @lc code=start
class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int ans = numBottles;
        while (numBottles >= numExchange)
        {
            ans += numBottles / numExchange;
            numBottles = numBottles % numExchange + numBottles / numExchange;
        }
        return ans;
    }
};
// @lc code=end
