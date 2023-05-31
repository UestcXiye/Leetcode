--
-- @lc app=leetcode.cn id=1731 lang=mysql
--
-- [1731] 每位经理的下属员工数量
--

-- @lc code=start
# Write your MySQL query statement below
SELECT a.employee_id, a.name, COUNT(1) reports_count, round(avg(b.age)) average_age
FROM Employees a, Employees b
WHERE a.employee_id = b.reports_to
GROUP BY a.employee_id, a.name
ORDER BY a.employee_id
-- @lc code=end

