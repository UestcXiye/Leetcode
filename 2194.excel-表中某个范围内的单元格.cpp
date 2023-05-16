/*
 * @lc app=leetcode.cn id=2194 lang=cpp
 *
 * [2194] Excel 表中某个范围内的单元格
 */

// @lc code=start
class Solution
{
public:
    vector<string> cellsInRange(string s)
    {
        char beginCol = s[0], beginRow = s[1];
        char endCol = s[3], endRow = s[4];
        vector<string> ans;
        for (char i = beginCol; i <= endCol; i++)
            for (char j = beginRow; j <= endRow; j++)
            {
                string temp;
                temp += i;
                temp += j;
                ans.push_back(temp);
            }
        return ans;
    }
};
// @lc code=end
