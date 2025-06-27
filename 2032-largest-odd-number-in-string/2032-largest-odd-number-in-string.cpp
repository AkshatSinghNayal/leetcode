class Solution {
public:
    string largestOddNumber(string num) {
        int n = num.size();
        while(n>0){
            if(((num[n-1]-'0')&1) !=0){
                break;
            }
            else{
                n--;
            }
            
        }
        num.resize(n);
        return num;
    }
};