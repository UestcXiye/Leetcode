/*
 * @lc app=leetcode.cn id=1952 lang=cpp
 *
 * [1952] 三除数
 */

// @lc code=start
class Solution
{
public:
    bool isThree(int n)
    {
        int count = 0;
        for (int i = 1; i <= n; i++)
            if (n % i == 0)
                count++;
        return count == 3;
    }
};
// @lc code=end
