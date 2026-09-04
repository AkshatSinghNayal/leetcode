with first_day as (
    select a.player_id , min(a.event_date ) as first
    from Activity as a 
    group by a.player_id
)

select round(count(*)/(
    select count( distinct temp.player_id )
    from Activity as temp
 ),2) as fraction
from first_day as f
left join Activity as a 
on f.player_id = a.player_id where datediff( a.event_date , f.first ) =1 