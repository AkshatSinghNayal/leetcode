class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        vector<tuple<int,int,int>>ans;
        for(auto& it : nums ){
            string temp = to_string(it); 
            sort(temp.rbegin(), temp.rend());
            int after = stoi(temp); 

            ans.push_back({after - it , after , it }); 

        }

        sort(ans.begin() , ans.end(), [&](auto a , auto b ){
            auto [gain1 , after1 , it1 ] = a;
            auto [gain2 , after2 , it2 ]= b; 

            return gain1>gain2;

        }); 
        long long score= 0; 
        for(auto& [ gain , after , it ] : ans ){

            // cout<< gain << " " << after << " "<< it << endl; 

            if( gain == 0 ) score+=it;
            else{
                if( k > 0 ){
                    score+=after;
                    k--; 
                }
                else{
                    score+=it;
                }
            }
        }

        return score ; 
    }
};