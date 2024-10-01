/*
 * @lc app=leetcode.cn id=3295 lang=cpp
 *
 * [3295] 举报垃圾信息
 */

// @lc code=start
class Solution
{
public:
    bool reportSpam(vector<string> &message, vector<string> &bannedWords)
    {
        unordered_set<string> hashSet(bannedWords.begin(), bannedWords.end());
        int count = 0;
        for (string &mes : message)
            if (hashSet.contains(mes))
                count++;
        return count >= 2;
    }
};
// @lc code=end
