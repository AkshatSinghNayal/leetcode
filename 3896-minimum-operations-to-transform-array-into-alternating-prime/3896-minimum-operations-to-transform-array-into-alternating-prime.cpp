class Solution {
public:
    
    bool isPrime(int n) {
    if (n <= 1) return false;   // 0 and 1 are not prime
    if (n <= 3) return true;    // 2 and 3 are prime

    if (n % 2 == 0 || n % 3 == 0) return false;

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }

    return true;
}

    int minOperations(vector<int>& nums) {
        int count = 0; 
        int n = nums.size(); 
        for(int i = 0;i<n ;i++ ){
            if( i&1 ){
                int temp = nums[i]; 
                while(isPrime(temp)){
                    temp++;
                    count++; 
                }
            }
            else{
                int temp = nums[i];
                while(!isPrime(temp)){
                    count++;
                    temp++;
                }
                
            }
        }
        return count;
    }
};