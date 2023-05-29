/*
 * @lc app=leetcode.cn id=2660 lang=cpp
 *
 * [2660] 保龄球游戏的获胜者
 */

// @lc code=start
class Solution
{
public:
    int isWinner(vector<int> &player1, vector<int> &player2)
    {
        int n = player1.size();
        int score1 = 0, score2 = 0;
        for (int i = 0; i < n; i++)
        {
            if ((i >= 2 && player1[i - 2] == 10) || (i >= 1 && player1[i - 1] == 10))
                score1 += 2 * player1[i];
            else
                score1 += player1[i];
        }
        for (int i = 0; i < n; i++)
        {
            if ((i >= 2 && player2[i - 2] == 10) || (i >= 1 && player2[i - 1] == 10))
                score2 += 2 * player2[i];
            else
                score2 += player2[i];
        }
        if (score1 > score2)
            return 1;
        else if (score1 == score2)
            return 0;
        else
            return 2;
    }
};
// @lc code=end
