/*
 * @lc app=leetcode.cn id=3029 lang=cpp
 *
 * [3029] 将单词恢复初始状态所需的最短时间 I
 */

// @lc code=start

// 暴力

class Solution
{
public:
    int minimumTimeToInitialState(string word, int k)
    {
        int n = word.size();
        int time = 0;
        for (int i = 0; i < n; i += k)
        {
            time++;
            if (i + k < n)
            {
                string temp = word.substr(i + k);

                if (word.substr(0, temp.size()) == temp)
                    break;
            }
        }
        return time;
    }
};
// @lc code=end
