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
        CASE 
            WHEN MAX(n.number) IS NOT NULL THEN MAX(n.number)
            ELSE NULL
        END AS xd
    FROM 
        solve AS n
    WHERE 
        n.cnt = 1
)
SELECT 
    f.xd  as num
FROM 
    final AS f;
