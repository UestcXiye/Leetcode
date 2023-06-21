/*
 * @lc app=leetcode.cn id=914 lang=cpp
 *
 * [914] 卡牌分组
 */

// @lc code=start
class Solution
{
public:
    bool hasGroupsSizeX(vector<int> &deck)
    {
        unordered_map<int, int> umap;
        for (int &x : deck)
            umap[x]++;
        vector<int> count;
        for (auto it = umap.begin(); it != umap.end(); it++)
            count.push_back(it->second);
        sort(count.begin(), count.end());
        // if (count[0] < 2)
        //     return false;
        for (int group = 2; group <= count[count.size() - 1]; group++)
        {
            bool judge = true;
            for (int &num : count)
                if (num % group != 0)
                {
                    judge = false;
                    break;
                }
            if (judge)
                return true;
        }
        return false;
    }
};
// @lc code=end
