class Solution {
public:
    vector<int> plusOne(vector<int>& v) {
        reverse(v.begin(),v.end());
         
        int carry = 1 ;
        for( int i = 0;  i<v.size();i++){
           int sum = v[i]+carry;
            carry = sum/10; 
            v[i] = sum%10;
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