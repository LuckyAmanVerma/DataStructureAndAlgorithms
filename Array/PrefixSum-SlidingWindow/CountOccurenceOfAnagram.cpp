/*
Count occurence of anagram in a string
Given two strings s and p, return the number of occurrences of p's anagrams in s
Approach: Use a sliding window technique with frequency maps to count occurrences of anagrams.
Example: For s = "cbaebabacd" and p = "abc", the anagrams of p in s are "cba" and "bac", so the output is 2.
Time Complexity: O(n + m), where n is the length of s and m is the length of p.

*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

int countAnagrams(string s,string p){
    int k=p.size();
    int ssize =s.size();
    int i=0;
    int j=0;
    map<char,int> count;
    map<char,int> pcount;
    int result =0;

    for(char p_char:p){
        pcount[p_char]++;
    }

    while(j<ssize){   // s = "c b a e b a b a c d" and p = "a b c"
        // i want to fill the map like for the first k characters like if first three characters are abc then map will be like a:1, b:1, c:1
        count[s[j]]++;
        if(j-i+1<k){
            j++;
        }
        else if(j-i+1==k){
           // i want to compare pcount and count map
            if(count==pcount){
                result++;
            }
            // now i want to remove the first character from the map
            count[s[i]]--;
            if(count[s[i]]==0){
                count.erase(s[i]);
            }
            i++; j++;
        }

    }
    return result;
}

int main(){
    string s="cbaebabacd";
    string p="abc";
    cout<<"Ocurrence of "<<p<<" in string "<<s<<" is "<<countAnagrams(s,p);
}