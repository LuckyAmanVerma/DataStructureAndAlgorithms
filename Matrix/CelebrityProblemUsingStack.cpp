/*
Celebrity Problem using Stack
1. Push all people onto a stack.
2. While there is more than one person on the stack:
   a. Pop two people off the stack.
   b. If person A knows person B, then A cannot be the celebrity, so push B back onto the stack.
   c. If person A does not know person B, then B cannot be the celebrity, so push A back onto the stack.
3. The last person remaining on the stack is the celebrity candidate.
4. Verify the candidate by checking if everyone knows the candidate and the candidate knows no one.
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

bool knows(int a,int b , vector<vector<int>> &matrix) {
    if(matrix[a][b]==1) {
        return true;
    }
    return false;
}

int isCelebrity(vector<vector<int>> &matrix,int n) {
    stack<int> s;
    for(int i=0;i<n;i++) {
        s.push(i);
    }

    while(s.size()>1) {
        int a=s.top();
        s.pop();

        int b=s.top();
        s.pop();

        if(knows(a,b,matrix)) {
            s.push(b);
        }
        else {
            s.push(a);
        }
    }

    if(s.size()==1) {
        bool rowCheck=false;
        int rowCount =0;
         int rowNo = s.top();
        // row check 
       
        for(int i=0;i<n;i++) {
            if(matrix[rowNo][i]==0) {
                rowCount++;
            }
        }
        if(rowCount ==n) rowCheck=true;

        bool colCheck=false;
        int colCount =0;
        // row check 
        for(int i=0;i<n;i++) {
            if(matrix[i][rowNo]==1) {
                if(i==rowNo) continue;
                colCount++;
            }
        }
        if(colCount ==n-1) colCheck=true;

        if(rowCheck && colCheck) return rowNo;
        return -1;
    }
    return -1;

}

int main() {
    vector<vector<int>> matrix = {
        {0, 1, 0},
        {0, 0, 0},
        {1, 1, 0}
    };
    int n = matrix.size();
    int celebrity = isCelebrity(matrix, n);
    if (celebrity != -1) {
        cout << "Celebrity is person " << celebrity << endl;
    } else {
        cout << "No celebrity found" << endl;
    }
    return 0;
}