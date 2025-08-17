class Solution {
public:
    vector<int> plusOne(vector<int>& v) {
        reverse(v.begin(),v.end());
        int sum  = 1 ; 
        int carry = 0 ;
        for( int i = 0;  i<v.size();i++){
            sum = v[i]+sum+carry;
            carry = sum/10 ;
            sum = sum%10;
            v[i] = sum ; 
            sum=sum/10;
            
        }
        if(carry!=0){
            v.push_back(carry%10);
            carry=carry/10;
        }
        reverse(v.begin(),v.end());
        return v;
    }
};