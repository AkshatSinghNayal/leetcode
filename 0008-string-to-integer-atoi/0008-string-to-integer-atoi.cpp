////////////////////// I Bow To Lord Krishna And Lord Hanuman ///////////
// class Solution {
// public:
//     int myAtoi(string s) {
//         int i = 0;
//         int sign = 1;  // Initialize sign to 1 (positive by default)
//         int num = 0;
        
//         //  Skip leading spaces
//         while (i < s.size() && s[i] == ' ') {
//             i++;
//         }
        
//         // Handle sign if present
//         if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
//             sign = (s[i] == '-') ? -1 : 1;
//             i++;  // Move past the sign
//         }
        
//         //  Convert digits to number
//         while (i < s.size() && isdigit(s[i])) {
//             int digit = s[i] - '0';
            
//             // Check for overflow before updating num
//             if (num > (INT_MAX - digit) / 10) {
//                 return sign == 1 ? INT_MAX : INT_MIN;
//             }
            
//             num = num * 10 + digit;  // Update num with current digit
//             i++;
//         }
        
//         //  Return the final result (considering the sign)
//         return num * sign;
//     }
// };
class Solution {
public:
    int myAtoi(string s) {
       int i=0;
        int sign=1;
        long ans=0;
        while(i<s.length() && s[i]==' ')
            i++;
        if(s[i]=='-')
        {
            sign=-1;
            i++;
        }
        else if(s[i]=='+')
            i++;
        while(i<s.length())
        {
            if(s[i]>='0' && s[i]<='9')
            {
                ans=ans*10+(s[i]-'0');
                if(ans>INT_MAX && sign==-1)
                    return INT_MIN;
                else if(ans>INT_MAX && sign==1)
                    return INT_MAX;
                i++;
            }
            else
                return ans*sign;
        }
        return (ans*sign);
    }
};