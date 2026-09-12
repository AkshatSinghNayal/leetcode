class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        int i  = 0;
        for(auto& it : nums ){
            mp[it].push_back(i) ; 
            i++;
        }
        
        int count= 0;
        
        for(auto& [ ele , vec ] : mp ){
            if(vec.size()>=3){
                int initial = abs(vec[1]-vec[0]); 
                int i = 2; bool ok = true;
                while(i<vec.size()){
                    if(abs(vec[i]-vec[i-1]) != initial){
                        ok=false;
                        break;
                    }
                    i++;
                }
                if(ok) count++;
            }
            
        }
        
        return count;
    }
};