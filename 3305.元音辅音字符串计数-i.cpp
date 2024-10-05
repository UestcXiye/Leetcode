/*
 * @lc app=leetcode.cn id=3305 lang=cpp
 *
 * [3305] 元音辅音字符串计数 I
 */

// @lc code=start
class Solution
{
private:
    const unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

public:
    int countOfSubstrings(string word, int k)
    {
        int n = word.length();
        int count = 0;

        for (int left = 0; left + 5 + k <= n; left++)
        {
            int notVowel = 0;
            unordered_set<char> foundVowels; // 存放当前找到的元音字母
            for (int right = left; right < n; right++)
            {
                char c = word[right];
                if (vowels.count(c))
                    foundVowels.insert(c);
                else
                    notVowel++;

                if (foundVowels.size() == 5 && notVowel == k)
                    count++;
            }
        }

        return count;
    }
};
// @lc code=end