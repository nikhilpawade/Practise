#include <stdio.h>
int reverse(int x){
    int num = 0, pow = 10, mod,i;
    for (i = 0; x != 0; i++) {
        mod = x % 10;
	if (num *10 > INT_MAX) {
		return 0;
        }
        num = num * 10 + mod;
        x = x / 10;
        printf("%d\n", num);
    }
    return num;
}

int main() {
	int x = -123;
	x = reverse(x);
	printf("%d\n",x);
}
