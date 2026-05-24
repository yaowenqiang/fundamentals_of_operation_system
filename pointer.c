#include <stdlib.h>

int main() {
	int *ptr = malloc(sizeof(int));
	*ptr = 10;
	*ptr += 1;
	free(ptr);
	return 0;

}
