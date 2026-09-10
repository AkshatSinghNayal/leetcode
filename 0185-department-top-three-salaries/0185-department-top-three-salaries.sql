with temp as (
    select id , name as Employee , 
    dense_rank() over( partition by departmentId 
    order by salary desc
    ) as rnk , departmentId , salary as Salary
    from Employee
)
select d.name as Department, t.Employee , t.Salary
from temp as t
left join Department as d 
on t.departmentId = d.id 
where t.rnk<=3