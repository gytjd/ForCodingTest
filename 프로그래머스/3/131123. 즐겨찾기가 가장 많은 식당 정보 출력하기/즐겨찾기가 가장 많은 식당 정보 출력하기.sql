-- 코드를 입력하세요

select food_type,rest_id,rest_name,favorites 
from rest_info 
where (food_type,favorites) 
in (SELECT R.FOOD_TYPE,max(R.FAVORITES) FROM REST_INFO R GROUP BY R.FOOD_TYPE)
order by food_type desc