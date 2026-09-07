with temp as(
    select employee_id , department_id , primary_flag , 
    count(*) over( 
        partition by employee_id
    ) as number
    from Employee   
)

select employee_id , department_id
from temp
where number =1 or primary_flag = 'Y'