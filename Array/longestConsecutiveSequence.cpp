/*
Longest Consecutive Sequence
Medium
*/

#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
using namespace std;

int bruteForce(vector<int> &nums) {
    int n=nums.size();
    if(n==0) return 0;
    int longestStreak=1;
    for(int i=0;i<n;i++) {
        int currentNum=nums[i];
        int currentStreak=1;
        while(find(nums.begin(),nums.end(),currentNum+1)!=nums.end()) {
            currentNum+=1;
            currentStreak+=1;
        }
        longestStreak=max(longestStreak,currentStreak);
    }
    return longestStreak;
}

int longestConsecutiveOptimal(vector<int>& nums) {
        int size=nums.size();
        if(size==0) return 0;
        unordered_set<int> numSet(nums.begin(),nums.end());
        unordered_map<int,bool> visited;
        for(int num:nums) visited[num]=false;
       int longestStreak=1;
       
       
           for(auto num:numSet) {
        if(!visited[num]) {
            visited[num]=true;
            int currentStreak = 1;

            int left = num - 1;
            while(numSet.find(left) != numSet.end() && !visited[left]) {
                visited[left] = true;
                currentStreak++;
                left--;
            }

            int right = num + 1;
            while(numSet.find(right) != numSet.end() && !visited[right]) {
                visited[right] = true;
                currentStreak++;
                right++;
            }

            longestStreak = max(longestStreak, currentStreak);
        }
    }

       return longestStreak;
    }



int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    vector<int> parent(1000);
    vector<int> rank(1000,0);
    for(int i=0;i<1000;i++) {
        parent[i]=i;
    }
    int result = longestConsecutiveOptimal(nums);
    cout << "Length of Longest Consecutive Sequence: " << result << endl;
    return 0;
}