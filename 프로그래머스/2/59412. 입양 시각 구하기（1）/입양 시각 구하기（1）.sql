-- 코드를 입력하세요
SELECT hour(DATETIME) as HOUR,count(*) as COUNT
FROM animal_outs
GROUP BY HOUR
having HOUR >= 9 and HOUR <=19
order by HOUR