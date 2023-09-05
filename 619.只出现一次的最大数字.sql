--
-- @lc app=leetcode.cn id=619 lang=mysql
--
-- [619] 只出现一次的最大数字
--

-- @lc code=start
# Write your MySQL query statement below
SELECT MAX(num) AS num
FROM (SELECT num FROM MyNumbers GROUP BY num HAVING COUNT(num) = 1) AS num_count;
-- @lc code=end

