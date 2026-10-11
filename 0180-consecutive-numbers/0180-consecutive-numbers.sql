with temp1 as (
    select l.id, l.num
    from Logs as l 
    where l.num = (
        select num
        from Logs 
        where l.id+1 = id
    )  and l.num = (
        select num
        from logs 
        where l.id+2 = id
    )
) 

select distinct num as "ConsecutiveNums"
from temp1