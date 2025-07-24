/*
First Negative Number in Subarray of size k , 
Problem: Given an array of integers and a number k, find the first negative number in every subarray of size k.
Approach: Use the sliding window technique to maintain a queue of negative numbers and their indices.
Example: For the array [-8, 2, 3, -6, 10] and k = 2, the first negative number in each subarray of size 2 is [-8, -6, -6].
Time Complexity: O(n), where n is the number of elements in the array.
*/

#include <iostream>
#include <vector>
#include<queue>

using namespace std;

void firstNegativeNumber(vector<int> array,int k) {
    int asize=array.size();
    int i,j=0;
    queue<int> q;
    while(j<asize){
        if(array[j]<0){
            q.push(array[j]);
        }
        if(j-i+1<k){
            j++;
        }
        else if(j-i+1==k){
            if(!q.empty()){
                cout<<q.front()<<endl;
            }
            else{
                cout<<0<<endl;
            }
           if(array[i]<0 && !q.empty() && array[i]==q.front()){
            q.pop();
           }
             i++; j++;
        }
   
    }
}

int main(){
    vector<int> array={-8, 2, 3, -6, 10};
    firstNegativeNumber(array,2);
}