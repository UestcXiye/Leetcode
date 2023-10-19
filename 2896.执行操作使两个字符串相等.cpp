/*
 * @lc app=leetcode.cn id=2896 lang=cpp
 *
 * [2896] 执行操作使两个字符串相等
 */

// @lc code=start
class Solution
{
public:
    int minOperations(string s1, string s2, int x)
    {
        // 特判
        if (s1 == s2)
            return 0;
        if (count(s1.begin(), s1.end(), '1') % 2 != count(s2.begin(), s2.end(), '1') % 2)
            return -1;
        int n = s1.size();
        vector<int> pos;
        for (int i = 0; i < n; i++)
            if (s1[i] != s2[i])
                pos.push_back(i);
        int cur = pos.size() / 2 * x, pre = cur;
        for (int i = 1; i < pos.size(); i++)
        {
            int next = min(cur, pre + pos[i] - pos[i - 1] - x);
            pre = cur;
            cur = next;
        }
        return cur;
    }
};
// @lc code=end
