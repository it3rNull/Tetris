#include "pch.h"
#include "Tetrimino.h"

void CTetrimino::Reset(int nType)
{
	m_nPosX = 10;
	m_nPosY = 0;
	m_nRotation = 0;
	switch (nType)
	{
	case TETRIMINO_I:
		memcpy(m_szBlock[0][0], "бс      ", 9);
		memcpy(m_szBlock[0][1], "бс      ", 9);
		memcpy(m_szBlock[0][2], "бс      ", 9);
		memcpy(m_szBlock[0][3], "бс      ", 9);
		
		memcpy(m_szBlock[1][0], "бсбсбсбс ", 9);
		memcpy(m_szBlock[1][1], "        ", 9);
		memcpy(m_szBlock[1][2], "        ", 9);
		memcpy(m_szBlock[1][3], "        ", 9);

		memcpy(m_szBlock[2][0], "бс      ", 9);
		memcpy(m_szBlock[2][1], "бс      ", 9);
		memcpy(m_szBlock[2][2], "бс      ", 9);
		memcpy(m_szBlock[2][3], "бс      ", 9);

		memcpy(m_szBlock[3][0], "бсбсбсбс ", 9);
		memcpy(m_szBlock[3][1], "         ", 9);
		memcpy(m_szBlock[3][2], "         ", 9);
		memcpy(m_szBlock[3][3], "         ", 9);
		break;

	case TETRIMINO_O:
		memcpy(m_szBlock[0][0], "бсбс     ", 9);
		memcpy(m_szBlock[0][1], "бсбс     ", 9);
		memcpy(m_szBlock[0][2], "         ", 9);
		memcpy(m_szBlock[0][3], "         ", 9);

		memcpy(m_szBlock[1][0], "бсбс     ", 9);
		memcpy(m_szBlock[1][1], "бсбс     ", 9);
		memcpy(m_szBlock[1][2], "         ", 9);
		memcpy(m_szBlock[1][3], "         ", 9);

		memcpy(m_szBlock[2][0], "бсбс     ", 9);
		memcpy(m_szBlock[2][1], "бсбс     ", 9);
		memcpy(m_szBlock[2][2], "         ", 9);
		memcpy(m_szBlock[2][3], "         ", 9);

		memcpy(m_szBlock[3][0], "бсбс     ", 9);
		memcpy(m_szBlock[3][1], "бсбс     ", 9);
		memcpy(m_szBlock[3][2], "         ", 9);
		memcpy(m_szBlock[3][3], "         ", 9);
		break;

	case TETRIMINO_J:
		memcpy(m_szBlock[0][0], "бсбсбс   ", 9);
		memcpy(m_szBlock[0][1], "    бс   ", 9);
		memcpy(m_szBlock[0][2], "         ", 9);
		memcpy(m_szBlock[0][3], "         ", 9);

		memcpy(m_szBlock[1][0], "бсбс     ", 9);
		memcpy(m_szBlock[1][1], "бс       ", 9);
		memcpy(m_szBlock[1][2], "бс       ", 9);
		memcpy(m_szBlock[1][3], "         ", 9);

		memcpy(m_szBlock[2][0], "бс       ", 9);
		memcpy(m_szBlock[2][1], "бсбсбс   ", 9);
		memcpy(m_szBlock[2][2], "         ", 9);
		memcpy(m_szBlock[2][3], "         ", 9);

		memcpy(m_szBlock[3][0], "  бс     ", 9);
		memcpy(m_szBlock[3][1], "  бс     ", 9);
		memcpy(m_szBlock[3][2], "бсбс     ", 9);
		memcpy(m_szBlock[3][3], "         ", 9);
		break;

	case TETRIMINO_L:
		memcpy(m_szBlock[0][0], "бс       ", 9);
		memcpy(m_szBlock[0][1], "бсбсбс   ", 9);
		memcpy(m_szBlock[0][2], "         ", 9);
		memcpy(m_szBlock[0][3], "         ", 9);

		memcpy(m_szBlock[1][0], "  бс     ", 9);
		memcpy(m_szBlock[1][1], "  бс     ", 9);
		memcpy(m_szBlock[1][2], "бсбс     ", 9);
		memcpy(m_szBlock[1][3], "         ", 9);

		memcpy(m_szBlock[2][0], "бсбсбс   ", 9);
		memcpy(m_szBlock[2][1], "    бс   ", 9);
		memcpy(m_szBlock[2][2], "         ", 9);
		memcpy(m_szBlock[2][3], "         ", 9);

		memcpy(m_szBlock[3][0], "бсбс     ", 9);
		memcpy(m_szBlock[3][1], "бс       ", 9);
		memcpy(m_szBlock[3][2], "бс       ", 9);
		memcpy(m_szBlock[3][3], "         ", 9);
		break;

	case TETRIMINO_S:
		memcpy(m_szBlock[0][0], "  бсбс   ", 9);
		memcpy(m_szBlock[0][1], "бсбс     ", 9);
		memcpy(m_szBlock[0][2], "         ", 9);
		memcpy(m_szBlock[0][3], "         ", 9);

		memcpy(m_szBlock[1][0], "бс       ", 9);
		memcpy(m_szBlock[1][1], "бсбс     ", 9);
		memcpy(m_szBlock[1][2], "  бс     ", 9);
		memcpy(m_szBlock[1][3], "         ", 9);

		memcpy(m_szBlock[2][0], "  бсбс   ", 9);
		memcpy(m_szBlock[2][1], "бсбс     ", 9);
		memcpy(m_szBlock[2][2], "         ", 9);
		memcpy(m_szBlock[2][3], "         ", 9);

		memcpy(m_szBlock[3][0], "бс       ", 9);
		memcpy(m_szBlock[3][1], "бсбс     ", 9);
		memcpy(m_szBlock[3][2], "  бс     ", 9);
		memcpy(m_szBlock[3][3], "         ", 9);
		break;

	case TETRIMINO_Z:
		memcpy(m_szBlock[0][0], "бсбс     ", 9);
		memcpy(m_szBlock[0][1], "  бсбс   ", 9);
		memcpy(m_szBlock[0][2], "         ", 9);
		memcpy(m_szBlock[0][3], "         ", 9);

		memcpy(m_szBlock[1][0], "  бс     ", 9);
		memcpy(m_szBlock[1][1], "бсбс     ", 9);
		memcpy(m_szBlock[1][2], "бс       ", 9);
		memcpy(m_szBlock[1][3], "         ", 9); 

		memcpy(m_szBlock[2][0], "бсбс     ", 9);
		memcpy(m_szBlock[2][1], "  бсбс   ", 9);
		memcpy(m_szBlock[2][2], "         ", 9);
		memcpy(m_szBlock[2][3], "         ", 9);

		memcpy(m_szBlock[3][0], "  бс     ", 9);
		memcpy(m_szBlock[3][1], "бсбс     ", 9);
		memcpy(m_szBlock[3][2], "бс       ", 9);
		memcpy(m_szBlock[3][3], "         ", 9);
		break;

	case TETRIMINO_T:
		memcpy(m_szBlock[0][0], "  бс     ", 9);
		memcpy(m_szBlock[0][1], "бсбсбс   ", 9);
		memcpy(m_szBlock[0][2], "         ", 9);
		memcpy(m_szBlock[0][3], "         ", 9);

		memcpy(m_szBlock[1][0], "  бс     ", 9);
		memcpy(m_szBlock[1][1], "бсбс     ", 9);
		memcpy(m_szBlock[1][2], "  бс     ", 9);
		memcpy(m_szBlock[1][3], "         ", 9);

		memcpy(m_szBlock[2][0], "бсбсбс   ", 9);
		memcpy(m_szBlock[2][1], "  бс     ", 9);
		memcpy(m_szBlock[2][2], "         ", 9);
		memcpy(m_szBlock[2][3], "         ", 9);

		memcpy(m_szBlock[3][0], "бс       ", 9);
		memcpy(m_szBlock[3][1], "бсбс     ", 9);
		memcpy(m_szBlock[3][2], "бс       ", 9);
		memcpy(m_szBlock[3][3], "         ", 9);
		break;
	}
}
void CTetrimino::Rightend(int nType)
{
	switch (nType)
	{
	case TETRIMINO_I:
		if (m_nRotation == 1 or m_nRotation == 3){
			if (m_nPosX > 14)
				m_nPosX = 14;
		}
		else {
			if (m_nPosX > 20)
				m_nPosX = 20;
		}
		break;


	case TETRIMINO_O:
		if (m_nPosX > 18)
			m_nPosX = 18;	

		break;

	case TETRIMINO_J:
		if (m_nRotation == 0 or m_nRotation == 2) {
			if (m_nPosX > 16)
				m_nPosX = 16;
		}
		else {
			if (m_nPosX > 18)
				m_nPosX = 18;
		}
		break;

	case TETRIMINO_L:
		if (m_nRotation == 0 or m_nRotation == 2) {
			if (m_nPosX > 16)
				m_nPosX = 16;
		}
		else {
			if (m_nPosX > 18)
				m_nPosX = 18;
		}
		break;

	case TETRIMINO_S:
		if (m_nRotation == 0 or m_nRotation == 2) {
			if (m_nPosX > 16)
				m_nPosX = 16;
		}
		else {
			if (m_nPosX > 18)
				m_nPosX = 18;
		}
		break;

	case TETRIMINO_Z:
		if (m_nRotation == 0 or m_nRotation == 2) {
			if (m_nPosX > 16)
				m_nPosX = 16;
		}
		else {
			if (m_nPosX > 18)
				m_nPosX = 18;
		}
		break;

	case TETRIMINO_T:
		if (m_nRotation == 0 or m_nRotation == 2) {
			if (m_nPosX > 16)
				m_nPosX = 16;
		}
		else {
			if (m_nPosX > 18)
				m_nPosX = 18;
		}
		break;
	}

	if (m_nPosX < 2)
		m_nPosX = 2;

}

