select f.warehouse_id,f.warehouse_name,f.address,coalesce(f.freezer_yn,'N') as freezer_yn
from food_warehouse f
where f.warehouse_name like "%경기%"
order by f.warehouse_id