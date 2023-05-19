/*
 * @lc app=leetcode.cn id=1945 lang=cpp
 *
 * [1945] 字符串转化后的各位数字之和
 */

// @lc code=start
class Solution
{
public:
    int getLucky(string s, int k)
    {
        string trans;
        for (char c : s)
            trans.append(to_string((int)c - 'a' + 1));
        while (k--)
        {
            int temp = 0;
            for (char c : trans)
                temp += (int)c - '0';
            trans = to_string(temp);
        }
        return stoi(trans);
    }
};
// @lc code=end
