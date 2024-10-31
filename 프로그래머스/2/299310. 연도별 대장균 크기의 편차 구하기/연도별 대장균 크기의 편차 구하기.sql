select e.YEAR,e.max_col-d.size_of_colony as YEAR_DEV,d.id as ID from ecoli_data d join (select max(size_of_colony) as max_col,YEAR(differentiation_date) as YEAR from ecoli_data group by YEAR) e on year(d.differentiation_date)=e.YEAR
order by YEAR,YEAR_DEV
