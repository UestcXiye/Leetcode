/*
 * @lc app=leetcode.cn id=2591 lang=cpp
 *
 * [2591] 将钱分给最多的儿童
 */

// @lc code=start
class Solution
{
public:
    int distMoney(int money, int children)
    {
        money -= children;
        if (money < 0)
            return -1;
        if (money > 7 * children)
            return children - 1;
        if (money == 7 * children)
            return children;
        if (money == 7 * children - 4)
            return children - 2;
        return money / 7;
    }
};
// @lc code=end
