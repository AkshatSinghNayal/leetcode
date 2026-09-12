with temp as (
    select id , salary ,
    dense_rank() over( order by salary desc ) as rnk
    from Employee
)
select max( case when rnk = 2 then salary else null end ) as SecondHighestSalary
from temp 
