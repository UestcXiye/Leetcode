/*
 * @lc app=leetcode.cn id=3270 lang=cpp
 *
 * [3270] 求出数字答案
 */

// @lc code=start
class Solution
{
public:
    int generateKey(int num1, int num2, int num3)
    {
        string s1 = trans(num1);
        string s2 = trans(num2);
        string s3 = trans(num3);

        string s = "";
        for (int i = 0; i < 4; i++)
            s += min(s1[i], min(s2[i], s3[i]));
        return stoi(s);
    }
    // 辅函数
    string trans(int x)
    {
        string s = to_string(x);
        int n = s.length();
        for (int i = 0; i < 4 - n; i++)
            s.insert(s.begin(), '0');
        return s;
    }
};
// @lc code=end
