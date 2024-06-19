-- 코드를 작성해주세요

select YEAR(ym) as year,
round(sum(pm_val1)/count(*),2) as pm10,
round(sum(pm_val2)/count(*),2) as 'pm2.5'

from air_pollution
where location1='경기도' and location2='수원'
group by YEAR(ym)
order by YEAR(ym)
