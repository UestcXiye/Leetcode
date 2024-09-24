/*
 * @lc app=leetcode.cn id=3291 lang=cpp
 *
 * [3291] 形成目标字符串需要的最少字符串数 I
 */

// @lc code=start

// 线段树

struct TrieNode
{
    TrieNode *child[26] = {nullptr};
};
class Trie
{
public:
    TrieNode *root;
    Trie() { root = new TrieNode(); }
    void insert(string &word)
    {
        TrieNode *node = root;
        for (char &c : word)
        {
            int index = c - 'a';
            if (node->child[index] == nullptr)
                node->child[index] = new TrieNode();
            node = node->child[index];
        }
    }
    vector<int> search(string &target, int pos)
    {
        TrieNode *node = root;
        vector<int> pres;
        for (int i = pos; i < target.size(); i++)
        {
            int index = target[i] - 'a';
            if (node->child[index] == nullptr)
                break;
            node = node->child[index];
            pres.push_back(i - pos + 1);
        }
        return pres;
    }
};

class Solution
{
public:
    int minValidStrings(vector<string> &words, string target)
    {
        Trie trie;
        // 将所有单词插入前缀树
        for (string &word : words)
            trie.insert(word);

        int n = target.size();
        vector<int> dp(n + 1, INT_MAX);
        // 初始化
        dp[0] = 0;
        // 状态转移
        for (int i = 0; i < n; i++)
        {
            if (dp[i] == INT_MAX)
                continue;
            vector<int> pres = trie.search(target, i);
            for (int len : pres)
                dp[i + len] = min(dp[i + len], dp[i] + 1);
        }

        return dp[n] == INT_MAX ? -1 : dp[n];
    }
};
// @lc code=end
