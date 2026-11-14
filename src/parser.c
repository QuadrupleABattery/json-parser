#include <string.h>
#include "parser.h"

int checkObjectType(char surroundCharacter) {
	if (surroundCharacter == '{') {
		return 1;
	} else if (surroundCharacter == '[') {
		return 2;
	}

	return 0;
}

int parse(char *text) {
	int objectType = checkObjectType(text[0]);

	if (objectType == 0) {
		return 1;
	}

	return 0;
}
