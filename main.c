#include <stdio.h>

#define MAX_LINE_SIZE 1000

int get_stream_size(FILE *stream) {
	int size;
	long currentPos = ftell(stream);

	fseek(stream, 0L, SEEK_END);
	size = ftell(stream);
	fseek(stream, currentPos, 0);

	return size;
}

int main(int argc, char **argv) {
	char *path;

	if (argc < 2) {
		printf("No Path Provided");
		return 1;
	}
	
	path = argv[1];
	FILE *file = fopen(path, "r");
	
	if (file == NULL) {
		printf("Invalid Path Provided");
		return 2;
	}
	
	char fileBuffer[]; // +1 for null terminator
	
}
