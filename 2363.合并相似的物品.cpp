/*
 * @lc app=leetcode.cn id=2363 lang=cpp
 *
 * [2363] 合并相似的物品
 */

// @lc code=start
class Solution
{
public:
    static bool cmp(const vector<int> A, const vector<int> B)
    {
        return A[0] < B[0];
    }
    vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1, vector<vector<int>> &items2)
    {
        unordered_map<int, int> umap;
        for (vector<int> item : items1)
        {
            if (umap.count(item[0]))
                umap[item[0]] += item[1];
            else
                umap[item[0]] = item[1];
        }
        for (vector<int> item : items2)
        {
            if (umap.count(item[0]))
                umap[item[0]] += item[1];
            else
                umap[item[0]] = item[1];
        }
        vector<vector<int>> res;
        for (unordered_map<int, int>::iterator it = umap.begin(); it != umap.end(); it++)
            res.push_back({(*it).first, (*it).second});
        sort(res.begin(), res.end(), cmp);
        return res;
    }
};
// @lc code=end
