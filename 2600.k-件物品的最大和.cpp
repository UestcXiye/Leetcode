/*
 * @lc app=leetcode.cn id=2600 lang=cpp
 *
 * [2600] K 件物品的最大和
 */

// @lc code=start
class Solution
{
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k)
    {
        int sum = 0;
        while (k)
        {
            while (numOnes && k)
            {
                sum++;
                numOnes--;
                k--;
            }
            while (numZeros && k)
            {
                numZeros--;
                k--;
            }
            while (numNegOnes && k)
            {
                sum--;
                k--;
            }
        }
        return sum;
    }
};
// @lc code=end
