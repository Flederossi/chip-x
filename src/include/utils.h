int hex2dec(char *hex){
	int b = 1;
	int dec = 0;

	for (int i = 1; i >= 0; i--){
		if (hex[i] >= '0' && hex[i] <= '9'){
			dec += ((int)(hex[i]) - 48) * b;
			b *= 16;
		}else if (hex[i] >= 'A' && hex[i] <= 'F'){
			dec += ((int)(hex[i]) - 55) * b;
			b *= 16;
		}
	}

	return dec;
}