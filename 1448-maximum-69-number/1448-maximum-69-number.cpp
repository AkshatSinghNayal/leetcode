class Solution {
public:
    int maximum69Number (int num) {
        int maxi =0; 
        string result = to_string(num);
        int right = result.size()-1;
        while(right>=0){
            if((result[right]-'0') <9 ){
                maxi = right;
            }
            

            right--;
        }
        result[maxi] ='9';
         num = stoi(result);
        return num;
    }
};