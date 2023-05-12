/*
 * @lc app=leetcode.cn id=2347 lang=cpp
 *
 * [2347] 最好的扑克手牌
 */

// @lc code=start
class Solution
{
public:
    string bestHand(vector<int> &ranks, vector<char> &suits)
    {
        bool isSuitsSame = true;
        char color = suits[0];
        for (char suit : suits)
            if (suit != color)
            {
                isSuitsSame = false;
                break;
            }
        int maxSameRank = 0;
        unordered_map<int, int> umap;
        for (int rank : ranks)
        {
            if (umap.count(rank))
                umap[rank]++;
            else
                umap[rank] = 1;
        }
        for (auto it = umap.begin(); it != umap.end(); it++)
            maxSameRank = max(maxSameRank, it->second);
        if (isSuitsSame == true)
            return "Flush";
        else if (maxSameRank >= 3)
            return "Three of a Kind";
        else if (maxSameRank == 2)
            return "Pair";
        else
            return "High Card";
    }
};
// @lc code=end
