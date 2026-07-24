class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>st(wordList.begin(),wordList.end());
        priority_queue<pair<int,string>,vector<pair<int,string>>,greater<pair<int,string>>>pq;
        st.insert(beginWord); 
        pq.push({1,beginWord}); 

        while(!pq.empty()){
            auto [ith , curr] = pq.top();pq.pop();

            if( curr == endWord) return ith;

            for(int i = 0;i<curr.size();i++ ){
                string temp = curr;

                for(char ch = 'a' ;ch<='z' ;ch++ ){
                    temp[i] = ch; 
                    string processing = temp;
                    if(st.count(processing)){
                        pq.push({ ith+1 , processing});
                        st.erase(processing);
                    }
                }
            }


        }
        return 0;
    }
};