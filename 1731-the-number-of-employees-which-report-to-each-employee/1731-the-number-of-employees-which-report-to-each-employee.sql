select e.employee_id , e.name , count(*) as reports_count , round(avg(d.age)) as average_age
from Employees as e 
inner join Employees as d 
on e.employee_id = d.reports_to
group by e.employee_id
order by e.employee_id