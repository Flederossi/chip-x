#include <SDL2/SDL.h>

int parser_valid(char hc){
	int hcv = (int) hc;
	return (hcv >= 48 && hcv <= 57) || (hcv >= 65 && hcv <= 70);
}

int parser_length(char *prog, int size){
	int cmd_count = 0;
	for (int i = 0; i < size; i++){
		if (parser_valid(prog[i])){
			cmd_count++;
		}
	}
	cmd_count /= 2;
	return cmd_count;
}

void parser_convert(char *prog, int *dest){
	char c;
	char temp[2];
	int cmd_i = 0;
	for (int i = 0; i < size; i++){
		c = prog[i];
		if (parser_valid(c)){
			sprintf(temp, "%c%c", c, prog[i+1]);
			dest[cmd_i] = hex2dec(temp);
			i++;
			cmd_i++;
		}
	}
}

int curr_color = 0;
int reg[256];

int parser_parse(int *prog, int i, int length, int key){
	if (key >= 1 && key <= 4){
		reg[255] = key;
	}else{
		reg[255] = 0;
	}

	if (prog[i] == 0){
		reg[prog[i + 1]] = prog[i + 2];
		return i + 2;
	}else if (prog[i] == 1 || prog[i] == 2){
		if (reg[prog[i + 1]] == 0 && prog[i] == 1){
			return i + 1;
		}else if (reg[prog[i + 1]] != 0 && prog[i] == 2){
			return i + 1;
		}else{
			for (int j = i; j < length; j++){
				if (prog[j] == 238){
					return j;
				}
			}
			return length;
		}
	}

	else if (prog[i] == 16){
		screen_set(reg[prog[i + 1]], reg[prog[i + 2]], curr_color);
		return i + 2;
	}else if (prog[i] == 17){
		curr_color = reg[prog[i + 1]];
		return i + 1;
	}else if (prog[i] == 18){
		screen_clear();
		return i;
	}

	else if (prog[i] == 32){
		reg[prog[i + 1]] += reg[prog[i + 2]];
		return i + 2;
	}else if (prog[i] == 33){
		reg[prog[i + 1]] -= reg[prog[i + 2]];
		return i + 2;
	}else if (prog[i] == 34){
		reg[prog[i + 1]] *= reg[prog[i + 2]];
		return i + 2;
	}else if (prog[i] == 35){
		reg[prog[i + 1]] /= reg[prog[i + 2]];
		return i + 2;
	}
}

void parser_init(int *prog, int length){
	for (int i = 0; i < length; i++){
		if (prog[i] == 255){
			break;
		}
		i = parser_parse(prog, i, length, NULL);
	}
}

void parser_cycle(int *prog, int length, int key){
	int update_reached = 0;
	for (int i = 0; i < length; i++){
		if (update_reached){
			i = parser_parse(prog, i, length, key);
		}else if (prog[i] == 255){
			update_reached = 1;
		}
	}
}