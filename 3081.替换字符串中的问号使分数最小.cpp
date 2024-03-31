/*
 * @lc app=leetcode.cn id=3081 lang=cpp
 *
 * [3081] 替换字符串中的问号使分数最小
 */

// @lc code=start

// 贪心 + 优先队列

class Solution
{
public:
    string minimizeStringValue(string s)
    {
        vector<int> freq(26, 0);
        for (char &c : s)
            if (c != '?')
                freq[c - 'a']++;
        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<>> pq;
        for (int i = 0; i < 26; i++)
            pq.emplace(freq[i], i + 'a');

        int cnt = count(s.begin(), s.end(), '?');
        string tmp;
        for (int i = 0; i < cnt; i++)
        {
            auto [f, ch] = pq.top();
            pq.pop();
            tmp.push_back(ch);
            pq.emplace(f + 1, ch);
        }
        // 排序，因为要求字典序最小
        sort(tmp.begin(), tmp.end());
        for (int i = 0, j = 0; i < s.length(); i++)
            if (s[i] == '?')
                s[i] = tmp[j++];
        return s;
    }
};
// @lc code=end
