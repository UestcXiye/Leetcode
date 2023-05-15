/*
 * @lc app=leetcode.cn id=2231 lang=cpp
 *
 * [2231] 按奇偶性交换后的最大数字
 */

// @lc code=start
class Solution
{
public:
    int largestInteger(int num)
    {
        string s = to_string(num);
        int n = s.size();
        // 进行选择排序
        for (int i = 0; i < n - 1; ++i)
            for (int j = i + 1; j < n; ++j)
            {
                int num_i = s[i] - '0', num_j = s[j] - '0';
                if (num_i % 2 == num_j % 2) // 只有下标数值奇偶相同才进行判断
                {
                    if (num_i < num_j)
                    {
                        // swap(s[i], s[j])
                        char temp = s[i];
                        s[i] = s[j];
                        s[j] = temp;
                    }
                }
            }
        // 转化为最终的整数
        return stoi(s);
    }
};
// @lc code=end
