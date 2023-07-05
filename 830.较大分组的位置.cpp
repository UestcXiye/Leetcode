/*
 * @lc app=leetcode.cn id=830 lang=cpp
 *
 * [830] 较大分组的位置
 */

// @lc code=start
class Solution
{
public:
    vector<vector<int>> largeGroupPositions(string s)
    {
        int n = s.size();
        int begin = 0, end = 1;
        vector<vector<int>> ans;
        while (begin < n)
        {
            while (s[begin] == s[end])
            {
                end++;
            }
            if (end - begin >= 3)
                ans.push_back({begin, end - 1});
            begin = end;
        }
        return ans;
    }
};
// @lc code=end
