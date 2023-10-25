/*
 * @lc app=leetcode.cn id=771 lang=cpp
 *
 * [771] 宝石与石头
 */

// @lc code=start
class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        unordered_set<char> jewelSet;
        for (const char &jewel : jewels)
            jewelSet.insert(jewel);
        int count = 0;
        for (const char &stone : stones)
            if (jewelSet.count(stone))
                count++;
        return count;
    }
};
// @lc code=end
