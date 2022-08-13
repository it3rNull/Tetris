#pragma once

#include "RenderObject.h"
#include "Tetrimino.h"
#include <windows.h>
#include <memory>
#include <string>
#include <stdexcept>

const int g_nBlockWidth = 12;
const int g_nBlockHeight = 18;
const int g_nMapMargin = 2;
const int g_nMapWidth = g_nBlockWidth + g_nMapMargin * 2;
const int g_nMapHeight = g_nBlockHeight + g_nMapMargin;

typedef enum Color {
	DARKPURPLE = 5,
	GRAY = 8,
	BLUE = 9,
	GREEN = 10,
	AQUA = 11,
	RED = 12,
	PURPLE = 13,
	YELLOW = 14,
	WHITE = 15
}COLOR;

class CMap : public CRenderObject
{
	char m_szMapData[g_nMapHeight][g_nMapWidth + 1];
	char wall[5];
	char block[3];
	char heart[3];
	char circle[3];
	char star[3];
	char dia[3];
	char spade[3];
	char club[3];
	char block_s[3];
	char heart_s[3];
	char circle_s[3];
	char star_s[3];
	char dia_s[3];
	char spade_s[3];
	char club_s[3];
	char bottom[25];
	char piledata[19][13];
	char shadowdata[19][13];
	char height[10];

public:
	void Clear(void);
	bool IsCollide(CTetrimino* pTetrimino,int type);
	bool IsBottom(CTetrimino* pTetrimino, int type);
	void Pile(CTetrimino* pTetrimino,int type);
	void OnDraw(CConsoleOutput* pOutput);
	void getHeight(CTetrimino* pTetrimino,int y);
	void EraseLine(int* score);
	void RenderShadow(CConsoleOutput* pRender,CTetrimino* pTetrimino, int type);
	bool Gameover();
	void Crossline(CConsoleOutput* pRender);
	void Score(CConsoleOutput* pRender,int score,int time);
	void logo(CConsoleOutput* pRender);
};


template<typename ... Args>
std::string string_format(const std::string& format, Args ... args)
{
	int size_s = std::snprintf(nullptr, 0, format.c_str(), args ...) + 1;
	if (size_s <= 0) { throw std::runtime_error("Error during formatting."); }
	auto size = static_cast<size_t>(size_s);
	std::unique_ptr<char[]> buf(new char[size]);
	std::snprintf(buf.get(), size, format.c_str(), args ...);
	return std::string(buf.get(), buf.get() + size - 1);
}