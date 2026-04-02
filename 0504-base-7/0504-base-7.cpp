class Solution {
public:
    string convertToBase7(int num) {
        if(num == 0 ) return "0"; 
        string result = "";
        int temp = abs(num);


        while(temp){
            int tempo = temp%7;
            result+=to_string(tempo);
            temp=temp/7;
        }
        reverse(result.begin(),result.end());
        if(num<0) result.insert(result.begin(),'-');
        return result;
    }
};