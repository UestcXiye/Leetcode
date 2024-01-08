/*
 * @lc app=leetcode.cn id=2981 lang=cpp
 *
 * [2981] 找出出现至少三次的最长特殊子字符串 I
 */

// @lc code=start

class Solution
{
public:
    int maximumLength(string s)
    {
        // 特判
        if (s.empty())
            return 0;

        int n = s.size();
        int ans = -1, left = 0;
        for (int right = 0; right < n; right++)
        {
            while (s[left] != s[right])
                left++;
            int len = right - left + 1;
            string sub = s.substr(left, len);
            int count = 1;
            // 暴力枚举所有的子字符串
            for (int i = left + 1; i < n; i++)
            {
                string temp = s.substr(i, len);
                if (sub == temp)
                {
                    count++;
                    if (count >= 3)
                    {
                        ans = max(ans, len);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end
