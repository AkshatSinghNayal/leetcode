class Solution {
public:

    int reverseNo(int n) {
        long long rev = 0; 
        int temp = n;

        while (temp != 0) {
            int digit = temp % 10;
            rev = rev * 10 + digit;
            temp /= 10;

            
            if (rev > INT_MAX || rev < INT_MIN) return 0;
        }

        return (int)rev;
    }

    int reverse(int x) {
         return reverseNo(x);
        
    }
};
