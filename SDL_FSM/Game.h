// author Dion Buckley
#ifndef GAME
#define GAME
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include "Animation.h"
#include "Windows.h"

struct KeyBoardState
{
	bool A;
	bool D;
	bool W;
	bool Q;
	bool E;
	bool Space;
};

class Game
{
public:

	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:
	int m_pressed;
	int m_previousPressed;
	KeyBoardState m_currentState;
	KeyBoardState m_previousState;
	Animation fsm;

	//void processEvents();
	//void update();
	//void render();
	
	//void setupFontAndText();
	//void setupSprite(int t_pressed);


	SDL_Window* m_window;

	//bool m_exitGame; // control exiting game

};

#endif // !GAME

