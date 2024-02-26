/*
 * @lc app=leetcode.cn id=3045 lang=cpp
 *
 * [3045] 统计前后缀下标对 II
 */

// @lc code=start

// 字典树

class Solution
{
public:
    struct Trie
    {
        unordered_map<int, Trie *> childs;
        int cnt = 0;
    };
    Trie *trie = new Trie();
    void add(const string &s)
    {
        Trie *cur = trie;
        int n = s.size();
        for (int i = 0, j = n - 1; i < n; ++i, --j)
        {
            int idx = (s[i] - 'a') * 26 + (s[j] - 'a');
            if (!cur->childs.count(idx))
            {
                cur->childs[idx] = new Trie();
            }
            cur = cur->childs[idx];
            cur->cnt += 1;
        }
    }
    int query(const string &s)
    {
        Trie *cur = trie;
        int n = s.size();
        for (int i = 0, j = n - 1; i < n; ++i, --j)
        {
            int idx = (s[i] - 'a') * 26 + (s[j] - 'a');
            if (!cur->childs.count(idx))
                return 0;
            cur = cur->childs[idx];
        }
        return cur->cnt;
    }
    long long countPrefixSuffixPairs(vector<string> &words)
    {
        int n = words.size();
        long long ans = 0;
        // 字符串对需要满足 i < j，所以从右往左遍历数组 words
        for (int i = n - 1; i >= 0; --i)
        {
            ans += query(words[i]);
            add(words[i]);
        }
        return ans;
    }
};
// @lc code=end
