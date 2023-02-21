#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PAIRS 255

int main() {
	char query[] = "register=&username=halloweeks&email=halloweeks@gmail.com&password=1234567890";
	char pairs[MAX_PAIRS][2][256] = {0};
	int pair_count = 0;
	
	char *key, *value;
	
	key = strtok(query, "&");
	while (key != NULL) {
		value = strchr(key, '=');
		if (value != NULL) {
			*value++ = '\0';
			strncpy(pairs[pair_count][0], key, 256);
			strncpy(pairs[pair_count][1], value, 256);
			pair_count++;
		}
		key = strtok(NULL, "&");
	}
	
	// Do something with the key-value pairs
	for (int i = 0; i < pair_count; i++) {
		printf("key=%s; value=%s;\n", pairs[i][0], pairs[i][1]);
	}
	
	return 0;
}
