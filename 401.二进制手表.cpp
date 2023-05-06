/*
 * @lc app=leetcode.cn id=401 lang=cpp
 *
 * [401] 二进制手表
 */

// @lc code=start
class Solution
{
public:
    vector<string> readBinaryWatch(int turnedOn)
    {
        vector<string> ans;
        string temp;
        for (int h = 0; h < 12; h++)
        {
            for (int m = 0; m < 60; m++)
            {
                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn)
                {
                    temp = "";
                    temp += to_string(h);
                    temp += ":";
                    if (m < 10)
                        temp += "0";
                    temp += to_string(m);

                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
