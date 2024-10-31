-- 코드를 작성해주세요

select round(sum(length)/count(*),2) as AVERAGE_LENGTH from (select case when i.length is null then 10 else i.length end length
from fish_info i) as temp