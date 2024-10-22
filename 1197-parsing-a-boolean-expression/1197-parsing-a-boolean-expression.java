class Solution {
    public char solveOp(char op, ArrayList<Character> values) {
        if (op == '!') 
            return values.get(0) == 't' ? 'f' : 't';

        if (op == '&'){
            for(int i=0; i<values.size(); i++){
                if(values.get(i)=='f'){
                    return 'f';
                }
            }
            return 't';
        }
        if(op=='|'){
            for(int i=0; i<values.size(); i++){
                if(values.get(i)=='t'){
                    return 't';
                }
            }
            return 'f';
        }

        return 't'; 
    }

    public boolean parseBoolExpr(String expression) {
        Stack<Character> stack = new Stack<>();
        int n = expression.length();
        
        for (int i = 0; i < n; i++) {
            char c = expression.charAt(i);
            if (c == ',') continue;

            if (c == ')') {
                ArrayList<Character> values = new ArrayList<>();
             
                while (stack.peek() != '(') {
                    values.add(stack.pop());
                }
                stack.pop();
                char op = stack.pop(); 
                stack.push(solveOp(op, values));  
            } else {
                stack.push(c); 
            }
        }
        return stack.peek() == 't';
    }
}