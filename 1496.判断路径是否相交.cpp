/*
 * @lc app=leetcode.cn id=1496 lang=cpp
 *
 * [1496] 判断路径是否相交
 */

// @lc code=start
class Solution
{
public:
    bool isPathCrossing(string path)
    {
        // unordered_set 里面不能存 pair
        set<pair<int, int>> visited;
        int x = 0, y = 0;
        visited.insert({x, y});
        for (char &dir : path)
        {
            switch (dir)
            {
            case 'N':
                y++;
                break;
            case 'S':
                y--;
                break;
            case 'E':
                x++;
                break;
            case 'W':
                x--;
                break;
            }
            if (visited.find({x, y}) != visited.end())
                return true;
            else
                visited.insert({x, y});
        }
        return false;
    }
};
// @lc code=end
