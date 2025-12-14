class Solution {
public:

    void reverseStr( string& s , int start , int end ){
        while( start<end){
            swap( s[start++] , s[end--]) ; 
        }
    }

    string reverseWords(string s) {
        set<char> st ; int n = s.size() ; 
        st.insert('a');  st.insert('e');  st.insert('i');  st.insert('o');  st.insert('u'); 
        int i = 0 , j = 0 ; 
        int count= 0 ; int firstCount ; 
         while( i< n && j < n  ){

            while( j< n && s[j]!= ' '){
                if(st.count(s[j]))count++; 
                j++; 
            }   
            j++; 
            i = j  ;
            firstCount = count; 
            break; 
        }
        while( i<n && j< n ){
             count = 0 ; 
            while( j < n && s[j]!= ' '){
                if(st.count(s[j]))count++; 
                j++; 
            }
            if( count == firstCount ){
                reverseStr( s, i , j-1 ); 
            }
            j++; 
            i = j; 

        }
        return s ; 
    }

};