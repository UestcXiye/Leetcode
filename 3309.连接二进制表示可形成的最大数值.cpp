/*
 * @lc app=leetcode.cn id=3309 lang=cpp
 *
 * [3309] 连接二进制表示可形成的最大数值
 */

// @lc code=start
class Solution
{
public:
    int maxGoodNumber(vector<int> &nums)
    {
        int a = nums[0];
        int b = nums[1];
        int c = nums[2];
        return max({getNum(a, b, c), getNum(a, c, b), getNum(b, a, c),
                    getNum(b, c, a), getNum(c, a, b), getNum(c, b, a)});
    }
    // 辅函数 - 求 a、b、c 的连接数值
    int getNum(int a, int b, int c)
    {
        string s = trans(a) + trans(b) + trans(c);
        ranges::reverse(s);
        int res = 0;
        for (int i = 0; i < s.length(); i++)
            res += (s[i] - '0') * (int)pow(2, i);
        return res;
    }
    // 辅函数 - 转换成二进制表示
    string trans(int x)
    {
        string s;
        while (x)
        {
            s.insert(s.begin(), x % 2 + '0');
            x /= 2;
        }
        return s;
    }
};
// @lc code=end
