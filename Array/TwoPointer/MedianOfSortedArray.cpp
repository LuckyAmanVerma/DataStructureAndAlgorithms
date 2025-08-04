/*
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
*/

#include <iostream>
#include <vector>
using namespace std;

double median(vector<int> a1,vector<int> a2) {
    int a1_size=a1.size();
    int a2_size=a2.size();
    int i=0;
    int j=0;
    int k=0;
    int total=a1_size +a2_size;
    int idx1 =(total/2)-1;
    int idx2 =total/2;
    int element1=0;
    int element2=0;

    while(i<a1_size && j<a2_size) {
        if(k==idx1){
            element1= a1[i]<=a2[j] ? a1[i] : a2[j];
        }
        if(k==idx2){
            element2= a1[i]<=a2[j] ? a1[i] : a2[j];
        }
        if(a1[i]<=a2[j]){
            i++;
        }
        else {
            j++;
        }
        k++;

    }

    while(i<a1_size) {
        if(k==idx1){
            element1=a1[i];
        }
        if(k==idx2){
            element2=a1[i];
        }
        i++;
        k++;
    }

    while(j<a2_size) {
        if(k==idx1){
            element1=a2[j];
        }
        if(k==idx2){
            element2=a2[j];
        }
        j++;
        k++;
    }

        if(total%2==0) {
            return (element1+element2)/2.0;
        }
        return element2;
    }

    int main() {
        vector<int> a1 = {1, 3};
        vector<int> a2 = {2, 4};
        cout << "Median: " << median(a1, a2) << endl; // Output: 2.50000
        return 0;
    }