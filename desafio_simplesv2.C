#include <stdio.h>
#pragma GCC optimize("O3,unroll-loops")

void operation1(int array[]) {
    int A, Y;
    scanf("%d %d", &A, &Y);
    int temp = array[A];
    array[A] = array[Y];
    array[Y] = temp;
}

void operation2(int array[]) {
    int x, A, B;
    scanf("%d %d %d", &x, &A, &B);
    int times = 0;
    for (int i = A; i <= B; i++) {
        if (x > array[i]) {
            times++;
        }
    }
    printf("%d\n", times);
}

void choseOp(int array[], int op) {
    if (op == 1) {
        operation1(array);
    } else if (op == 2) {
        operation2(array);
    }
}

int main(void) {
    int N, Nop, op;
    scanf("%d %d", &N, &Nop);

    int array[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &array[i]);
    }

    for (int j = 0; j < Nop; j++) {
        scanf("%d", &op);
        choseOp(array, op);
    }

    return 0;
}