-- 코드를 입력하세요
select MCDP_CD as 진료과코드,count(*) as 5월예약건수 from appointment where month(apnt_ymd)='05'
group by MCDP_CD
order by 5월예약건수,진료과코드