/*
 * @lc app=leetcode.cn id=3039 lang=cpp
 *
 * [3039] 进行操作使字符串为空
 */

// @lc code=start

// 哈希 + 排序

class Solution
{
public:
    string lastNonEmptyString(string s)
    {
        if (s.empty())
            return "";

        vector<int> cnt(26, 0);        // 字符的出现次数
        vector<int> lastIndex(26, -1); // 字符的最后下标

        for (int i = 0; i < s.length(); i++)
        {
            char c = s[i];
            cnt[c - 'a']++;
            lastIndex[c - 'a'] = i;
        }

        int max_cnt = *max_element(cnt.begin(), cnt.end());
        vector<int> idx;

        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] == max_cnt)
                idx.push_back(lastIndex[i]);
        }
        sort(idx.begin(), idx.end());

        string ans(idx.size(), 0);
        for (int i = 0; i < idx.size(); i++)
            ans[i] = s[idx[i]];

        return ans;
    }
};
// @lc code=end
