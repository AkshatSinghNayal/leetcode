class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string>st(bank.begin(),bank.end()); 
        string traverse = "ACGT"; 
        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>>pq;
        pq.push({0,start});

        while(!pq.empty()){
            auto [ rank , temp ] = pq.top(); pq.pop();

            if( temp  == end ){
                return rank;
            }

            for(int i  = 0 ;i<temp.size(); i++ ){                
                string ok = temp; 
                for(auto& it : traverse){
                    ok[i] = it;

                    if(st.count(ok)){
                        pq.push({rank+1 , ok }); 
                        st.erase(ok);
                    }
                
                }
            }

        }
        return -1; 

    }
};