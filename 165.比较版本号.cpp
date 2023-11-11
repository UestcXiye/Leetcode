/*
 * @lc app=leetcode.cn id=165 lang=cpp
 *
 * [165] 比较版本号
 */

// @lc code=start
class Solution
{
public:
    int compareVersion(string version1, string version2)
    {
        stringstream ss;
        vector<int> v1, v2;
        string s;
        ss << version1;
        while (getline(ss, s, '.'))
            v1.push_back(stoi(s));
        ss.clear();
        ss << version2;
        while (getline(ss, s, '.'))
            v2.push_back(stoi(s));
        while (v1.size() < v2.size())
            v1.push_back(0);
        while (v2.size() < v1.size())
            v2.push_back(0);
        for (int i = 0; i < v1.size(); i++)
        {
            if (v1[i] > v2[i])
                return 1;
            else if (v1[i] < v2[i])
                return -1;
        }
        return 0;
    }
};
// @lc code=end
