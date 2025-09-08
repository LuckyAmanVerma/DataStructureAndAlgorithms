
/*
Find the representative (root) of the set that contains element i
Input: element i
Output: representative (root) of the set containing i
DSU - FIND , UNION

vector<int> parent = {0,1,2,3,4,5,6,7,8,9,10};
i=5;
Using Compression technique first time , it take the same n time , but after that it only take O(1) time.
*/
#include<iostream>
#include<vector>
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


int main() {
    vector<int> parent(100);
    vector<int> rank(100,0);
    for(int i=0;i<100;i++) {
        parent[i]=i;
    }
    cout<<find(10,parent)<<endl;
}