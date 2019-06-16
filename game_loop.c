#include "SDL.h"
#include<stdio.h>

typedef struct $
{
	int x,y;
	short life;
	char *name;	
} Man;

int processEvents(SDL_Window *window,Man *man) //window passed in by reference
{
	SDL_Event event;
	int done = 0;
	while(SDL_PollEvent(&event))
		{
			switch(event.type)
			{
				case SDL_WINDOWEVENT_CLOSE:
				{
					if(window)
					{
						SDL_DestroyWindow(window);
						window = NULL;
						done = 1;
					}
				}
				break;
				{
					switch(event.key.keysym.sym)
					{
						case SDLK_ESCAPE:
							done = 1;
						break;
					}
						
				}
				break;
				case SDL_QUIT:
				//quit out of the game
					done = 1;
				break;
			}
		}

	const Uint8 *state = SDL_GetKeyboardState(NULL);
	if(state[SDL_SCANCODE_LEFT])
	{
		man->x -= 10;  							 //because it is a reference, we do not use man.x or man .y
    }                                            //we use man->x and man->y
	if(state[SDL_SCANCODE_RIGHT])
	{
		man->x += 10;
	}
	if(state[SDL_SCANCODE_UP])
	{
		man->y -= 10;
	}
	if(state[SDL_SCANCODE_DOWN])
	{
		man->y += 10;
	}


	return done;
}

void doRender(SDL_Renderer *renderer, Man *man)
{
	SDL_SetRenderDrawColor(renderer,0,0,255,255);
    //clears screen to blue
	SDL_RenderClear(renderer);
    //sets the draw color to white
	SDL_SetRenderDrawColor(renderer,255,255,255,255);

	SDL_Rect rect = {man->x,man->y,200,200};  //positions of rectangle
	SDL_RenderFillRect(renderer,&rect); //creates the rectangle
    //presents the drawing,shows to the screen
	SDL_RenderPresent(renderer);

}

int main(int argc, char const *argv[])
{
	SDL_Window *window;
	SDL_Renderer *renderer;

	SDL_Init(SDL_INIT_VIDEO);

	Man man;
	man.x = 220;
	man.y = 140;

	window = SDL_CreateWindow("Game Window",          //name of game window
							 SDL_WINDOWPOS_UNDEFINED, //initial x position
							 SDL_WINDOWPOS_UNDEFINED, //initial y position
							 640,                    //width of window
							 480,                     //height of window
							 0                        //flags
		                     );

	renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);

	//entering the program loop
	int done = 0;//boolean to check if game is completed

	//entering the event loop
	while(!done)
	{
	//check for events
	if(processEvents(window,&man)== 1)
		done = 1;
	//renders display
	doRender(renderer, &man);
	//waits to quit after ~ miliseconds
	SDL_Delay(20);
	}

	SDL_DestroyWindow(window);    //destroys the window
	SDL_DestroyRenderer(renderer);//destroys the renderer

	SDL_Quit(); //quits the API


	return 0;
}	
