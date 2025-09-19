select a.mcdp_cd as 진료과코드,count(*) as 5월예약건수 from appointment a
where date_format(a.apnt_ymd,"%Y-%m")="2022-05"
group by a.mcdp_cd
order by 5월예약건수,진료과코드