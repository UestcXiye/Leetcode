/*
 * @lc app=leetcode.cn id=1710 lang=cpp
 *
 * [1710] 卡车上的最大单元数
 */

// @lc code=start
class Solution
{
private:
    static bool cmp(const vector<int> &A, const vector<int> &B)
    {
        return A[1] > B[1];
    }

public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        int n = boxTypes.size();
        sort(boxTypes.begin(), boxTypes.end(), cmp);
        int sum = 0;
        for (vector<int> &boxType : boxTypes)
        {
            if (truckSize > 0)
            {
                if (truckSize >= boxType[0])
                {
                    sum += boxType[0] * boxType[1];
                    truckSize -= boxType[0];
                }
                else
                {
                    sum += truckSize * boxType[1];
                    truckSize = 0;
                }
            }
        }
        return sum;
    }
};
// @lc code=end
