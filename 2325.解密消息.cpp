/*
 * @lc app=leetcode.cn id=2325 lang=cpp
 *
 * [2325] 解密消息
 */

// @lc code=start
class Solution
{
public:
    string decodeMessage(string key, string message)
    {
        unordered_map<char, char> umap;
        char currentKey = 'a';
        for (char c : key)
            if (islower(c) && !umap.count(c))
            {
                umap[c] = currentKey;
                currentKey++;
            }
        for (int i = 0; i < message.size(); i++)
            if (islower(message[i]))
                message[i] = umap[message[i]];
        return message;
    }
};
// @lc code=end
