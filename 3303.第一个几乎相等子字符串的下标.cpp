/*
 * @lc app=leetcode.cn id=3303 lang=cpp
 *
 * [3303] 第一个几乎相等子字符串的下标
 */

// @lc code=start
class Solution
{
public:
    int minStartingIndex(string s, string pattern)
    {
        int n = s.length(), m = pattern.length();
        string rev_s = string(s.rbegin(), s.rend());
        string rev_pattern = string(pattern.rbegin(), pattern.rend());
        vector<int> preZ = getZ(pattern + s);
        vector<int> sufZ = getZ(rev_pattern + rev_s);
        reverse(sufZ.begin(), sufZ.end());
        for (int i = 0; i <= n - m; i++)
            if (preZ[i + m] + sufZ[i + m - 1] >= m - 1)
                return i;
        return -1;
    }
    // 辅函数
    vector<int> getZ(string s)
    {
        int n = s.length();
        vector<int> z(n);
        int box_l = 0, box_r = 0; // z-box 左右边界
        for (int i = 1; i < n; i++)
        {
            if (i <= box_r)
                z[i] = min(z[i - box_l], box_r - i + 1);
            while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            {
                box_l = i;
                box_r = i + z[i];
                z[i]++;
            }
        }
        return z;
    }
};
// @lc code=end
