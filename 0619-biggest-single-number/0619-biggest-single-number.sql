WITH solve AS (
    SELECT 
        num AS number, 
        COUNT(num) AS cnt
    FROM 
        MyNumbers
    GROUP BY 
        num
    ORDER BY 
        num
),
final AS (
    SELECT 
        MAX(s.number) AS xd
    FROM 
        solve AS s
    WHERE 
        s.cnt = 1
)
SELECT 
    f.xd as num 
FROM 
    final AS f;
