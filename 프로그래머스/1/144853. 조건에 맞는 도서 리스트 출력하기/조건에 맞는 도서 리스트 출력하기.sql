SELECT book_id,DATE_FORMAT(published_date, '%Y-%m-%d') as published_date
FROM book
WHERE category = '인문' and published_date like '2021%'
order by published_date