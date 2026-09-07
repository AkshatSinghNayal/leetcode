with temp as (
    select main.id , case when num = (
    select l.num
    from Logs as l
    where l.id = main.id+1
) and  num = (
    select ll.num
    from Logs as ll
    where ll.id = main.id+2
) then num else null end as found 
from Logs as main
)

select distinct found as ConsecutiveNums
from temp
where found is not null