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
        unordered_map<char, int> cnt;
        for (char &c : s)
            cnt[c]++;
        vector<pair<char, int>> vp;
        for (auto &[ch, freq] : cnt)
            vp.push_back(make_pair(ch, freq));
        sort(vp.begin(), vp.end(), [&](const auto &p1, const auto &p2)
             { return p1.second > p2.second; });
        string ans;
        for (auto &p : vp)
        {
            for (int i = 0; i < p.second; i++)
                ans.push_back(p.first);
        }
        return ans;
    }
};
// @lc code=end
