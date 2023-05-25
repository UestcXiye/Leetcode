/*
 * @lc app=leetcode.cn id=1796 lang=cpp
 *
 * [1796] 字符串中第二大的数字
 */

// @lc code=start
class Solution
{
public:
    int secondHighest(string s)
    {
        set<int> set;
        for (char c : s)
        {
            if (isdigit(c))
                set.insert(c - '0');
        }
        if (set.size() <= 1)
            return -1;
        else
        {
            vector<int> v(set.begin(),set.end());
            // sort(v.begin(), v.end());
            return v[v.size() - 2];
        }
    }
};
// @lc code=end
