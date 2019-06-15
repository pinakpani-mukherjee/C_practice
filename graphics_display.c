#include "SDL.h"
#include<stdio.h>

typedef struct $
{
	int x,y;
	short life;
	char *name;	
} Man;

int main(int argc, char const *argv[])
{
	SDL_Window *window;
	SDL_Renderer *renderer;

	SDL_Init(SDL_INIT_VIDEO);

	window = SDL_CreateWindow("Game Window",          //name of game window
							 SDL_WINDOWPOS_UNDEFINED, //initial x position
							 SDL_WINDOWPOS_UNDEFINED, //initial y position
							 1024,                    //width of window
							 720,                     //height of window
							 0                        //flags
		                     );

	renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);


	SDL_SetRenderDrawColor(renderer,0,0,255,255);
    //clears screen to blue
	SDL_RenderClear(renderer);
    //sets the draw color to white
	SDL_SetRenderDrawColor(renderer,255,255,255,255);

	SDL_Rect rect = {220,140,200,200};  //positions of rectangle
	SDL_RenderFillRect(renderer,&rect); //creates the rectangle
    //presents the drawing,shows to the screen
	SDL_RenderPresent(renderer);
    //waits to quit after ~ miliseconds
	SDL_Delay(2000);

	SDL_DestroyWindow(window);    //destroys the window
	SDL_DestroyRenderer(renderer);//destroys the renderer

	SDL_Quit(); //quits the API


	return 0;
}	
