/*
 * @lc app=leetcode.cn id=2283 lang=cpp
 *
 * [2283] 判断一个数的数字计数是否等于数位的值
 */

// @lc code=start
class Solution
{
public:
    bool digitCount(string num)
    {
        int n = num.size();
        for (int i = 0; i < n; i++)
        {
            int target = num[i] - '0';
            int count = 0;
            for (char c : num)
                if (c == i + '0')
                    count++;
            if (target != count)
                return false;
        }
        return true;
    }
};
// @lc code=end
