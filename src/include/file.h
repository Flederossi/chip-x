FILE *fp;
int size;

int file_open(char *filename){
	fp = fopen(filename, "r");

	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	return size;
}

void file_read(char *dest){
	for (int cc = 0; cc < size; cc++){
		dest[cc] = fgetc(fp);
	}
}