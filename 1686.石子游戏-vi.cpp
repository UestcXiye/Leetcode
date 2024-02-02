/*
 * @lc app=leetcode.cn id=1686 lang=cpp
 *
 * [1686] 石子游戏 VI
 */

// @lc code=start
class Solution
{
public:
    int stoneGameVI(vector<int> &aliceValues, vector<int> &bobValues)
    {
        int n = aliceValues.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&aliceValues, &bobValues](const int lhs, const int rhs)
             { return (aliceValues[lhs] + bobValues[lhs]) > (aliceValues[rhs] + bobValues[rhs]); });
        int alice_score = 0, bob_score = 0;
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0) // Alice choose
                alice_score += aliceValues[idx[i]];
            else // Bob choose
                bob_score += bobValues[idx[i]];
        }

        if (alice_score == bob_score)
            return 0;
        return alice_score > bob_score ? 1 : -1;
    }
};
// @lc code=end
