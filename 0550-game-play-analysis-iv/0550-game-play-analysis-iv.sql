select round(count(*)/(
    select count( distinct player_id )
    from Activity
),2) as fraction 
from Activity as a
where datediff(a.event_date , (
    select min(temp.event_date)
    from Activity as temp 
    where temp.player_id = a.player_id
)) = 1 
