/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start

// 滑动窗口

// class Solution
// {
// public:
//     int lengthOfLongestSubstring(string s)
//     {
//         if (s.empty())
//             return 0;
//         int n = s.size(), maxLen = 0, left = 0;
//         unordered_set<char> occurred;
//         for (int i = 0; i < n; i++)
//         {
//             while (occurred.find(s[i-1]) != occurred.end()) // s[i-1] 在哈希表中存在
//             {
//                 occurred.erase(s[left]);
//                 left++;
//             }
//             maxLen = max(maxLen, i - left + 1);
//             occurred.insert(s[i-1]);
//         }
//         return maxLen;
//     }
// };

// 动态规划

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (s.empty())
            return 0;
        int n = s.size();
        if (n <= 1)
            return n;
        int max_len = 0;
        unordered_map<char, int> charMap; //<字符，最大下标>
        vector<int> dp(n, 0);
        // 初始化
        dp[0] = 1;
        charMap[s[0]] = 1;
        // 状态转移
        for (int i = 1; i < n; i++)
        {
            if (charMap[s[i]] == 0)
                dp[i] = dp[i - 1] + 1;
            else
            {
                int lastIndex = charMap[s[i]] - 1;
                int distance = i - lastIndex;
                if (distance <= dp[i - 1])
                    dp[i] = distance;
                else
                    dp[i] = dp[i - 1] + 1;
            }
            charMap[s[i]] = i + 1;
            max_len = max(max_len, dp[i]);
        }
        return max_len;
    }
};
// @lc code=end
