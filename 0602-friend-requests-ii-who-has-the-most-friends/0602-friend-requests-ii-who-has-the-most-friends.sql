with temp as(
    select accepter_id as id from RequestAccepted
    union all 
    select requester_id as id from RequestAccepted
)

select id , count(*) as num
from temp
group by id
order by num  desc
limit 1 
