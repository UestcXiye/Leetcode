/*
 * @lc app=leetcode.cn id=1002 lang=cpp
 *
 * [1002] 查找共用字符
 */

// @lc code=start
class Solution
{
public:
    vector<string> commonChars(vector<string> &words)
    {
        vector<string> ans;
        int hash[26] = {0};
        for (char c : words[0])
            hash[c - 'a']++;
        int hashOther[26] = {0};
        for (int i = 1; i < words.size(); i++)
        {
            memset(hashOther, 0, 26 * sizeof(int));
            for (char c : words[i])
                hashOther[c - 'a']++;
            for (int j = 0; j < 26; j++)
                hash[j] = min(hash[j], hashOther[j]);
        }
        for (int i = 0; i < 26; i++)
            while (hash[i]--)
                ans.push_back(string(1, i + 'a'));
        return ans;
    }
};
// @lc code=end
