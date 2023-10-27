-- 코드를 입력하세요
SELECT
    c.car_id,
    round(AVG(c.end_date - c.start_date+1),1) AS average_duration
FROM
    car_rental_company_rental_history c
GROUP BY
    c.car_id
HAVING
    AVG(c.end_date - c.start_date+1) >= 7
ORDER BY
    AVERAGE_DURATION DESC,
    c.car_id DESC