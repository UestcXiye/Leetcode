/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */

// @lc code=start
class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        sort(citations.begin(), citations.end());
        int h_index = 0, i = citations.size() - 1;
        while (i >= 0 && citations[i] >= h_index + 1)
        {
            i--;
            h_index++;
        }
        return h_index;
    }
};
// @lc code=end
