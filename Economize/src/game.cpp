#include "../include/game.h"

#include <Windows.h>
#include <time.h>

#include <stdio.h>

using namespace std;

const float frame_length = 1;

char inputHandler()
{
	// https://cpp.hotexamples.com/examples/-/-/PeekConsoleInput/cpp-peekconsoleinput-function-examples.html
	char input;
	bool stop = false;

	HANDLE handle = GetStdHandle(STD_INPUT_HANDLE);
	DWORD gotEvent;
	INPUT_RECORD buffer;

	while (stop != true)
	{
		// Think if I change the 1 to another number the length of the WORD
		// would become longer.
		// Change it to 2 I'll get two characters.
		// REMEMBER TO DO IT IN ReadConsoleInput() ALSO
		PeekConsoleInput(handle, &buffer, 1, &gotEvent);

		if (gotEvent > 0)
		{
			ReadConsoleInput(handle, &buffer, 1, &gotEvent);

			// There will be some data-loss, but it's only special characters
			// like !\'@ øûõ or the arrow keys.
			// You can get the arrow keys to work, but it's:
			// Up arrow key: &
			// Down arrow key: (
			// Left arrow key: %
			// Right arrow key: '

			// This happens because I'm converting a WORD to a char
			input = buffer.Event.KeyEvent.wVirtualKeyCode;
			stop = true;
		}
	}

	return input;
}

void test()
{
	bool stopGame = false;

	char inputChar = 0;
	while (stopGame != true)
	{
		inputChar = inputHandler();
		cout << inputChar; //  << endl
		if (inputChar == 'S')
		{
			cout << "Ending game" << endl;
			stopGame = true;
		}
	}
}