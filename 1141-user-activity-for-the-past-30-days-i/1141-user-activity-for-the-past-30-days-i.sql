select activity_date as day , count( distinct user_id) as active_users
from Activity 
WHERE activity_date > '2019-07-27' - INTERVAL 30 DAY AND activity_date <= '2019-07-27'
group by activity_date