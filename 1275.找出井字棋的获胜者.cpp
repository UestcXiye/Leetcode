/*
 * @lc app=leetcode.cn id=1275 lang=cpp
 *
 * [1275] 找出井字棋的获胜者
 */

// @lc code=start
class Solution
{
private:
    const vector<vector<int>> WINS = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}};

public:
    string tictactoe(vector<vector<int>> &moves)
    {
        unordered_set<int> A, B;
        for (int i = 0; i < moves.size(); i++)
        {
            int pos = moves[i][0] * 3 + moves[i][1];
            if (i % 2 == 0)
            {
                A.insert(pos);
                if (check(A, WINS))
                    return "A";
            }
            else
            {
                B.insert(pos);
                if (check(B, WINS))
                    return "B";
            }
        }
        return moves.size() == 9 ? "Draw" : "Pending";
    }
    // 辅函数
    bool check(const unordered_set<int> &s, const vector<vector<int>> &WINS)
    {
        for (const vector<int> &win : WINS)
        {
            bool flag = true;
            for (const int &pos : win)
            {
                if (!s.count(pos))
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                return true;
        }
        return false;
    }
};
// @lc code=end
