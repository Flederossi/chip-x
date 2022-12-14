#include <SDL2/SDL.h>

#define SD 256
#define D 64

typedef struct{
	int r;
	int g;
	int b;
}Color;

const Color colors[3] = {
	(Color){255, 0, 0},
	(Color){0, 255, 0},
	(Color){0, 0, 255}
};

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Event event;

void screen_init(){
	SDL_Init(SDL_INIT_VIDEO);
	SDL_CreateWindowAndRenderer(SD, SD, 0, &window, &renderer);
	SDL_SetWindowTitle(window, "Chip-X");
	SDL_RenderPresent(renderer);
}

int screen_check_key(){
	if (SDL_PollEvent(&event) && event.type == SDL_KEYDOWN){
		return event.key.keysym.sym == SDLK_UP;
	}else{
		return 0;
	}
}

int screen_check_quit(){
	SDL_PollEvent(&event);
	if (event.type == SDL_QUIT){
		return 0;
	}else if (event.type == SDL_KEYDOWN){
		switch(event.key.keysym.sym){
		case SDLK_UP:
			return 1;
			break;
		case SDLK_RIGHT:
			return 2;
			break;
		case SDLK_DOWN:
			return 3;
			break;
		case SDLK_LEFT:
			return 4;
			break;
		}
	}
}

void screen_clear(){
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);
}

void screen_set(int x, int y, int c){
	int pixel_width = SD / D;

	Color color = colors[c];
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, 255);

	for (int dx = 0; dx < pixel_width; dx++){
		for (int dy = 0; dy < pixel_width; dy++){
			SDL_RenderDrawPoint(renderer, x * pixel_width + dx, y * pixel_width + dy);
		}
	}

	SDL_RenderPresent(renderer);
}

void screen_info(char *title, char *content){
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, title, content, window);
}

void screen_error(char *title, char *content){
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, title, content, window);
}

void screen_delay(int fps){
	SDL_Delay(1000 / fps);
}

void screen_exit(){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}