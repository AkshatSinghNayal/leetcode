class Solution {
  public:
    int countDivisors(int n) {
        int count = 0;
        int ok = (int)sqrt(n);
        
        for (int i = 1; i <= ok; i++) {
            if (n % i == 0) {
                
                if (i % 3 == 0) count++;
                
                int other = n / i;
                if (other != i && other % 3 == 0) count++; 
            }
        }
        
        return count;
    }
};
