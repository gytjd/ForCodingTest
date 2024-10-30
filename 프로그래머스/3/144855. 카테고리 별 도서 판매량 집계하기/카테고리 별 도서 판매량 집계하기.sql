select b.category as CATEGORY,sum(s.sales) as TOTAL_SALES from book b join book_sales s on b.book_id=s.book_id
WHERE TO_CHAR(s.SALES_DATE,'YYYY-MM')='2022-01'
group by b.category
order by b.category asc