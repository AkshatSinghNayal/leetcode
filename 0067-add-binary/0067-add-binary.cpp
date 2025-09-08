class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size() -1 ; 
        int m = b.size() -1;
        string result ; 
        int carry = 0 ;


        while(n>= 0 || m>= 0 || carry!=0 ){
            int digit1 = (n<0) ? 0 : (a[n]-'0'); 
            int digit2 = (m<0) ? 0 : (b[m]-'0');
            int sum = digit1+digit2+carry;
            result.push_back(((sum%2)+'0'));
            carry = sum/2 ;
            n--;m--;


        }
        reverse(result.begin(),result.end());
        return result ;
    }
};