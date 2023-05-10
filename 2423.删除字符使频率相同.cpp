/*
 * @lc app=leetcode.cn id=2423 lang=cpp
 *
 * [2423] 删除字符使频率相同
 */

// @lc code=start
class Solution
{
public:
    bool equalFrequency(string word)
    {
        int charCount[26] = {0};
        for (int i = 0; i < word.size(); i++)
            charCount[word[i] - 'a']++;
        for (int i = 0; i < 26; i++)
        {
            if (charCount[i] == 0)
                continue;
            charCount[i]--;
            unordered_set<int> frequency;
            for (int count : charCount)
                if (count)
                    frequency.insert(count);

            if (frequency.size() == 1)
                return true;
            charCount[i]++;
        }
        return false;
    }
};
// @lc code=end
