#include <stdio.h>

typedef struct ts_a {
	int *a;
}ts_a;

int main()
{
	int i;

	ts_a tsa = {
		.a=(int[]){1,2,3,4,5,6,7,8,9 (int)NULL}
	};

	tsa.a[0] = 5;

	for(i=0 ; tsa.a[i]; i++) {
		printf("%d\n", tsa.a[i]);
	}

	return 0;
}
