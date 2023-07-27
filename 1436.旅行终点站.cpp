/*
 * @lc app=leetcode.cn id=1436 lang=cpp
 *
 * [1436] 旅行终点站
 */

// @lc code=start
class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {
        unordered_set<string> citiesA;
        for (vector<string> &path : paths)
            citiesA.insert(path[0]);
        for (vector<string> &path : paths)
            if (!citiesA.count(path[1]))
                return path[1];
        return "";
    }
};
// @lc code=end
