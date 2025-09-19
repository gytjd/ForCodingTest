SELECT DATE_FORMAT(sales_date, '%Y-%m-%d') AS sales_date,product_id,user_id,sales_amount
FROM online_sale
where MONTH(sales_date)=3

UNION ALL

SELECT DATE_FORMAT(sales_date, '%Y-%m-%d') AS sales_date,product_id,null as user_id,sales_amount
FROM offline_sale
where MONTH(sales_date)=3

order by sales_date,product_id,user_id;