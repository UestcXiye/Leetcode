/*
 * @lc app=leetcode.cn id=1839 lang=cpp
 *
 * [1839] 所有元音按顺序排布的最长子字符串
 */

// @lc code=start

// 滑动窗口

class Solution
{
public:
    int longestBeautifulSubstring(string word)
    {
        // 特判
        if (word.size() < 5)
            return 0;
        int n = word.size();
        string window;
        unordered_set<char> cnt;
        int max_len = 0, left = 0, right = 0;
        while (right < n)
        {
            if (window.empty() || word[right] >= window.back())
            {
                window += word[right];
                cnt.insert(word[right]);
                right++;
                if (cnt.size() == 5)
                    max_len = max(max_len, (int)window.size());
            }
            else
            {
                window = "";
                cnt.clear();
                left = right;
                window += word[left];
                cnt.insert(word[left]);
                right++;
            }
        }
        return max_len;
    }
};

// 一次遍历

// class Solution
// {
// public:
//     int longestBeautifulSubstring(string word)
//     {
//         // 特判
//         if (word.size() < 5)
//             return 0;
//         int n = word.size();
//         int max_len = 0;
//         int vowel = 1, cur_len = 1;
//         for (int i = 1; i < n; i++)
//         {
//             if (word[i] >= word[i - 1])
//             {
//                 cur_len++;
//                 if (word[i] > word[i - 1])
//                     vowel++;
//             }
//             else
//             {
//                 cur_len = 1;
//                 vowel = 1;
//             }
//             if (vowel == 5)
//                 max_len = max(max_len, cur_len);
//         }
//         return max_len;
//     }
// };
// @lc code=end
