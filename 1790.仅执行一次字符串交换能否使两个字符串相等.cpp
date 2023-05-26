/*
 * @lc app=leetcode.cn id=1790 lang=cpp
 *
 * [1790] 仅执行一次字符串交换能否使两个字符串相等
 */

// @lc code=start
class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        if (s1 == s2)
            return true;
        int n = s1.size();
        vector<int> index;
        for (int i = 0; i < n; i++)
        {
            if (s1[i] != s2[i])
                index.push_back(i);
        }
        if (index.size() != 2)
            return false;
        swap(s1[index[0]], s1[index[1]]);
        return s1 == s2;
    }
};
// @lc code=end
