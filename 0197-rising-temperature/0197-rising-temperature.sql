SELECT w2.id
FROM Weather AS w1
JOIN Weather AS w2
ON DATEDIFF(w2.recordDate, w1.recordDate) = 1
AND w2.temperature > w1.temperature;