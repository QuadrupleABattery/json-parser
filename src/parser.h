enum TOKEN_TYPE {
	OpenChar,
	CloseChar,
	String,
	Number,
	Bool,
};

struct token {
	char *text;
	enum TOKEN_TYPE type;
};

struct input_buffer {
	char *data;
	int cursor;
};
