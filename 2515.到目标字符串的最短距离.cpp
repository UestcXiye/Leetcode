/*
 * @lc app=leetcode.cn id=2515 lang=cpp
 *
 * [2515] 到目标字符串的最短距离
 */

// @lc code=start
class Solution
{
public:
    int closetTarget(vector<string> &words, string target, int startIndex)
    {
        int len = words.size();
        vector<int> indexs;
        for (int i = 0; i < len; i++)
            if (words[i] == target)
                indexs.push_back(i);
        if (indexs.empty())
            return -1;
        int ans = __INT_MAX__;
        for (int index : indexs)
        {
            int distance = min(abs(startIndex - index), len - abs(startIndex - index));
            ans = min(distance, ans);
        }
        return ans;
    }
};
// @lc code=end
