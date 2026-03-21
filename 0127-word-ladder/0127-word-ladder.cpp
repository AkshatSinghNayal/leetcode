class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end()); 
        if(!st.count(endWord))return 0;

        queue<pair<string,int>> q; 
        q.push({beginWord,1}); 

        while(!q.empty()){
            auto [tempo , dist ]  = q.front(); q.pop(); 

            
            for(int i  = 0 ; i< tempo.size(); i++ ){
                string temp = tempo;
                for(char ch = 'a' ;ch<='z' ;ch++ ){
                    temp[i] = ch;
                    if(temp == endWord ) return dist+1;
                    if( st.count(temp)){
                        st.erase(temp);
                        q.push({temp, dist+1});
                    }
                }
            }
        }

        return 0 ;     

    }
};