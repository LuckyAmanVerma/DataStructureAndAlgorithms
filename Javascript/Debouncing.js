const myDebounce =(fn,time)=>{
    let timer;
    return function(...args){
        if(timer) clearTimeout(timer);
        else{
            timer =setTimeout(()=>fn(...args),time);
        }
    }
};