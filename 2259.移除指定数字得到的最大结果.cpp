/*
 * @lc app=leetcode.cn id=2259 lang=cpp
 *
 * [2259] 移除指定数字得到的最大结果
 */

// @lc code=start
class Solution
{
public:
    string removeDigit(string number, char digit)
    {
        string ans;
        int n = number.size();

        for (int i = 0; i < n; i++)
        {
            if (number[i] == digit)
            {
                string temp;
                for (int j = 0; j < n; j++)
                {
                    if (j != i)
                        temp += number[j];
                }
                // for (int j = 0; j < i; j++)
                //     temp += number[j];
                // for (int j = i + 1; j < n; j++)
                //     temp += number[j];
                
                // string temp = number.substr(0, i);
                // temp.append(number.substr(i + 1, n - i));
                ans = max(ans, temp);
            }
        }
        return ans;
    }
};
// @lc code=end
