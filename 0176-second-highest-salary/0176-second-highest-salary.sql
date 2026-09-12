with temp as (
    select id , salary ,
    dense_rank() over( order by salary desc ) as rnk
    from Employee
)
select case when count(*) = 0 then null else salary end as SecondHighestSalary
from temp
where rnk = 2
