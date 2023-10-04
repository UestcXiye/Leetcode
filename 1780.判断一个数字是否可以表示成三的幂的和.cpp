/*
 * @lc app=leetcode.cn id=1780 lang=cpp
 *
 * [1780] 判断一个数字是否可以表示成三的幂的和
 */

// @lc code=start
class Solution
{
public:
    bool checkPowersOfThree(int n)
    {
        // 若干3的幂之和，也就是转化为3进制后，每一位必须是0或1，出现2的话返回false
        while (n > 0)
        {
            if (n % 3 != 0 && n % 3 != 1)
                return false;
            n /= 3;
        }
        return true;
    }
};
// @lc code=end
