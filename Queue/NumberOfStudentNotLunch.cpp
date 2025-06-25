/*
Problem ka Background:
- School mein lunch time hai.
- Do tarah ke sandwiches hain:
- 0 → circular sandwich
- 1 → square sandwich
- Students ek queue mein khade hain.
- Sandwiches ek stack mein hain (top se serve hote hain).
- Har student ko ya to 0 ya 1 pasand hai.

Rules:
- Har step mein, queue ka front student dekhta hai stack ke top sandwich ko.
- Agar sandwich uski pasand ka hai → wo sandwich le leta hai aur queue se nikal jaata hai.
- Agar pasand nahi hai → wo queue ke end mein chala jaata hai.
- Ye process tab tak chalta hai jab tak koi bhi student top sandwich lena nahi chahta.

No of student no lunch we have to return
https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/
// Input: students = [1,1,0,0], sandwiches = [0,1,0,1]
// Output: 0
// Explanation: All students can eat lunch. No student is unable to eat lunch.
*/

class Solution {
    public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
       if(students.empty() || sandwiches.empty()) {
           return 0; // If either students or sandwiches is empty, return 0
       }
       queue<int> studentQueue; // Queue for students
       for(int i=0;i<students.size();i++) {
           studentQueue.push(students[i]); // Add each student to the queue
       }
       int rotate =0; // Counter for the number of rotations
       while (!studentQueue.empty()) {
            if(studentQueue.front() == sandwiches[0]) {
                studentQueue.pop(); // Student takes the sandwich and leaves the queue
                sandwiches.erase(sandwiches.begin()); // Remove the sandwich from the stack
                rotate=0;
            }
            else {
                studentQueue.push(studentQueue.front()); // Student goes to the end of the queue
                studentQueue.pop();
                rotate++; // Increment the rotation counter
            }
            if(rotate ==studentQueue.size()) {
           return studentQueue.size(); // If no student can take the sandwich, return the size of the queue
       }
       }
       
       return studentQueue.size(); // Return the number of students unable to eat lunch
}
};


//                 IMPORTANT QUESTION