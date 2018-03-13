/*Write C expressions for the following values, with the results for x = 0x98FDECBA and a 32-bit word
size shown in square brackets:
A. The least significant byte of x, with all other bits set to 1 [0xFFFFFFBA].
B. The complement of the least significant byte of x, with all other bytes left unchanged [0x98FDEC45].
C. All but the least significant byte of x, with the least significant byte set to 0 [0x98FDEC00].*/
/*                         8  4  2  1 */
#include <stdio.h>

int set_bit_except_least(int x) {
	x = x | 0xffffff00; 
	printf("set all bit except least=  0x.%x\n",x);
	return 0;
}

int complement_least_byte(int x) {
	x = x ^ 0x000000ff; 
	printf("Complement_least_byte=  0x.%x\n",x);
	return 0;
}

int least_byte_set_tozero(int x) {

	x = x & 0xffffff00; 
	printf("least_byte_set_tozero=  0x.%x\n",x);
	return 0;


}
int main() {
	int x = 0x98FDECBA;
	printf("Hex deciamal val = 0x.%x\n",x);
	set_bit_except_least(x);
	complement_least_byte(x);
	least_byte_set_tozero(x);
	return 0;


}
