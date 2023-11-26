/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 */

// @lc code=start
struct TrieNode
{
    vector<TrieNode *> child;
    bool isEnd;
    TrieNode() : child(vector<TrieNode *>(26, nullptr)), isEnd(false) {}
};

void insert(TrieNode *root, const string &word)
{
    TrieNode *node = root;
    for (const char &c : word)
    {
        if (node->child[c - 'a'] == nullptr)
            node->child[c - 'a'] = new TrieNode();
        node = node->child[c - 'a'];
    }
    node->isEnd = true;
}

class WordDictionary
{
private:
    TrieNode *trie;

public:
    WordDictionary() : trie(new TrieNode()) {}

    void addWord(string word)
    {
        insert(trie, word);
    }

    bool search(string word)
    {
        return dfs(word, 0, trie);
    }

    bool dfs(const string &word, int index, TrieNode *node)
    {
        if (index == word.size())
            return node->isEnd;
        char ch = word[index];
        if (ch >= 'a' && ch <= 'z')
        {
            TrieNode *child = node->child[ch - 'a'];
            if (child != nullptr && dfs(word, index + 1, child))
                return true;
        }
        else if (ch == '.')
        {
            for (int i = 0; i < 26; i++)
            {
                TrieNode *child = node->child[i];
                if (child != nullptr && dfs(word, index + 1, child))
                    return true;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end
