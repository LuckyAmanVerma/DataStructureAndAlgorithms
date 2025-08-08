/*
Input: arr[][] = [[1, 3], [2, 4], [6, 8], [9, 10]]
Output: [[1, 4], [6, 8], [9, 10]]
Merge Intervals
*/

function mergeInterval(array) {
    let n=array.length;
    if(n<=1){
        return array;
    }
    let result=[];
    result.push(array[0]);
    let i=1;
    while(i<n) {
        const [currentStart,currentEnd]=array[i];
        const[prevStart,prevEnd]=result[result.length-1];
        if(prevEnd>currentStart) {
            const mergeData=[prevStart,Math.max(currentEnd,prevEnd)];
            result[result.length-1]=mergeData;
        }
        else{
            result.push(array[i]);
        }
        i++;
    }
    console.log(result);
}

mergeInterval([[1, 3], [2, 4], [6, 8], [9, 10]]);
