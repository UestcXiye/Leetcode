/*
 * @lc app=leetcode.cn id=2937 lang=cpp
 *
 * [2937] 使三个字符串相等
 */

// @lc code=start
class Solution
{
public:
    int findMinimumOperations(string s1, string s2, string s3)
    {
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        int min_len = min(len1, min(len2, len3));
        for (int len = min_len; len >= 1; len--)
        {
            string t1 = s1.substr(0, len), t2 = s2.substr(0, len), t3 = s3.substr(0, len);
            if (t1 == t2 && t2 == t3)
                return len1 + len2 + len3 - 3 * len;
        }
        return -1;
    }
};
// @lc code=end
