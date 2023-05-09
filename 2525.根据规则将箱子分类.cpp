/*
 * @lc app=leetcode.cn id=2525 lang=cpp
 *
 * [2525] 根据规则将箱子分类
 */

// @lc code=start
class Solution
{
public:
    string categorizeBox(int length, int width, int height, int mass)
    {
        bool Bulky = false;
        bool Heavy = false;
        if (!(length < 10000 && width < 10000 && height < 10000) || (long long)length * width * height >= 1000000000)
            Bulky = true;
        if (mass >= 100)
            Heavy = true;
        if (Bulky && Heavy)
            return "Both";
        else if (!Bulky && !Heavy)
            return "Neither";
        else if (Bulky && !Heavy)
            return "Bulky";

        return "Heavy";
    }
};
// @lc code=end
