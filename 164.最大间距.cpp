/*
 * @lc app=leetcode.cn id=164 lang=cpp
 *
 * [164] 最大间距
 */

// @lc code=start
class Solution
{
private:
    // 求出数组中最大数的位数
    int MaxBit(vector<int> &input)
    {
        int max_num = *max_element(input.begin(), input.end());
        int p = 0;
        while (max_num > 0)
        {
            p++;
            max_num /= 10; // 每次除以10取整，即可去掉最低位
        }
        return p;
    }
    // 取出所给数字的第d位数字
    int GetNum(int num, int d)
    {
        int p = 1;
        while (d - 1 > 0)
        {
            p *= 10;
            d--;
        }
        return num / p % 10;
    }
    // 基数排序
    vector<int> RadixSort(vector<int> &input)
    {
        int length = input.size();
        vector<int> bucket(length); // 创建临时存放排序过程中的数据
        for (int d = 1; d <= MaxBit(input); d++)
        {
            // 创建按位计数的计数容器，即记录排序中按个位、十位...各个数的位置的个数
            vector<int> count(10, 0);
            // 统计各个桶中的个数
            for (int i = 0; i < length; i++)
                count[GetNum(input[i], d)]++;
            // 得到每个数应该放入bucket中的位置
            for (int i = 1; i < 10; i++)
                count[i] += count[i - 1];
            // 采用倒序进行排序是为了不打乱已经排好的顺序
            for (int i = length - 1; i >= 0; i--)
            {
                int k = GetNum(input[i], d);
                bucket[count[k] - 1] = input[i];
                count[k]--;
            }
            // 临时数组复制到 input 中
            for (int j = 0; j < length; j++)
                input[j] = bucket[j];
        }
        return input;
    }

public:
    int maximumGap(vector<int> &nums)
    {
        vector<int> sortedNums = RadixSort(nums);
        int max_gap = 0;
        for (int i = 1; i < sortedNums.size(); i++)
            max_gap = max(max_gap, sortedNums[i] - sortedNums[i - 1]);
        return max_gap;
    }
};
// @lc code=end
