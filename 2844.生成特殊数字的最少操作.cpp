/*
 * @lc app=leetcode.cn id=2844 lang=cpp
 *
 * [2844] 生成特殊数字的最少操作
 */

// @lc code=start
class Solution
{
public:
    int minimumOperations(string num)
    {
        int n = num.size();
        vector<int> count(10, 0);
        for (int i = n - 1; i >= 0; i--)
        {
            int digit = num[i] - '0';
            // 以00结尾
            if (count[0] == 2)
                return n - i - 3;
            // 以25/50/75结尾
            if ((digit == 2 && count[5]) || (digit == 5 && count[0]) || (digit == 7 && count[5]))
                return n - i - 2;
            count[digit]++;
        }
        // 删到只剩0
        return n - count[0];
    }
};
// @lc code=end
