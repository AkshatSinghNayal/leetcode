class Solution {
public:
    string largestGoodInteger(string num) {
        int maxi = -1 ; 
        int count = 1 ; 
        for( int i = 1 ; i<num.size() ; i++){
            if(num[i] == num[i-1]){
                count++;
                if( count == 3){
                    maxi = max ( maxi , num[i]-'0');
                }
            }else{
                count=1;
            }
        }
        return maxi<0 ? "" : string(3 , '0'+maxi);
    }
};