/*
Example Dictionary (Alien Language):
text
["baa", "abcd", "abca", "cab", "cad"]
Ye alien language ke sorted words hain.

Step 1: Adjacent Words Compare Karo
Words ko pairwise compare karoge:

Compare "baa" and "abcd"

Compare "abcd" and "abca"

Compare "abca" and "cab"

Compare "cab" and "cad"

Step 2: Pehla Character Jahan Difference Ho
"baa" vs "abcd":

b vs a → Different

Toh alien language me 'b' pehle aata hai 'a' se.

"abcd" vs "abca":

a vs a → Same

b vs b → Same

c vs c → Same

d vs a → Different

Toh 'd' pehle aata hai 'a' se.

"abca" vs "cab":

a vs c → Different

Toh 'a' pehle aata hai 'c' se.

"cab" vs "cad":

c vs c → Same

a vs a → Same

b vs d → Different

Toh 'b' pehle aata hai 'd' se.

Step 3: Extract Relationships (Edges)
Alien letter order relations:

b → a

d → a

a → c

b → d

Step 4: Build Directed Graph from These Edges
Vertically directed edges from above relations.

Step 5: Topological Sort of Graph
Sort karte hain graph ko taaki order mile ki kis character ke baad kya aata hai.

Is example ka possible order ho sakta hai:
b → d → a → c

Summary
Dictionary ke sorted words se hum edges derive karte hain.

Fir graph se topological sort karke order find karte hain.
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace std;

void compareString(string& s1,string& s2,unordered_map<char,vector<char>> &adj) {
    int len= min(s1.size(),s2.size());
    for(int i=0;i<len;i++) {
        if(s1[i]!=s2[i]) {
            adj[s1[i]].push_back(s2[i]);
            break;
        }
    }
}

int main() {
    vector<string> strs = {"baa", "abcd", "abca", "cab", "cad"};
    int n=strs.size();
    unordered_map<char,vector<char>> adj;
    for(int i=0;i<n-1;i++) {
        compareString(strs[i],strs[i+1],adj);
    }
    // now i will use topology using bfs

    unordered_set<char> vertices;
    unordered_map<char, int> indegree;
    for(auto str:strs) {
        for(char c:str) {
            vertices.insert(c);
        }
    }

    for(auto node:vertices) {
        indegree[node]=0;
    }

    for(auto [u,v]:adj) {
        for(char node:v) {
            indegree[node]++;
        }
    }

    queue<char> q;
        for (auto& [node, deg] : indegree) {
            if (deg == 0) {
            q.push(node);
        }
    }

    vector<char> ans;

    while(!q.empty()) {
        char front = q.front();
        ans.push_back(front);
        q.pop();
        for(auto neighbor:adj[front]) {
            indegree[neighbor]--;
            if(indegree[neighbor]==0){
                q.push(neighbor);
            }
        }
    }

    if(ans.size()!=vertices.size()) {
        cout<<"Cycle exists"<<endl;
        return 0;
    }
    for(auto c:ans) {
        cout<<c<<" ";
    }
    cout<<endl;
    return 0;

}
