/*
 * @lc app=leetcode.cn id=3160 lang=cpp
 *
 * [3160] 所有球里面不同颜色的数目
 */

// @lc code=start
class Solution
{
public:
    vector<int> queryResults(int limit, vector<vector<int>> &queries)
    {
        vector<int> ans;
        unordered_map<int, int> color; // 存储各球的颜色
        unordered_map<int, int> cnt;   // 统计各个颜色的出现次数
        for (vector<int> &query : queries)
        {
            int x = query[0], y = query[1];
            if (color.contains(x))
            {
                if (--cnt[color[x]] == 0)
                    cnt.erase(color[x]);
            }
            // add
            color[x] = y;
            cnt[y]++;
            // 加入答案
            ans.push_back(cnt.size());
        }
        return ans;
    }
};
// @lc code=end
