/*
 * @lc app=leetcode.cn id=2062 lang=cpp
 *
 * [2062] 统计字符串中的元音子字符串
 */

// @lc code=start
class Solution
{
public:
    int countVowelSubstrings(string word)
    {
        int n = word.size();
        int ans = 0;
        unordered_set<char> vowelSet = {'a', 'e', 'i', 'o', 'u'};
        for (int i = 0; i < n; i++)
        {
            unordered_set<char> charSet;
            for (int j = i; j < n; j++)
            {
                charSet.insert(word[j]);
                if (charSet == vowelSet)
                    ans++;
            }
        }
        return ans;
    }
};
// @lc code=end
