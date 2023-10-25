/*
 * @lc app=leetcode.cn id=2698 lang=cpp
 *
 * [2698] 求一个整数的惩罚数
 */

// @lc code=start
class Solution
{
public:
    int punishmentNumber(int n)
    {
        int punishment_number = 0;
        for (int i = 0; i <= n; i++)
        {
            string s = to_string(i * i);
            if (dfs(s, 0, 0, i))
                punishment_number += i * i;
        }
        return punishment_number;
    }
    // 辅函数 - 判断字符串能否分割成若干连续子字符串，且这些子字符串对应的整数值之和等于 target
    bool dfs(const string &s, int pos, int sum, const int target)
    {
        if (pos == s.size())
            return sum == target;
        int total = 0;
        for (int i = pos; i < s.size(); i++)
        {
            total = 10 * total + s[i] - '0';
            if (sum + total > target)
                break;
            if (dfs(s, i + 1, sum + total, target))
                return true;
        }
        return false;
    }
};
// @lc code=end
