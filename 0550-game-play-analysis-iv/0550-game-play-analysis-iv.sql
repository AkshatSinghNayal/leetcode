select round(count(*)/(select count(distinct player_id) from Activity),2) as fraction
from Activity as a
where a.event_date = (
    select min(b.event_date)+ interval 1 day 
    from Activity as b 
    where a.player_id = b.player_id
)