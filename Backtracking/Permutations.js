function permutations(str,perm,index){
    if(str.length == 0){
        console.log(perm);
        return;
    }
    for(let i=0;i<str.length;i++){
        let currChar =str[i];
        let newString = str.substring(0,i)+str.substring(i+1);
        permutations(newString,perm+currChar,index+1);
    }
}
permutations('ABC','',0);

