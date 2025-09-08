/*
Similar String Group using DSU approach
Final Parent after all union 
Parent: [0,  0,  0,  3]

*/

#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;


int find(int i,vector<int> &parent) {
    if(i==parent[i]) {
        return i;
    }
    return parent[i]=find(parent[i],parent);
}

void Union(int x,int y,vector<int> &parent,vector<int> &rank) {
    int x_parent=find(x,parent);
    int y_parent=find(y,parent);
    if(x_parent!=y_parent) {
        if(rank[x_parent]<rank[y_parent]) {
            parent[x_parent]=y_parent;
        } else if(rank[x_parent]>rank[y_parent]) {
            parent[y_parent]=x_parent;
        } else {
            parent[y_parent]=x_parent;
            rank[x_parent]++;
        }
    }
}

bool areSimilar(string& s1,string& s2) {
    if(s1==s2) return true;
    if(s1.size()!=s2.size()) return false;
    vector<int> diff;

    for(int i=0;i<s1.size();i++) {
        if(s1[i]!=s2[i]) diff.push_back(i);
        if(diff.size()>2) return false;
    }
    if(diff.size()!=2) return false;
    return s1[diff[0]]==s2[diff[1]] && s1[diff[1]]==s2[diff[0]];
}

int main() {
    vector<string> strs = {"tars","rats","arts","star"};
    int n=strs.size();
    vector<int> parent(n);
    vector<int> rank(n,0);
    for(int i=0;i<n;i++) {
        parent[i]=i;
    }

    for(int i=0;i<strs.size();i++) {
        for(int j=i+1;j<strs.size();j++) {
            if(areSimilar(strs[i],strs[j])) {
                Union(i,j,parent,rank);
            }
        }
    }

    unordered_set<int> uniqueParents;
    for(int i = 0; i < n; i++) {
        uniqueParents.insert(find(i, parent));
    }
    int totalGroups = uniqueParents.size();

    cout<<"Output:"<<" "<<totalGroups;

}