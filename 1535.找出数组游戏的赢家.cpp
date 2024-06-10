/*
 * @lc app=leetcode.cn id=1535 lang=cpp
 *
 * [1535] 找出数组游戏的赢家
 */

// @lc code=start
class Solution
{
public:
    int getWinner(vector<int> &arr, int k)
    {
        int n = arr.size();
        int mx_i = 0, win = 0;
        for (int i = 1; i < n && win < k; i++)
        {
            if (arr[i] > arr[mx_i])
            {
                mx_i = i;
                win = 0;
            }
            win++;
        }
        return arr[mx_i];
    }
};
// @lc code=end
