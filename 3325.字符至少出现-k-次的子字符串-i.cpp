/*
 * @lc app=leetcode.cn id=3325 lang=cpp
 *
 * [3325] 字符至少出现 K 次的子字符串 I
 */

// @lc code=start
class Solution
{
public:
    int numberOfSubstrings(string s, int k)
    {
        int n = s.length();
        if (k > n)
            return 0;

        vector<int> cnt(26, 0);
        int left = 0; // 滑动窗口的左端点
        int count = 0;
        for (int right = 0; right < n; right++)
        {
            cnt[s[right] - 'a']++;

            while (cnt[s[right] - 'a'] >= k)
            {
                cnt[s[left] - 'a']--;
                left++;
            }

            count += left;
        }

        return count;
    }
};
// @lc code=end
