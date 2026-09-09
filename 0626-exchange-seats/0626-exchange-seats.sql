with temp as (
    select 
    id , student , 
    case when id%2 != 0 and id+1 in ( select id from Seat )
    then id+1
    when id % 2 = 0 and id-1 in (select id from Seat ) 
    then id-1
    else id 
    end  as req
    from Seat
)

select t.id ,  s.student
from temp  as t
left join Seat as s 
on t.req = s.id