# Write your MySQL query statement below
select e.name , d.bonus
from Employee as e
left join Bonus as d 
on (e.empId = d.empId )
where d.bonus <1000 or d.bonus is null;