/*
Print program in such a way , if even add 1 and if odd substract 1 , 
1 to 10
*/
function recursion(n){
    if(n==0){
        return;
    }
    if(n%2==0){
        console.log(n+1)
    }
    else {
        console.log(n-1);
    }
    recursion(n-1);
}
recursion(10);
