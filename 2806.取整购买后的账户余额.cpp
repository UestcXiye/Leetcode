/*
 * @lc app=leetcode.cn id=2806 lang=cpp
 *
 * [2806] 取整购买后的账户余额
 */

// @lc code=start
// class Solution
// {
// public:
//     int accountBalanceAfterPurchase(int purchaseAmount)
//     {
//         int roundedAmount;

//         if (purchaseAmount % 10 < 5)
//             roundedAmount = purchaseAmount - purchaseAmount % 10;
//         else if (purchaseAmount % 10 > 5)
//             roundedAmount = purchaseAmount + 10 - purchaseAmount % 10;
//         else
//             roundedAmount = purchaseAmount + 5;

//         return 100 - roundedAmount;
//     }
// };

// one-line code

class Solution
{
public:
    int accountBalanceAfterPurchase(int purchaseAmount)
    {
        return 100 - (purchaseAmount + 5) / 10 * 10;
    }
};
// @lc code=end
