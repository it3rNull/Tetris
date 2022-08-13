#pragma once

#include "Map.h"
#include "Tetrimino.h"
#include "KeyInput.h"
#include "ConsoleOutput.h"
void printarr(int* arr, int num);
void shuffle(int* arr, int num);
class CTetris
{
	CMap m_Map;
	CTetrimino m_Tetrimino;
	CKeyInput m_Input;
	CConsoleOutput m_Output;
	int type;
	int count = 0;
	int* arr;
	int score = 0;

public:
	CTetris(void);
	~CTetris(void);

	void Input(std::list<ST_KEYSTATE>& outState);
	void Update(const std::list<ST_KEYSTATE> stKeyState, int nElapsedTick, int tick);
	void Render(int tick);
	bool Next(void);
};

