--
-- @lc app=leetcode.cn id=181 lang=mysql
--
-- [181] 超过经理收入的员工
--

-- @lc code=start
# Write your MySQL query statement below
SELECT a.name AS Employee
FROM Employee AS a JOIN Employee AS b
WHERE a.managerId = b.id AND a.salary > b.salary;
-- @lc code=end

