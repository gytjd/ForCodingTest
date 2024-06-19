-- 코드를 작성해주세요

select count(*) as fish_count,MONTH(time) as month
from fish_info
group by MONTH(time)
order by MONTH(time)