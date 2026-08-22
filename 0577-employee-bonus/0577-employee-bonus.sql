# Write your MySQL query statement below
select e.name , u.bonus
from Employee as e 
left join Bonus as u 
on e.empID = u.empID
where u.bonus is null or u.bonus < 1000 
