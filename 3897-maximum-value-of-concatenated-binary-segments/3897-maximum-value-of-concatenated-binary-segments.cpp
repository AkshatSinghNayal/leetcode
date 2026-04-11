class Solution {
public:
    int M=1e9+7;
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        int n=nums1.size();
        //1 represent the no of 1s in the ith seg 
        //0 represent the no of 0s in the ith seg 
        vector<string>vec;
        for(int i =0;i<n;i++){
            string temp="";
            
            temp+=string (nums1[i],'1');
            temp+=string (nums0[i],'0');

            vec.push_back(temp);
        }
        sort(vec.begin(),vec.end(),[](const string &a ,const string &b){
            return a+b>b+a;
        });
        long long ans=0;
        for(auto s:vec){
            for(auto c:s){
                ans=((ans<<1)+(c-'0'))%M;
            }
        }
        return ans;
    }
};