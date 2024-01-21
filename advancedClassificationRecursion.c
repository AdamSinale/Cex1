
#include "NumClass.h"

int pow(int this, int by){
    int powed = 1;
    for(int i=0; i<by;i++){
        powed = powed * this;
    }
    return powed;
}

int isArmstrong(int num){
    int size = 0, cNum = num;
    while(cNum > 0){ 
        size++;
        cNum = cNum/10;    
    }
    if(isArmstrongHelper(num, size) == num){ return TRUE; }
    return FALSE;
}
int isArmstrongHelper(int num, int size){
    if(num < 10){ return pow(num,size); }
    return pow(num%10,size) + isArmstrongHelper(num/10,size);
}


int isPalindrome(int num){
    if(isPalindromeHelper(num,0) == num){ return TRUE; }
    return FALSE;
}
int isPalindromeHelper(int num, int revNum){
    if(num == 0){ return revNum; }
    revNum = revNum*10 + num%10;
    return isPalindromeHelper(num/10,revNum);
}
