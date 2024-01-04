function fact(n){
    if(n==1){
        return 1;
    }
    else{
        return n * fact(n-1);
    }
}
/**
 * fact(1) =1;
 * fact(2) =2* fact(1);
 * fact(3) =3* fact(2);
 * fact(4) =4* fact(3);
 * 
 */