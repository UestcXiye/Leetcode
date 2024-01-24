/*
 * @lc app=leetcode.cn id=2381 lang=cpp
 *
 * [2381] 字母移位 II
 */

// @lc code=start
class Solution
{
public:
    string shiftingLetters(string s, vector<vector<int>> &shifts)
    {
        // 特判
        if (shifts.empty())
            return s;

        int n = s.length();
        // 构造差分数组
        vector<int> diff(n + 1, 0);
        for (vector<int> &shift : shifts)
        {
            int start = shift[0];
            int end = shift[1];
            int move = shift[2] ? 1 : -1;
            diff[start] += move;
            diff[end + 1] -= move;
        }

        int shift = 0;
        // 计算最终字符串
        for (int i = 0; i < n; i++)
        {
            shift += diff[i];
            s[i] = (char)((s[i] - 'a' + (shift % 26) + 26) % 26 + 'a');
        }
        return s;
    }
};
// @lc code=end
