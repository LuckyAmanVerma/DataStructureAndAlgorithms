// DP with memoization Approach
let values = [ 60, 100, 120 ]; 
let weights = [ 10, 20, 30 ]; 
let W = 50; 
let n = values.length;
let dp = new Array(n+1).fill(-1).map(el=>new Array(W+1).fill(-1));
function knapsack(weights,values,W,n){
    if(W ==0 || n==0){
        return 0;
    }
    if(dp[n][W]!==-1){
        return dp[n][W]
    }
    if(weights[n-1]<=W){
        return  dp[n][W]= Math.max(
            values[n-1]+knapsack(weights,values,W-weights[n-1],n-1),
            knapsack(weights,values,W,n-1)
        );
    }
    else{
        return dp[n][W]= knapsack(weights,values,W,n-1)
    }
}

let startTime =new Date().getTime();
let data=knapsack(weights,values,W,n);
let endTime = new Date().getTime();
console.log(data);
console.log(endTime-startTime+' ms');