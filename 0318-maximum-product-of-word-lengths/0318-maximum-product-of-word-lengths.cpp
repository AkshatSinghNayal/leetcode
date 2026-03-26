class Solution {
public:
    int maxProduct(vector<string>& words) {
        
        long long maxi = 0; 
        int n  = words.size() ; 
        for(int i = 0 ; i< n-1 ;i++ ){
            string temp = words[i]; 
            vector<int>ans(26,-1);
            for(auto& it : temp){
                ans[it-'a']++; 
            }

            for(int j = i+1 ; j<=n-1;  j++ ){
                bool flag = false;
                for(int k = 0; k<words[j].size(); k++ ){
                    if(ans[words[j][k]-'a'] != -1 ){
                        flag = true;
                        break;
                    }
                }
                    if(!flag){
                        maxi = max(maxi, (long long)words[j].size() * (long long)words[i].size());
                    } 

            }

            
        }
        return (int)maxi; 
    }
};