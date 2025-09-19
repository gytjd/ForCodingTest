select f.product_id,f.product_name,f.product_cd,f.category,f.price
from food_product f
where f.price = (select max(price) from food_product);