#include <stdio.h>
#include <stdlib.h>
typedef struct ts_a {
	char *a;
}ts_a;

int strLength(char *str)
{
	// local variable in all function must be initialzed"
	int length = 0;

	while(*(str++)) {
		length++;
	}

	return length;
}

char *stringAppend(char *src_1, char *src_2, char *src_3) {
	int total_length_of_src = (strLength(src_1) + strLength(src_2) + strLength(src_3));
	char *p_appended = (char*)malloc(total_length_of_src + 1);
	
	while(*src_1) {
		*(p_appended++) = *(src_1++);
	}

	while(*src_2) {
		*(p_appended++) = *(src_2++);
	}

	while(*src_3) {
		*(p_appended++) = *(src_3++);
	}
	*p_appended = '\0';

	p_appended -= total_length_of_src;
	return p_appended;
}

int main()
{
	int i;
	ts_a tsa = {.a="apple"};
	ts_a tsb = {.a=" is "};
	ts_a tsc = {.a="delicious"};

	printf("%s\n", stringAppend(tsa.a,tsb.a,tsc.a));

	return 0;
}
