/*+-----------------------+
  | Start Iteration #1    |
  +-----------------------+
             |
             v
+---------------------------------------------+
| low  = min(arr[0]+k, arr[1]-k)              |
|      = min(3+3, 9-3) = min(6,6) = 6         |
+---------------------------------------------+
             |
             v
+---------------------------------------------+
| high = max(arr[0]+k, arr[4]-k)              |
|      = max(3+3, 20-3) = max(6,17) = 17      |
+---------------------------------------------+

Input: k = 2, arr[] = {1, 5, 8, 10}
Output: 5
Explanation: The array can be modified as {1+k, 5-k, 8-k, 10-k} = {3, 3, 6, 8}.The difference between the largest and the smallest is 8-3 = 5.
Based on it’s a classic greedy‐plus‐sorting solution
time complexity is O(nlogn) and space complexity is O(1).

बात “टावर (या किसी भी मानों) को एक-दूसरे के जितना पास संभव हो उतना पास लाने” की है—जिसका मतलब साफ़-साफ़ है:

1. एक समूह के सभी मानों का **range** या **spread** यानि  
   max(समूह) − min(समूह)  
   जितना कम, उतना “क्लोज़” या “पास”।

2. Dummy उदाहरण  
   मान लीजिये चार टावर हैं, उनकी ऊँचाइयाँ = [2, 8, 10, 15]  
   • अभी सबसे छोटी = 2, सबसे बड़ी = 15  
   •	range = 15 – 2 = 13  

3. “जितना पास ला पाओ” मतलब  
   यदि आप समायोजन करके (अप या डाउन) उन्हें कुछ ऐसे सेट कर देते कि मान लीजिये  
       [6, 7, 9, 10]  
   • अब सबसे छोटी = 6, सबसे बड़ी = 10  
   •	range = 10 – 6 = 4  

4. अर्थ  
   • पहले मान काफी बिखरे थे (2 से 15), range=13  
   • अब सभी मान एक छोटे से interval (6 से 10) में हैं, range=4  
   • इसलिए हम कहते हैं कि टावर “क्लोज़ इन हाइट” हो गए—उनकी ऊँचाइयों में अब कम विचलन (variation) है।

5. जब भी हम कहते हैं “टावर को क्लोज़ इन हाइट लाना” →  
   हम बस यही चाहते हैं कि उनके बीच का **max–min** यथासंभव छोटा हो।

*/

class Solution { // {3, 9, 12, 16, 20} k=3;
  public:
    int getMinDiff(vector<int> &arr, int k) {
       int length = arr.size();
       if (length == 1) return 0;
       std::sort(arr.begin(), arr.end());
       int ans = arr[length - 1] - arr[0];
       int smallest = arr[0] + k;
       int largest = arr[length - 1] - k;
       for (int i = 1; i < length; i++) {
            int min_height = std::min(smallest, arr[i] - k);
            int max_height = std::max(largest, arr[i - 1] + k);
            if (min_height < 0) continue;
            ans = std::min(ans, max_height - min_height);
        }
        return ans;
    }
};
