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

	char test[512];
	sprintf(test, "%d", hex2dec("A0"));
	screen_info("Convert", test);

	while (1){
		if (screen_check_quit()){
			break;
		}
		parser_cycle(buf, size);
		screen_delay(30);
	}

	screen_exit();

	return 0;
}