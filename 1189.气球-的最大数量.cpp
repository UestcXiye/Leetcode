/*
 * @lc app=leetcode.cn id=1189 lang=cpp
 *
 * [1189] “气球” 的最大数量
 */

// @lc code=start
class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        int count_b = 0, count_a = 0, count_l = 0, count_o = 0, count_n = 0;
        for (char &c : text)
        {
            if (c == 'b')
                count_b++;
            else if (c == 'a')
                count_a++;
            else if (c == 'l')
                count_l++;
            else if (c == 'o')
                count_o++;
            else if (c == 'n')
                count_n++;
            else
                continue;
        }
        vector<int> freq = {count_b, count_a, count_n, count_l / 2, count_o / 2};
        sort(freq.begin(), freq.end());
        return freq[0];
    }
};
// @lc code=end
