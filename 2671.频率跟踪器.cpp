/*
 * @lc app=leetcode.cn id=2671 lang=cpp
 *
 * [2671] 频率跟踪器
 */

// @lc code=start
class FrequencyTracker
{
private:
    unordered_map<int, int> cnt;  // number 的出现次数
    unordered_map<int, int> freq; // number 的出现次数的出现次数

public:
    FrequencyTracker()
    {
    }

    void add(int number)
    {
        freq[cnt[number]]--;
        cnt[number]++;
        freq[cnt[number]]++;
    }

    void deleteOne(int number)
    {
        if (!cnt[number])
            return;
        freq[cnt[number]]--;
        cnt[number]--;
        freq[cnt[number]]++;
    }

    bool hasFrequency(int frequency)
    {
        return freq[frequency];
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */
// @lc code=end
