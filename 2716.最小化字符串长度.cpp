/*
 * @lc app=leetcode.cn id=2716 lang=cpp
 *
 * [2716] 最小化字符串长度
 */

// @lc code=start
class Solution
{
public:
    int minimizedStringLength(string s)
    {
        unordered_map<char, int> umap;
        for (char &c : s)
            umap[c]++;
        return umap.size();
    }
};
// @lc code=end
