/*
 * @lc app=leetcode.cn id=3006 lang=cpp
 *
 * [3006] 找出数组中的美丽下标 I
 */

// @lc code=start
class Solution
{
public:
    vector<int> beautifulIndices(string s, string a, string b, int k)
    {
        // 特判
        if (s.empty() || a.empty() || b.empty() || k <= 0 || k > s.size())
            return {};
        if (s.length() < a.length() || s.length() < b.length())
            return {};

        int slen = s.size(), alen = a.size(), blen = b.size();
        vector<int> indices;
        for (int i = 0; i <= slen - alen; i++)
        {
            if (s.substr(i, alen) == a)
            {
                // 注意减小 j 的取值范围
                int start = max(0, i - k), end = min(slen, i + k);
                for (int j = start; j <= end; j++)
                    if (s.substr(j, blen) == b)
                    {
                        indices.push_back(i);
                        break;
                    }
            }
        }
        return indices;
    }
};
// @lc code=end
