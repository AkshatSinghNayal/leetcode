class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        long long total = accumulate(source.begin(),source.end(),0LL);
        total = total-accumulate(target.begin(),target.end(),0LL); 
        return total == 0;
    }
};