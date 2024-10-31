SELECT 
    q.member_name AS MEMBER_NAME, 
    w.review_text AS REVIEW_TEXT, 
    DATE_FORMAT(w.review_date, '%Y-%m-%d') AS REVIEW_DATE
FROM 
    member_profile q 
JOIN 
    rest_review w ON q.member_id = w.member_id 
WHERE 
    q.member_id = (
        SELECT r.member_id 
        FROM rest_review r 
        GROUP BY r.member_id 
        ORDER BY COUNT(r.member_id) DESC 
        LIMIT 1
    ) 
ORDER BY 
    w.review_date ASC, 
    w.review_text ASC;