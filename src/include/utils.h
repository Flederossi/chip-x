int hex2dec(char *h){
	int b = 1;
	int d = 0;

	for (int i = 1; i >= 0; i--){
		if (h[i] >= '0' && h[i] <= '9'){
			d += ((int)(h[i]) - 48) * b;
			b *= 16;
		}else if (h[i] >= 'A' && h[i] <= 'F'){
			d += ((int)(h[i]) - 55) * b;
			b *= 16;
		}
	}
	return d;
}