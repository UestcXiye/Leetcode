/*
 * @lc app=leetcode.cn id=767 lang=cpp
 *
 * [767] 重构字符串
 */

// @lc code=start
class Solution
{
private:
    static bool cmp(const pair<char, int> &p1, const pair<char, int> &p2)
    {
        return p1.second > p2.second;
    }

public:
    string reorganizeString(string s)
    {
        unordered_map<char, int> hash;
        int max_freq = 0;
        for (const char &c : s)
        {
            hash[c]++;
            max_freq = max(max_freq, hash[c]);
        }
        int n = s.size();
        // 特判
        if (max_freq > (n + 1) / 2)
            return "";
        vector<pair<char, int>> alpha(hash.begin(), hash.end());
        sort(alpha.begin(), alpha.end(), cmp);
        int index = 0;
        string ans(n, 0);
        for (int i = 0; i < alpha.size(); i++)
        {
            while (alpha[i].second > 0)
            {
                ans[index] = alpha[i].first;
                alpha[i].second--;
                index += 2;
                if (index >= n)
                    index = 1;
            }
        }
        return ans;
    }
};
// @lc code=end
