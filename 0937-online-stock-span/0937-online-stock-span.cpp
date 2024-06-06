class StockSpanner {
public:
     stack<int>st1;
     stack<int>st2;
     StockSpanner() {

    }
    
    int next(int price) {
      int count =1;
      while(!st1.empty() and st1.top()<=price){
        st1.pop();
        count+=st2.top();
        st2.pop();

      }
      st1.push(price);
      st2.push(count);
      return  count;
    }
};

