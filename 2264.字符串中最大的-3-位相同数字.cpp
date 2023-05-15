/*
 * @lc app=leetcode.cn id=2264 lang=cpp
 *
 * [2264] 字符串中最大的 3 位相同数字
 */

// @lc code=start
class Solution
{
public:
    string largestGoodInteger(string num)
    {
        int n = num.size();
        string ans = "";
        int max = -1;
        for (int i = 0; i <= n - 3; i++)
        {
            string temp = num.substr(i, 3);
            if (temp[0] == temp[1] && temp[1] == temp[2])
            {
                if (stoi(temp) > max)
                {
                    max = stoi(temp);
                    ans = temp;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
