/*
Similar Strings Groups using DSU
Given a list of strings strs, two strings are similar 
if we can swap two letters (in different positions) of the first string to get the second string. 
For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, 
but "star" is not similar to "tars", "rats", or "arts". 
 Input:["tars","rats","arts","star"]
 Output:2

1.  Function that check areString similar directly or indirectly , 
    For indirectly same , length will be same , total different char willbe exactly two , 
    Then we simply check those  (s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]]);
*/

#include<iostream>
#include<vector>
#include<string>
using namespace std;


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
    int count =0;

    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {  // j=i+1 to avoid double counting  , as j!=i will do duplicate
            if(areSimilar(strs[i],strs[j])) count++;
        }
    }

    cout<<"Output:"<<count;

    return 0;
}