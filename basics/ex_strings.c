#include <stdio.h>
#include <string.h>

int main() {

	char * name1 = "John Smith";
	char name2[] = "John Smith";
	char name3[11] = "John Smith";
	printf("%s\n", name1);
	printf("%s\n", name2);
	printf("%s consists of %zu letters.\n", name3, strlen(name3));
		
	return 0;
}