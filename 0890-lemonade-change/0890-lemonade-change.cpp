class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0, twenty = 0;
        for (auto it : bills) {
            if (it == 5) {
                five += 1;
            } else if (it == 10) {
                if (five <= 0)
                    return false;
                ten += 1;
                five -= 1;
            } else if (it == 20) {
               if(ten>0 && five>0){
                    ten-=1;
                    five-=1;
               }
               else if( five>=3 ){
                    five-=3;
               }
               else{
                return false;
               }
                
            }
        }
        return true;
    }
};