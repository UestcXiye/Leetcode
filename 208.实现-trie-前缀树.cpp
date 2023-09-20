/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 */

// @lc code=start

// 字典树（前缀树）

class TrieNode
{
public:
    TrieNode *childNode[26];
    bool isEnd; // 是否是一个单词的结尾
    TrieNode() : isEnd(false)
    {
        for (int i = 0; i < 26; i++)
            childNode[i] = nullptr;
    }
};

class Trie
{
private:
    TrieNode *root;

public:
    Trie() : root(new TrieNode())
    {
    }
    // 向字典树插入一个词
    void insert(string word)
    {
        TrieNode *node = root;
        for (char &c : word)
        {
            if (node->childNode[c - 'a'] == nullptr)
                node->childNode[c - 'a'] = new TrieNode();
            node = node->childNode[c - 'a'];
        }
        node->isEnd = true;
    }
    // 判断字典树里是否有一个词
    bool search(string word)
    {
        TrieNode *node = root;
        for (char &c : word)
        {
            if (node == nullptr)
                break;
            node = node->childNode[c - 'a'];
        }
        return node ? node->isEnd : false;
    }
    // 判断字典树是否有一个以词开始的前缀
    bool startsWith(string prefix)
    {
        TrieNode *node = root;
        for (char &c : prefix)
        {
            if (node == nullptr)
                break;
            node = node->childNode[c - 'a'];
        }
        return node != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
