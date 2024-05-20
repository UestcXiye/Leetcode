/*
 * @lc app=leetcode.cn id=756 lang=cpp
 *
 * [756] 金字塔转换矩阵
 */

// @lc code=start
class Solution
{
private:
    unordered_map<string, vector<char>> reflect;

public:
    void init(string bottom, vector<string> &allowed)
    {
        for (string &s : allowed)
        {
            string bottomBlock = s.substr(0, 2);
            char upperBlock = s[2];
            reflect[bottomBlock].push_back(upperBlock);
        }
    }
    bool pyramidTransition(string bottom, vector<string> &allowed)
    {
        init(bottom, allowed);
        return dfs(bottom, "", 0);
    }
    // 辅函数
    bool dfs(string bottom, string upper, int pos)
    {
        if (bottom.length() == 1) // 到达顶层
            return true;
        if (upper.length() == bottom.length() - 1) // 本层构建完毕，递归构建上一层
            return dfs(upper, "", 0);
        if (pos == bottom.length() - 1) // 构建失败
            return false;
        // string curBlock = bottom.substr(pos, 2); // TLE 的罪魁祸首
        string curBlock = {bottom[pos], bottom[pos + 1]};
        if (reflect.count(curBlock) == 0) // 无法根据任何一条规则构建
            return false;
        for (char &c : reflect[curBlock])
            if (dfs(bottom, upper + c, pos + 1))
                return true;
        return false;
    }
};
// @lc code=end
