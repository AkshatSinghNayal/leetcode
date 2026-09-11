WITH temp AS (
    SELECT requester_id AS id
    FROM RequestAccepted

    UNION ALL

    SELECT accepter_id AS id
    FROM RequestAccepted
),
cnt as(
    select id , count(*) as cnt 
    from temp
    group by id
), 
final as(
    select id , cnt ,
    rank() over(order by cnt desc ) as rnk
    from cnt 

)

select id , cnt as num
from final 
where rnk = 1