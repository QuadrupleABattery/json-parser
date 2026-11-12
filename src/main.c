#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include "parser.h"

struct dictionary {
	char **keys;
	void **values;
	int size;
};

struct list {
	void **values;
	int size;
};

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
	
	int fileSize = get_stream_size(file) + 1; // +1 for null terminator
	
	struct input_buffer fileBuffer = {
		.data = malloc(fileSize),
		.cursor = 0,
	};

	printf("file size: %d\n", fileSize);
	fread(fileBuffer.data, 1, fileSize, file);
	fclose(file);

	return 0;
}
