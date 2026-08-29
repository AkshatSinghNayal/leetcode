class Solution {
public:

    bool solve( long long d1 , long long d2 , long long r1 , long long r2 , long long mid ){
        long long lcm = (r1 / gcd(r1 , r2))*r2; 

        return mid-mid/r1 >= d1 and mid- mid/r2 >= d2 and mid - mid/lcm>=d1+d2; 
    }

    long long minimumTime(vector<int>& d, vector<int>& r) {
        long long d1 = d[0] , d2 = d[1] , r1 = r[0] , r2 = r[1];
        long long high = 1; 
        while(!solve(d1 , d2 , r1 , r2 , high)){
            high*=2;
        }
        long long low = 1 ;
        long long mid = 1;
        while( low<=high ){
            mid = low+(high-low)/2;

            if(solve(d1,d2,r1,r2,mid)){
                high =mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};