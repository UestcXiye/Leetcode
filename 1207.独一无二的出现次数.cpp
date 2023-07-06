/*
 * @lc app=leetcode.cn id=1207 lang=cpp
 *
 * [1207] 独一无二的出现次数
 */

// @lc code=start
class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> freq;
        for (int &x : arr)
            freq[x]++;
        unordered_set<int> times;
        for (const auto &f : freq)
            times.insert(f.second);
        return times.size() == freq.size();
    }
};
// @lc code=end
