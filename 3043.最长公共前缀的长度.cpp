/*
 * @lc app=leetcode.cn id=3043 lang=cpp
 *
 * [3043] 最长公共前缀的长度
 */

// @lc code=start
class Solution
{
public:
    int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2)
    {
        set<string> strSet;
        for (int &x : arr1)
        {
            string s = to_string(x);
            for (int i = 1; i <= s.length(); i++)
                strSet.insert(s.substr(0, i));
        }

        int ans = 0;
        for (int &x : arr2)
        {
            string s = to_string(x);
            for (int len = 1; len <= s.length(); len++)
            {
                string temp = s.substr(0, len);
                if (strSet.count(temp))
                    ans = max(ans, len);
            }
        }

        return ans;
    }
};
// @lc code=end
