/*
 * @lc app=leetcode.cn id=2243 lang=cpp
 *
 * [2243] 计算字符串的数字和
 */

// @lc code=start
class Solution
{
public:
    string digitSum(string s, int k)
    {
        while (s.size() > k)
        {
            string str;
            // int n = s.size();
            // int count;
            // if (n % k == 0)
            //     count = n / k;
            // else
            //     count = n / k + 1;
            int count = (s.size() % k == 0) ? s.size() / k : s.size() / k + 1;
            for (int i = 0; i < count; i++)
            {
                string temp = s.substr(i * k, k);
                int sum = 0;
                for (char c : temp)
                    sum += c - '0';
                str.append(to_string(sum));
            }
            s = str;
        }
        return s;
    }
};
// @lc code=end
