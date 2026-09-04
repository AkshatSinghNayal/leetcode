WITH temp AS (
    SELECT *,
           ROW_NUMBER() OVER (
               PARTITION BY player_id
               ORDER BY event_date
           ) AS streak
    FROM Activity
)

SELECT 
    ROUND(
        COUNT(temp.player_id) /
        (
            SELECT COUNT(DISTINCT player_id)
            FROM Activity
        ) ,
        2
    ) AS fraction

FROM temp

INNER JOIN temp AS t
    ON temp.player_id = t.player_id
   AND DATEDIFF(temp.event_date, t.event_date) = 1

WHERE temp.streak <= 2;