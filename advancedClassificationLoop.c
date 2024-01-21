
#include "NumClass.h"

int pow(int this, int by){
    int powed = 1;
    for(int i=0; i<by;i++){
        powed = powed * this;
    }
    return powed;
}

int isArmstrong(int num){
    int sum = 0, size=0, cNum=num;
    while(cNum > 0){ 
        size++;
        cNum = cNum/10;    
    }
    cNum = num;
    for(int i=0; i<size; i++){
        sum += pow(cNum%10,size);
        cNum = cNum/10;
    }
    if(sum == num){ return TRUE; }
    return FALSE;
}




int isPalindrome(int num){
    int reversed = 0, cNum = num;
    while(cNum > 0){
        reversed = reversed*10 + cNum%10;   
        cNum = cNum/10; 
    }
    if(reversed == num){ return TRUE; }
    return FALSE;
}
