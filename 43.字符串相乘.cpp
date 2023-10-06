/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 */

// @lc code=start
class Solution
{
public:
    string multiply(string num1, string num2)
    {
        // 特判
        if (num1 == "0" || num2 == "0")
            return "0";
        int m = num1.size(), n = num2.size();
        vector<int> ansArr(m + n, 0);
        for (int i = m - 1; i >= 0; i--)
        {
            int x = num1[i] - '0';
            for (int j = n - 1; j >= 0; j--)
            {
                int y = num2[j] - '0';
                ansArr[i + j + 1] += x * y;
            }
        }
        for (int i = m + n - 1; i > 0; i--)
        {
            ansArr[i - 1] += ansArr[i] / 10;
            ansArr[i] %= 10;
        }
        int index = ansArr[0] == 0 ? 1 : 0;
        string ans;
        while (index < m + n)
        {
            ans.push_back(ansArr[index] + '0');
            index++;
        }
        return ans;
    }
};
// @lc code=end
