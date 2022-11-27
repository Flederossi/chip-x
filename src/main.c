#include <stdio.h>

#include "utils.h"
#include "file.h"
#include "parser.h"
#include "screen.h"

int main(int argc, char *argv[]){
	screen_init();

	if (argc < 2){
		screen_error("Arguments", "Usage: chip-x [image-file]");
		return 1;
	}

	int size = file_open(argv[1]);
	char buf[size];
	file_read(buf);

	int prog_length = parser_length(buf, size);
	int prog[prog_length];
	parser_convert(buf, prog);

	parser_init(prog, prog_length);

	while (1){
		int key = screen_check_quit();
		if (key == NULL){
			break;
		}
		parser_cycle(prog, prog_length, key);
		screen_delay(30);
	}

	screen_exit();
	return 0;
}