// Recursive Approach
function knapsack(weights,values,W,n){
    if(W ==0 || n==0){
        return 0;
    }
    if(weights[n-1]<=W){
        return Math.max(
            values[n-1]+knapsack(weights,values,W-weights[n-1],n-1),
            knapsack(weights,values,W,n-1)
        );
    }
    else{
        return knapsack(weights,values,W,n-1)
    }
}

let values = [ 60, 100, 120 ]; 
let weights = [ 10, 20, 30 ]; 
let W = 50; 
let n = values.length; 
let startTime =new Date().getTime();
let data=knapsack(weights,values,W,n);
let endTime = new Date().getTime();
console.log(data);
console.log(endTime-startTime+' ms');