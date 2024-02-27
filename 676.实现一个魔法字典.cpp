/*
 * @lc app=leetcode.cn id=676 lang=cpp
 *
 * [676] 实现一个魔法字典
 */

// @lc code=start
class MagicDictionary
{
private:
    vector<string> dict;

public:
    MagicDictionary() {}

    MagicDictionary(vector<string> dictionary) : dict(dictionary) {}

    void buildDict(vector<string> dictionary)
    {
        dict = dictionary;
    }

    bool search(string searchWord)
    {
        for (string &s : dict)
        {
            if (searchWord.length() != s.length())
                continue;

            int diff = 0;
            for (int i = 0; i < s.length(); i++)
                if (s[i] != searchWord[i])
                    diff++;

            if (diff == 1)
                return true;
        }

        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
// @lc code=end
