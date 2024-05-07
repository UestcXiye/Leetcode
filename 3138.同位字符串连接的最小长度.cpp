/*
 * @lc app=leetcode.cn id=3138 lang=cpp
 *
 * [3138] 同位字符串连接的最小长度
 */

// @lc code=start
class Solution
{
public:
    int minAnagramLength(string s)
    {

        int n = s.length();
        for (int len = 1; len < n; len++)
        {
            if (n % len == 0)
            {
                set<string> set;
                for (int i = 0; i < n; i += len)
                {
                    string temp = s.substr(i, len);
                    sort(temp.begin(), temp.end());
                    set.insert(temp);
                    if (set.size() > 1)
                        break;
                }
                if (set.size() == 1)
                    return len;
            }
        }
        return n;
    }
};
// @lc code=end
