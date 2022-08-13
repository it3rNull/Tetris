#pragma once

#include "RenderObject.h"
#include <stack>

enum E_TETRIMINO_TYPE
{
	TETRIMINO_I = 0,
	TETRIMINO_O,
	TETRIMINO_J,
	TETRIMINO_L,
	TETRIMINO_S,
	TETRIMINO_Z,
	TETRIMINO_T,
	TETRIMINO_COUNT
};

struct ST_TETRIMINO_STATE
{
	int nRotation;
	int nPosX;
	int nPosY;
};

class CTetrimino : public CRenderObject
{
	char m_szBlock[4][4][8 + 1];
	int m_nRotation;
	std::stack<ST_TETRIMINO_STATE> m_stackState;

public:
	void Reset(int nType);
	void Rightend(int nType);
	void PushState(void);
	void RestoreState(void);
	void PopState(void);

	void Move(int nOffset,int type);
	void Smash(int type);
	void Fall();
	void Rotate(int nDir = 1);
	int giveXpos();
	int giveYpos();
	int giveRot();

	void OnDraw(CConsoleOutput* pRenderer);
	void Draw(CConsoleOutput* pRenderer, int type);
};

