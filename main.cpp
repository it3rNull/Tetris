#include "pch.h"
#include "Tetris.h"
void Tetris() {
	int nFPS = 100;
	int nSleepTime = 1000 / nFPS;
	while (true) {
		CTetris tetris;
		int tick = 0;
		while (true)
		{
			std::list<ST_KEYSTATE> keyState;

			tetris.Input(keyState);
			tetris.Update(keyState, nSleepTime, tick);
			tetris.Render(tick);
			tick += 1;
			Sleep(nSleepTime);
		}
	}
}


int main()
{
	Tetris();

	return 0;
}


