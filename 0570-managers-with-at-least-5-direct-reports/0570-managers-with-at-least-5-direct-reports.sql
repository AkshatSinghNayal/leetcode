# Write your MySQL query statement below
SELECT e.name
FROM Employee AS e
INNER JOIN Employee AS d ON e.id = d.managerID
group by d.managerID
having count(*) >= 5
