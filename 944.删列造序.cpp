/*
 * @lc app=leetcode.cn id=944 lang=cpp
 *
 * [944] 删列造序
 */

// @lc code=start
class Solution
{
public:
    int minDeletionSize(vector<string> &strs)
    {
        int row = strs.size(), col = strs[0].length();
        int count = 0;
        for (int j = 0; j < col; j++)
            for (int i = 1; i < row; i++)
            {
                if (strs[i][j] < strs[i - 1][j])
                {
                    count++;
                    break;
                }
            }
        return count;
    }
};
// @lc code=end
