class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
       int Bottlesdrunk=0;
       int empty=0;
       while(numBottles+empty>=numExchange){
        empty+=numBottles;
        Bottlesdrunk+=numBottles;
        numBottles=0;
        empty-=numExchange;
        numBottles++;
        numExchange++;
       } 
       return Bottlesdrunk+numBottles;
    }
};