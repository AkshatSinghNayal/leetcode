WITH temp AS (
    SELECT requester_id AS id FROM RequestAccepted
    UNION ALL
    SELECT accepter_id AS id FROM RequestAccepted
),
friend_count AS (
    SELECT id, COUNT(*) AS num
    FROM temp
    GROUP BY id
)
SELECT id, num
FROM (
    SELECT id,
           num,
           RANK() OVER (ORDER BY num DESC) AS rnk
    FROM friend_count
) t
WHERE rnk = 1;
