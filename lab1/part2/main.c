#include <stdio.h>

void convert_binary(unsigned int num){
	int i;

	for (i = sizeof(int) * 8 - 1; i >= 0; i--) {
		printf("%d", (num >> i) & 1);
		if (i % 4 == 0)
			printf(" ");
	}
	printf("\n");
}

int main() {
	
	int num;
	scanf("%d", &num);
	printf("signed dec:   %d\n", num);
	printf("unsigned dec: %u\n", (unsigned int)num);
	printf("hex:	      %x\n", num);
	printf("binary:       ");
	convert_binary((unsigned int)num);
	
	return 0;
}
