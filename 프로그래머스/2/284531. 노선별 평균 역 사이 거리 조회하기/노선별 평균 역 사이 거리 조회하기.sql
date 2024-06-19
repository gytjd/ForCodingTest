-- 코드를 작성해주세요
select route,
concat(round(sum(d_between_dist),1),'km') as total_distance,
concat(round(sum(d_between_dist)/count(route),2),'km')  as average_distance

from subway_distance
group by route
order by sum(d_cumulative) desc