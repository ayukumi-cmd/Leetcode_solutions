WITH FirstOrders AS (
    -- Find the first order for each customer
    SELECT 
        customer_id, 
        MIN(order_date) AS first_order_date
    FROM 
        Delivery
    GROUP BY 
        customer_id
),
pref AS (
    -- Get the preferred delivery date for each customer's first order
    SELECT 
        d.customer_id,
        d.customer_pref_delivery_date AS pref_order
    FROM 
        FirstOrders AS f 
    JOIN 
        Delivery AS d 
    ON  
        f.customer_id = d.customer_id 
        AND f.first_order_date = d.order_date
),
Solve AS (
    -- Count the immediate orders (when preferred date = order date) and total orders
    SELECT
        COUNT(CASE WHEN p.pref_order = f.first_order_date THEN 1 END) AS immediate_orders,
        COUNT(*) AS total_orders
    FROM 
        pref AS p  
    JOIN 
        FirstOrders AS f 
    ON 
        p.customer_id = f.customer_id
)
-- Calculate the percentage of immediate orders
SELECT 
    ROUND((immediate_orders * 100.0) / total_orders, 2) AS immediate_percentage
FROM 
    Solve;
