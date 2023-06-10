/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
class Solution
{
public:
    string frequencySort(string s)
    {
        unordered_map<char, int> counts;
        int maxCount = 0;
        for (const char &c : s)
        {
            counts[c]++;
            maxCount = max(maxCount, counts[c]);
        }
        vector<vector<char>> buckets(maxCount + 1);
        for (const auto &p : counts)
            buckets[p.second].push_back(p.first);
        string ans;
        for (int i = maxCount; i > 0; i--)
        {
            int count = i;
            for (const char &c : buckets[i])
                for (int j = 0; j < count; j++)
                    ans += c;
        }
        return ans;
    }
};
// @lc code=end
