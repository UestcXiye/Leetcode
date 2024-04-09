/*
 * @lc app=leetcode.cn id=3100 lang=cpp
 *
 * [3100] 换水问题 II
 */

// @lc code=start
class Solution
{
public:
    int maxBottlesDrunk(int numBottles, int numExchange)
    {
        // 一开始，把所有的满水瓶都喝掉
        int bottlesDrunk = numBottles; // 喝了多少瓶水
        int emptyBottles = numBottles; // 空水瓶数
        while (emptyBottles >= numExchange)
        {
            // 用 numExchange 个空水瓶交换一个满水瓶
            emptyBottles -= numExchange;
            // 然后，将 numExchange 的值增加 1
            numExchange++;
            // 喝掉换的满水瓶
            bottlesDrunk++;
            emptyBottles++;
        }
        return bottlesDrunk;
    }
};
// @lc code=end
