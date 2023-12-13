/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start

// 优先队列

// class MedianFinder
// {
// private:
//     // 大顶堆，top 是其最大的元素，存储小于等于中位数的数
//     priority_queue<int, vector<int>, less<int>> maxHeap;
//     // 小顶堆，top 是其最小的元素，存储大于中位数的数
//     priority_queue<int, vector<int>, greater<int>> minHeap;

// public:
//     MedianFinder() {}

//     void addNum(int num)
//     {
//         maxHeap.push(num);
//         if (maxHeap.size() > minHeap.size() + 1)
//         {
//             int x = maxHeap.top();
//             minHeap.push(x);
//             maxHeap.pop();
//         }
//         while (!minHeap.empty() && maxHeap.top() > minHeap.top())
//         {
//             int x = maxHeap.top(), y = minHeap.top();
//             maxHeap.pop();
//             maxHeap.push(y);
//             minHeap.pop();
//             minHeap.push(x);
//         }
//     }

//     double findMedian()
//     {
//         double median;
//         if ((maxHeap.size() + minHeap.size()) % 2 == 1)
//             median = (double)maxHeap.top();
//         else
//             median = (maxHeap.top() + minHeap.top()) / 2.0;
//         return median;
//     }
// };

// 有序集合 + 双指针

class MedianFinder
{
private:
    multiset<int> nums;
    multiset<int>::iterator left, right;

public:
    MedianFinder() : left(nums.end()), right(nums.end()) {}

    void addNum(int num)
    {
        const size_t n = nums.size();

        nums.insert(num);
        if (n == 0)
        {
            left = right = nums.begin();
        }
        else if (n % 2 == 1)
        {
            if (num < *left)
                left--;
            else
                right++;
        }
        else
        {
            if (num > *left && num < *right)
            {
                left++;
                right--;
            }
            else if (num >= *right)
                left++;
            else
            {
                right--;
                left = right;
            }
        }
    }

    double findMedian()
    {
        return (*left + *right) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