void CTetrimino::PushState(void)
{
	ST_TETRIMINO_STATE state;
	state.nPosX = m_nPosX;
	state.nPosY = m_nPosY;
	state.nRotation = m_nRotation;
	m_stackState.push(state);
}

void CTetrimino::RestoreState(void)
{
	if (m_stackState.empty())
		return;

	m_nPosX = m_stackState.top().nPosX;
	m_nPosY = m_stackState.top().nPosY;
	m_nRotation = m_stackState.top().nRotation;
	m_stackState.pop();
}

void CTetrimino::PopState(void)
{
	if (m_stackState.empty())
		return;

	m_stackState.pop();
}

void CTetrimino::Move(int nOffset,int type)
{
	if (nOffset == 3) {
		m_nPosY -= 1;
	}
	else if (nOffset == 2) {
		m_nPosY += 1;
	}
	else if (nOffset == -2) {
		m_nPosY -= 1;
	}
	else {
		m_nPosX += 2*nOffset;
	}

		
}

void CTetrimino::Smash(int type)
{
	m_nPosY = 17;
}
void CTetrimino::Fall()
{
		m_nPosY += 1;
}

int CTetrimino::giveXpos()
{
	return m_nPosX;
}

int CTetrimino::giveYpos()
{
	return m_nPosY;
}

int CTetrimino::giveRot()
{
	return m_nRotation;
}

void CTetrimino::Rotate(int nDir)
{
	m_nRotation = (m_nRotation + nDir) % 4;
}

void CTetrimino::OnDraw(CConsoleOutput* pRenderer)
{

	pRenderer->Print(m_nPosX, m_nPosY + 0, m_szBlock[m_nRotation][0], 8);
	pRenderer->Print(m_nPosX, m_nPosY + 1, m_szBlock[m_nRotation][1], 8);
	pRenderer->Print(m_nPosX, m_nPosY + 2, m_szBlock[m_nRotation][2], 8);
	pRenderer->Print(m_nPosX, m_nPosY + 3, m_szBlock[m_nRotation][3], 8);
}

void CTetrimino::Draw(CConsoleOutput* pRenderer, int type) {
	for (int i = 0; i < 4; i++) {
		if (m_nPosY + i >= 0) {
			pRenderer->Printblock(m_nPosX, m_nPosY + i, m_szBlock[m_nRotation][i], 8, type);
		}
	}

}