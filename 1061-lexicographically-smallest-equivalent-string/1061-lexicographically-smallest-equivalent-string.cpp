class Disjointset {
public:
    vector<int> size, parent, minChar; 

    Disjointset(int V) {
        size.resize(V, 1); 
        parent.resize(V); 
        minChar.resize(V);

        for(int i = 0; i < V; i++){
            parent[i] = i; 
            minChar[i] = i; // Track the smallest character in the set
        }
    }

    int findParent(int n) {
        if(parent[n] == n) return n; 
        return parent[n] = findParent(parent[n]);
    }

    void unionBySize(int u, int v) {
        int NodeA = findParent(u); 
        int NodeB = findParent(v); 

        if(NodeA == NodeB) return; 

        if(size[NodeA] > size[NodeB]) {
            parent[NodeB] = NodeA; 
            size[NodeA] += size[NodeB];
            // Update the minimum character for the new root
            minChar[NodeA] = min(minChar[NodeA], minChar[NodeB]);
        }
        else {
            parent[NodeA] = NodeB; 
            size[NodeB] += size[NodeA];
            // Update the minimum character for the new root
            minChar[NodeB] = min(minChar[NodeA], minChar[NodeB]);
        }
    }
    
    // Helper to get the smallest character of a set
    int getSmallest(int n) {
        return minChar[findParent(n)];
    }
}; 

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        Disjointset d(26); 
        int n = s1.size(); 
        
        for(int i = 0; i < n; i++) {
            int ch1 = s1[i] - 'a'; 
            int ch2 = s2[i] - 'a'; 
            d.unionBySize(ch1, ch2); 
        }

        string result = ""; 
        for(auto& it : baseStr) {
            // Use the helper to get the smallest char in that character's group
            int smallestCharIndex = d.getSmallest(it - 'a'); 
            result += (smallestCharIndex + 'a'); 
        }
        
        return result;
    }
};