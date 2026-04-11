class Solution {
public:
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        int n=nums1.size();
        vector<string>v;
        for(int i=0;i<n;i++){
            string ns=string(nums1[i],'1');
            ns+=string(nums0[i],'0');
            v.push_back(ns);
        }
        sort(v.begin(),v.end(),[](const string&a, const string& b){
            return a+b>b+a;
        });
        string s="";
        for(auto it:v){
            s+=it;
        }
        //is a binary string
        int mod=1e9+7;
        long long decimal=0;
        for(char bit:s){
            decimal=(decimal*2 + (bit-'0')) %mod;
        }
    return decimal;
    }
};