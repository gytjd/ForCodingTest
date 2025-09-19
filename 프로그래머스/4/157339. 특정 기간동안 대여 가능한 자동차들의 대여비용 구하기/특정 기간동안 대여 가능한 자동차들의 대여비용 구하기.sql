SELECT 
    c.car_id,
    c.car_type,
    ROUND(c.daily_fee * 30 * (1 - d.discount_rate/100)) AS fee
FROM car_rental_company_car c
JOIN car_rental_company_discount_plan d 
  ON c.car_type = d.car_type
 AND d.duration_type = '30일 이상'
WHERE c.car_type IN ('세단', 'SUV')
  AND NOT EXISTS (
        SELECT 1
        FROM car_rental_company_rental_history r
        WHERE r.car_id = c.car_id
          AND r.start_date <= '2022-11-30'
          AND r.end_date   >= '2022-11-01'
  )
  AND ROUND(c.daily_fee * 30 * (1 - d.discount_rate/100)) BETWEEN 500000 AND 1999999
ORDER BY fee DESC, c.car_type ASC, c.car_id DESC;