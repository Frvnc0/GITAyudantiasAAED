#include <stdio.h>



int fibRecStack(int result){

    if(result == 1 || result == 0){
        return result;
    }

    else{
        return fibRecStack(result-1) + fibRecStack(result-2);
    }

}


int main (){

    printf("El resultado del fibonacci es: %d", fibRecStack(10));
    return 0;
}