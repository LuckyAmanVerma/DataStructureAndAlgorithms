/*
Minimum Size Subarray Sum
Given an array of positive integers nums and a positive integer target, return the minimal length of a
Input:[2,3,1,2,4,3], target=7
Output: 2
Using Sliding Window Approach - O(n) time, O(1) space
in Example Dry Run: nums = [2,3,1,2,4,3], target = 7
→ Start: sum = 0, minLength = ∞
i = 0 → sum = 2 → not enough
i = 1 → sum = 5 → not enough
i = 2 → sum = 6 → not enough
i = 3 → sum = 8 ✅ → try shrink: → length = 4 → min = 4 → remove 2 → sum = 6
i = 4 → sum = 10 ✅ → length = 3 → min = 3
→ remove 3 → sum = 7 ✅
→ length = 2 → min = 2 ✅
→ remove 1 → sum = 6

Detail for code -- Jab i = 3 hota hai, tab:
- Tumhara window hai start = 0 se end = 3 (inclusive), yani elements [2, 3, 1, 2].
→ sum = 2 + 3 + 1 + 2 = 8
- Since sum (8) ≥ target (7), hum try karte hain window ko chhota karke dekhne ka:
- • Pehle window ki length nikaalte hain:
currLength = end - start + 1 = 3 - 0 + 1 = 4 → minLength = 4
- • Ab shrink karte hain window ko left se:
- Hume lagta hai ki shayad chhoti subarray bhi sum ≥ 7 de de
- Toh hum sum -= nums[start] karte hain → sum = 8 - nums[0] = 8 - 2 = 6
- Aur start++ karke window ki left boundary aage khiskaa dete hain → start = 1
- 

*/

//Input:[2,3,1,2,4,3], target=7 Output: 2
int minimumSizeSubArraySum(vector<int> num,int target) {
    int n=num.size();
    int start=0,end=0;
    int sum=0;
    int minLength=INT_MAX;

    for(int i=0;i<n;i++) {
        sum+=num[i];
        while(sum>=target) {
            minLength=min(minLength,i-start+1 );
            sum-=num[start]; // removing the one before
            start+=1;
        }
    }

    return minLength==INT_MAX ?0:minLength;
}