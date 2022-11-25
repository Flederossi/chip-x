char c;
char *valid = "0123456789ABCDEF";

void parser_cycle(char *prog, int size){
	for (int i = 0; i < size; i++){
		c = prog[i];

		for (int j = 0; j < 16; j++){
			if (valid[j] == c){
				screen_info("Test", &c);
			}
		}
	}
}