/*
 * @lc app=leetcode.cn id=738 lang=cpp
 *
 * [738] 单调递增的数字
 */

// @lc code=start
class Solution
{
public:
    int monotoneIncreasingDigits(int n)
    {
        string s = to_string(n);
        int max = -1, idx = -1;
        for (int i = 0; i < s.length() - 1; i++)
        {
            if (max < s[i])
            { // idx 就是修改的起点
                max = s[i];
                idx = i;
            }
            // 找到从高到低第一个满足 s[i] > s[i + 1] 的位置
            if (s[i] > s[i + 1])
            {
                // 把 s[idx] 减去 1，后面全部置 9
                s[idx] -= 1;
                for (int j = idx + 1; j < s.length(); j++)
                    s[j] = '9';
                break;
            }
        }
        return stoi(s);
    }
};
// @lc code=end
