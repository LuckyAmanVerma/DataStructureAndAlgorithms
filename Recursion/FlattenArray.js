/**
 * Time Complexity O(n) -Linear Increases as no of input values increases
 */
let newArray=[];
function recursionFunction(a){
    console.log(a);
    if(a){
        for(let i=0;i<a.length;i++){
           if(Array.isArray(a[i])){
            recursionFunction(a[i]);
           }
           else{
            newArray.push(a[i]);
           }
        }
    }
    return newArray;
}
let arr=[1,2,[3,4],[5],[7,[9]]];
 console.log(recursionFunction(arr));