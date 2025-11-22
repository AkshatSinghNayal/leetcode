class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](vector<int>&a,vector<int>&b){
            return a[1]<b[1];
        });
        int ans=0;
        int a=-1,b=-1;
        for(auto &i:intervals){
            if(b<i[0]){
                b=i[1];
                a=b-1;
                ans+=2;
            }
            else if(a<i[0]){
                a=min(i[1]-1,b);
                b=i[1];
                ans++;
            }
        }
        return ans;
    }
};