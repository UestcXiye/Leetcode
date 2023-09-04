/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
class Solution
{
private:
    vector<pair<int, int>> freq;
    vector<vector<int>> ans;
    vector<int> seq;

public:
    // 主函数
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        // 初始化 freq
        for (int num : candidates)
        {
            if (freq.empty() || num != freq.back().first)
                freq.emplace_back(num, 1);
            else
                freq.back().second++;
        }
        dfs(0, target);
        return ans;
    }
    // 辅函数
    void dfs(int pos, int rest)
    {
        if (rest == 0)
        {
            ans.push_back(seq);
            return;
        }
        if (pos == freq.size() || rest < freq[pos].first)
            return;
        dfs(pos + 1, rest);
        int most = min(rest / freq[pos].first, freq[pos].second);
        for (int i = 1; i <= most; i++)
        {
            seq.push_back(freq[pos].first);
            dfs(pos + 1, rest - i * freq[pos].first);
        }
        // 回改当前节点状态
        for (int i = 1; i <= most; i++)
            seq.pop_back();
    }
};
// @lc code=end
