--
-- @lc app=leetcode.cn id=1075 lang=mysql
--
-- [1075] 项目员工 I
--

-- @lc code=start
# Write your MySQL query statement below
SELECT project_id, ROUND(AVG(experience_years) , 2) AS average_years
FROM Project JOIN Employee
WHERE Project.employee_id = Employee.employee_id
GROUP BY project_id;
-- @lc code=end

