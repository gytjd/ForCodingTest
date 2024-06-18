-- 코드를 입력하세요
select warehouse_id,warehouse_name,address,COALESCE(freezer_yn, 'N') AS freezer_yn
from food_warehouse
where warehouse_name like '%경기%'
order by warehouse_id