class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        unordered_map<int,int>mp;
        for(auto& it : nums ){
            auto temp = it ; 
            while( temp ){
                int Tempdigit = temp%10;
                mp[Tempdigit]++;
                temp/=10;  
            }
        }
        return mp[digit];
    }
};