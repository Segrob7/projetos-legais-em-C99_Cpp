#include <stdio.h>

int fibo(int n){
if(n == 0){
    return 0;
}
else if(n - 2 <= 0){
    return 1;
}
else {
    return fibo(n -1) + fibo(n-2);
}
}
int main(){
    int times;
    scanf("%d", &times);
    int n;
    int array[times];
    int set[times];
    for(int i = 0; i < times; i++){
    scanf("%d", &n);
    set[i] = n;
    array[i] = fibo(n);
}
for(int j=0; j< times;j++){
    printf("Fib[%d] = %d\n", set[j], array[j]);
}
    return 0;
}