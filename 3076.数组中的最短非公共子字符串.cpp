/*
 * @lc app=leetcode.cn id=3076 lang=cpp
 *
 * [3076] 数组中的最短非公共子字符串
 */

// @lc code=start
class Solution
{
public:
    vector<string> shortestSubstrings(vector<string> &arr)
    {
        int n = arr.size();
        vector<string> answer(n);

        // 若 sub 不是 arr 中其他（下标不为 i）任何字符串的子字符串，返回 true
        auto check = [&](int i, string &sub)
        {
            for (int j = 0; j < n; j++)
            {
                if (j != i && arr[j].find(sub) != string::npos)
                    return false;
            }
            return true;
        };

        for (int i = 0; i < n; i++)
        {
            int m = arr[i].size();
            string res;
            for (int len = 1; len <= m && res.empty(); len++)
                for (int begin = 0; begin <= m - len; begin++)
                {
                    string temp = arr[i].substr(begin, len);
                    if ((res.empty() || temp < res) && check(i, temp))
                        res = temp;
                }
            answer[i] = res;
        }

        return answer;
    }
};
// @lc code=end
