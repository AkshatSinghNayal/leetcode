class Solution {
public:
    int minOperations(vector<int>& a) {
        int n=a.size();
        int pos0=0,posLast=0,ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(a[i]==0) pos0=i;
            if(a[i]==n-1) posLast=i;
        }
        bool inc=true,dec=true;
        for(int i=0;i<n;i++){
            if(a[(i+1)%n]!=(a[i]+1)%n){
                inc=false;
                break;
            }
        }
        if(inc) ans=min({ans,pos0,n-pos0+2});
        for(int i=0;i<n;i++){
            if(a[(i+1)%n]!=(a[i]-1+n)%n){
                dec=false;
                break;
            }
        }
        if(dec) ans=min({ans,posLast+1,n-pos0});
        return ans==INT_MAX?-1:ans;
    }
};