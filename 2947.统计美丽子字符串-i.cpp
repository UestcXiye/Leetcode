/*
 * @lc app=leetcode.cn id=2947 lang=cpp
 *
 * [2947] 统计美丽子字符串 I
 */

// @lc code=start

// 双指针

class Solution
{
public:
    int beautifulSubstrings(string s, int k)
    {
        int len = s.length(), count = 0;
        for (int i = 0; i < len; i++)
        {
            int vowels = 0, consonants = 0;
            for (int j = i; j < len; j++)
            {
                if (isVowels(s[j]))
                    vowels++;
                else
                    consonants++;
                if (vowels == consonants && (vowels * consonants) % k == 0)
                    count++;
            }
        }
        return count;
    }
    // 辅函数 - 判断字符 c 是否是元音字母
    bool isVowels(const char &c)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        return false;
    }
};
// @lc code=end
