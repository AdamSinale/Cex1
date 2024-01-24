
#include "NumClass.h"

int sqrt(int this){
    int i = 1;
    while(i*i <= this){
        i++;
    }
    return i-1;
}
int powerTo(int num){
    int powered = 1;
    for(int i=1; i<=num; i++){
        powered = powered*i;
    }
    return powered;
}

int isPrime(int num){
    int sqrted = sqrt(num);
    for(int i=2; i<=sqrted; i++){
        if(num%i == 0){ return FALSE; }
    }
    return TRUE;
}

int isStrong(int num){
    int sum = 0, size=0, cNum=num;
    while(cNum > 0){ 
        size++;
        cNum = cNum/10;    
    }
    cNum = num;
    for(int i=0; i<size; i++){
        sum += powerTo(cNum%10);
        cNum = cNum/10;
    }
    if(sum == num){ return TRUE; }
    return FALSE;
}
