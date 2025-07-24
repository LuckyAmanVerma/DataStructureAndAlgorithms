/*
Max value in sub arrays of size k
Given an array of integers and a number k, find the maximum value in all subarrays of size k.
Example: For the array [2, 1, 5, 1, 3, 2] and k = 3, the maximum values in the subarrays are [5, 5, 5,3].
Time Complexity: O(n), where n is the number of elements in the array.
*/

#include<iostream>
#include<list>
#include<vector>

using namespace std;

vector<int> maxValSubArray(vector<int> array,int k){
    int asize=array.size();
    int i=0;
    int j=0;
    vector<int> ans;
    list<int> l;
    while(j<asize){
        while(l.size()>0 && l.back()<array[j]){
            l.pop_back();
        }
        l.push_back(array[j]);
        if(j-i+1<k){
            j++;
        }
        else if(j-i+1==k){
            ans.push_back(l.front());
            if(array[i]==l.front()){
                l.pop_front();
            }
            i++; j++;
        }
    }
    return ans;
}

int main(){
    vector<int> array={2, 1, 5, 1, 3, 2};
    vector<int> ans =maxValSubArray(array,3);
    for(int i=0;i<ans.size();i++){
        cout<<" "<<ans[i]<<" ";
    }
}