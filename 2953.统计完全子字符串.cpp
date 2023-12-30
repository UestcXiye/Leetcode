/*
 * @lc app=leetcode.cn id=2953 lang=cpp
 *
 * [2953] 统计完全子字符串
 */

// @lc code=start
class Solution
{
public:
    int countCompleteSubstrings(string word, int k)
    {
        int n = word.size();
        int ans = 0;
        for (int i = 0; i < n;)
        {
            int start = i;
            i++;
            while (i < n && abs(int(word[i]) - int(word[i - 1])) <= 2)
                i++;
            ans += countCompleteStrings(word.substr(start, i - start), k);
        }
        return ans;
    }
    // 辅函数 - 计算字符串 s 中完全子字符串的个数
    int countCompleteStrings(string s, int k)
    {
        int count = 0;
        for (int m = 1; m <= 26 && m * k <= s.length(); m++)
        {
            vector<int> alphaCount(26, 0);
            // 判断每种字符是否都出现了恰好 k 次
            auto check = [&]() -> bool
            {
                for (int i = 0; i < 26; i++)
                {
                    if (alphaCount[i] && alphaCount[i] != k)
                        return false;
                }
                return true;
            };
            // 滑动窗口
            // for (int right = 0; right < s.length(); right++)
            // {
            //     alphaCount[s[right] - 'a']++;
            //     int left = right + 1 - m * k;
            //     if (left >= 0)
            //     {
            //         if (check())
            //             count++;
            //         alphaCount[s[left] - 'a']--;
            //     }
            // }
            for (int i = 0; i < m * k; i++)
                alphaCount[s[i] - 'a']++;
            if (check())
                count++;
            for (int right = m * k; right < s.length(); right++)
            {
                alphaCount[s[right] - 'a']++;
                alphaCount[s[right - m * k] - 'a']--;
                if (check())
                    count++;
            }
        }
        return count;
    }
};
// @lc code=end
