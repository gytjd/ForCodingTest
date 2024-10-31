-- 코드를 입력하세요
select substring(product_code,1,2) as CATEGORY,count(product_code) from product group by substring(product_code,1,2) order by product_code