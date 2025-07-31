function maxProductSubarray(array) {
    let size=array.length;
    let max_till_now=array[0];
    let max_overall=array[0];
    
    for(let i=1;i<size;i++) {
        max_till_now = Math.max(array[i],max_till_now*array[i]);
        max_overall=Math.max(max_till_now,max_overall);
    }
    
    console.log(max_overall);
    
}

maxProductSubarray([-2,0,-1]);