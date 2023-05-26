/*
 * @lc app=leetcode.cn id=1773 lang=cpp
 *
 * [1773] 统计匹配检索规则的物品数量
 */

// @lc code=start
class Solution
{
public:
    int countMatches(vector<vector<string>> &items, string ruleKey, string ruleValue)
    {
        int index = 0;
        if (ruleKey == "type")
            index = 0;
        else if (ruleKey == "color")
            index = 1;
        else
            index = 2;
        int count = 0;
        for (vector<string> &item : items)
        {
            if (item[index] == ruleValue)
                count++;
        }
        return count;
    }
};
// @lc code=end
