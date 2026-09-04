WITH first_login AS (
    SELECT
        player_id,
        MIN(event_date) AS first_date
    FROM Activity
    GROUP BY player_id
)

SELECT
    ROUND(
        COUNT(a.player_id) /
        (SELECT COUNT(DISTINCT player_id) FROM Activity),
        2
    ) AS fraction
FROM first_login AS f
JOIN Activity AS a
    ON f.player_id = a.player_id
   AND datediff( a.event_date , f.first_date ) =1 