/*
 * @lc app=leetcode.cn id=2707 lang=cpp
 *
 * [2707] 字符串中的额外字符
 */

// @lc code=start

// 动态规划

// class Solution
// {
// public:
//     int minExtraChar(string s, vector<string> &dictionary)
//     {
//         int n = s.length();
//         // dp[i] 是 s[0,...,i] 中额外字符的最小值
//         vector<int> dp(n + 1, INT_MAX);
//         // 初始化
//         dp[0] = 0;

//         // 建哈希表
//         unordered_map<string, int> hash;
//         for (string &dic : dictionary)
//             hash[dic]++;

//         // 状态转移
//         for (int i = 1; i <= n; i++)
//         {
//             // 将 s[i-1] 视为额外的字符，额外字符数 +1
//             dp[i] = dp[i - 1] + 1;
//             for (int j = i - 1; j >= 0; j--)
//             {
//                 string temp = s.substr(j, i - j);
//                 if (hash.count(temp))
//                 {
//                     // 状态转移方程
//                     dp[i] = min(dp[i], dp[j]);
//                 }
//             }
//         }
//         return dp[n];
//     }
// };

// 字典树优化

class Trie
{
private:
    vector<Trie *> children;
    bool isEnd;

public:
    Trie() : children(26), isEnd(false) {}

    void insert(string word)
    {
        Trie *node = this;
        for (char ch : word)
        {
            ch -= 'a';
            if (node->children[ch] == nullptr)
            {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->isEnd = true;
    }

    bool track(Trie *&node, char ch)
    {
        if (node == nullptr || node->children[ch - 'a'] == nullptr)
        {
            node = nullptr;
            return false;
        }
        node = node->children[ch - 'a'];
        return node->isEnd;
    }
};

class Solution
{
public:
    int minExtraChar(string s, vector<string> &dictionary)
    {
        int n = s.size();
        vector<int> d(n + 1, INT_MAX);
        Trie trie;
        for (auto s : dictionary)
        {
            reverse(s.begin(), s.end());
            trie.insert(s);
        }
        d[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            d[i] = d[i - 1] + 1;
            Trie *node = &trie;
            for (int j = i - 1; j >= 0; j--)
            {
                if (trie.track(node, s[j]))
                {
                    d[i] = min(d[i], d[j]);
                }
            }
        }
        return d[n];
    }
};

// @lc code=end
