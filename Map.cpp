#include "pch.h"
#include "Map.h"

void CMap::Clear(void)
{
	m_nPosX = 0;
	m_nPosY = 0;
	memcpy(block, "¡á", 2);
	memcpy(block_s, "¡à", 2);
	memcpy(wall, "¢Ã", 2);
	memcpy(bottom, "¢Ã¢Ã¢Ã¢Ã¢Ã¢Ã¢Ã¢Ã¢Ã¢Ã¢Ã¢Ã ", 25);
	for (int i = 0; i < 18; i++) {
		memset(piledata[i], 8, 13);
	}
	memset(piledata[18], 9, 13); 
}

void CMap::getHeight(CTetrimino* pTetrimino,int y) {
	for (int i = 0; i < 10; i++) {
		for (int j = y; j < 19; j++) {
			if (piledata[j][i] != 8) {
				height[i] = j;
				break;
			}
		}
	}
}

bool CMap::Gameover() {
	int flag = 0;
	for (int i = 0; i < 10; i++) {
		if (height[i] <= 3){
			return true;
		}
	}
	return false;

}
bool CMap::IsCollide(CTetrimino* pTetrimino, int type)
{
	int xpos = (pTetrimino->giveXpos()/2) -1;
	int ypos = pTetrimino->giveYpos();
	int rot = pTetrimino->giveRot();
	if (type == 0) {
		if (rot == 0 || rot == 2) {
			if ((piledata[ypos][xpos] != 8) ||
				(piledata[ypos + 1][xpos] != 8) ||
				(piledata[ypos + 2][xpos] != 8) ||
				(piledata[ypos + 3][xpos] != 8)) {
				return true;
			}
		}
		else if (rot == 1 || rot == 3) {
			if ((piledata[ypos][xpos] != 8) ||
				(piledata[ypos][xpos+1] != 8) ||
				(piledata[ypos][xpos+2] != 8) ||
				(piledata[ypos][xpos+3] != 8)) {
				return true;
			}
		}
	}

	else if (type == 1) {
		if ((piledata[ypos][xpos] != 8) ||
			(piledata[ypos][xpos + 1] != 8) ||
			(piledata[ypos + 1][xpos] != 8) ||
			(piledata[ypos + 1][xpos + 1] != 8)) {
			return true;
		}
	}

	else if (type == 2) {
		if (rot == 0) {
			if ((piledata[ypos][xpos] != 8) ||
				(piledata[ypos][xpos + 1] != 8) ||
				(piledata[ypos][xpos + 2] != 8) ||
				(piledata[ypos + 1][xpos + 2] != 8)) {
				return true;
			}
		}
		if (type == 2 && rot == 1) {
			if ((piledata[ypos][xpos] != 8) ||
				(piledata[ypos][xpos + 1] != 8) ||
				(piledata[ypos + 1][xpos] != 8) ||
				(piledata[ypos + 2][xpos] != 8)) {
				return true;
			}
		}
		if (rot == 2) {
			if ((piledata[ypos][xpos] != 8) ||
				(piledata[ypos + 1][xpos] != 8) ||
				(piledata[ypos + 1][xpos + 1] != 8) ||
				(piledata[ypos + 1][xpos + 2] != 8)) {
				return true;
			}
		}
		if (rot == 3) {
			if ((piledata[ypos][xpos + 1] != 8) ||
				(piledata[ypos + 1][xpos + 1] != 8) ||
				(piledata[ypos + 2][xpos + 1] != 8) ||
				(piledata[ypos + 2][xpos] != 8)) {
				return true;
			}
		}
	}

	else if (type == 3) {
		if (rot == 0) {
			if ((piledata[ypos][xpos] != 8) ||
				(piledata[ypos + 1][xpos] != 8) ||
				(piledata[ypos + 1][xpos + 1] != 8) ||
				(piledata[ypos + 1][xpos + 2] != 8)) {
				return true;
			}
		}
		if (rot == 1) {
			if ((piledata[ypos][xpos + 1] != 8) ||
				(piledata[ypos + 1][xpos + 1] != 8) ||
				(piledata[ypos + 2][xpos + 1] != 8) ||
				(piledata[ypos + 2][xpos] != 8)) {
				return true;
			}
		}
		if (rot == 2) {
			if ((piledata[ypos][xpos] != 8) ||
				(piledata[ypos][xpos + 1] != 8) ||
				(piledata[ypos][xpos + 2] != 8) ||
				(piledata[ypos + 1][xpos + 2] != 8)) {
				return true;
			}
		}
		if (rot == 3) {
			if ((piledata[ypos][xpos] != 8) ||
				(piledata[ypos][xpos + 1] != 8) ||
				(piledata[ypos + 1][xpos] != 8) ||
				(piledata[ypos + 2][xpos] != 8)) {
				return true;
			}
		}
	}

	if (type == 4) {
		if (rot == 0 or rot == 2) {
			if ((piledata[ypos][xpos + 1] != 8) ||
				(piledata[ypos][xpos + 2] != 8) ||
				(piledata[ypos + 1][xpos] != 8) ||
				(piledata[ypos + 1][xpos + 1] != 8)) {
				return true;
			}
		}
		if (rot == 1 or rot == 3) {
			if ((piledata[ypos][xpos] != 8) ||
				(piledata[ypos + 1][xpos] != 8) ||
				(piledata[ypos + 1][xpos + 1] != 8) ||
				(piledata[ypos + 2][xpos + 1] != 8)) {
				return true;
			}
		}
	}

	else if (type == 5) {
		if (rot == 0 or rot == 2) {
			if ((piledata[ypos][xpos] != 8) ||
				(piledata[ypos][xpos + 1] != 8) ||
				(piledata[ypos + 1][xpos + 1] != 8) ||
				(piledata[ypos + 1][xpos + 2] != 8)) {
				return true;
			}
		}
		if (rot == 1 or rot == 3) {
			if ((piledata[ypos][xpos + 1] != 8) ||
				(piledata[ypos + 1][xpos + 1] != 8) ||
				(piledata[ypos + 1][xpos] != 8) ||
				(piledata[ypos + 2][xpos] != 8)) {
				return true;
			}
		}
	}

	else if (type == 6) {
		if (rot == 0) {
			if ((piledata[ypos][xpos + 1] != 8) ||
				(piledata[ypos + 1][xpos] != 8) ||
				(piledata[ypos + 1][xpos + 1] != 8) ||
				(piledata[ypos + 1][xpos + 2] != 8)) {
				return true;
			}
		}
		if (rot == 1) {
			if ((piledata[ypos + 1][xpos] != 8) ||
				(piledata[ypos][xpos + 1] != 8) ||
				(piledata[ypos + 1][xpos + 1] != 8) ||
				(piledata[ypos + 2][xpos + 1] != 8)) {
				return true;
			}
		}
		if (rot == 2) {
			if ((piledata[ypos][xpos] != 8) ||
				(piledata[ypos][xpos + 1] != 8) ||
				(piledata[ypos][xpos + 2] != 8) ||
				(piledata[ypos + 1][xpos + 1] != 8)) {
				return true;
			}
		}
		if (rot == 3) {
			if ((piledata[ypos][xpos] != 8) ||
				(piledata[ypos + 1][xpos] != 8) ||
				(piledata[ypos + 2][xpos] != 8) ||
				(piledata[ypos + 1][xpos + 1] != 8)) {
				return true;
			}
		}
	}
	return false;
}
bool CMap::IsBottom(CTetrimino* pTetrimino, int type) {
	int xpos = (pTetrimino->giveXpos() / 2) - 1;
	int ypos = pTetrimino->giveYpos();
	int blockypos[4] = { 0,0,0,0 };
	int rot = pTetrimino->giveRot();

	if (type == 0) {
		if (rot == 0 || rot == 2) {
			blockypos[0] = ypos+3;
			blockypos[1] = 0;
			blockypos[2] = 0;
			blockypos[3] = 0;
		}

		else if (rot == 1 || rot == 3) {
			blockypos[0] = ypos;
			blockypos[1] = ypos;
			blockypos[2] = ypos;
			blockypos[3] = ypos;
		}
	}

	else if (type == 1){
		blockypos[0] = ypos+1;
		blockypos[1] = ypos+1;
		blockypos[2] = 0;
		blockypos[3] = 0;
	}
	
	else if (type == 2){
		if (rot == 0){
			blockypos[0] = ypos;
			blockypos[1] = ypos;
			blockypos[2] = ypos+1;
			blockypos[3] = 0;
		}
		
		if (rot == 1) {
			blockypos[0] = ypos+2;
			blockypos[1] = ypos;
			blockypos[2] = 0;
			blockypos[3] = 0;
		}
		if (rot == 2) {
			blockypos[0] = ypos+1;
			blockypos[1] = ypos+1;
			blockypos[2] = ypos+1;
			blockypos[3] = 0;

		}
		if (rot == 3) {
			blockypos[0] = ypos+2;
			blockypos[1] = ypos+2;
			blockypos[2] = 0;
			blockypos[3] = 0;
		}
	}

	else if (type == 3) {
		if (rot == 0) {
			blockypos[0] = ypos+1;
			blockypos[1] = ypos+1;
			blockypos[2] = ypos+1;
			blockypos[3] = 0;

		}
		if (rot == 1) {
			blockypos[0] = ypos+2;
			blockypos[1] = ypos+2;
			blockypos[2] = 0;
			blockypos[3] = 0;

		}
		if (rot == 2) {
			blockypos[0] = ypos;
			blockypos[1] = ypos;
			blockypos[2] = ypos+1;
			blockypos[3] = 0;

		}
		if (rot == 3) {
			blockypos[0] = ypos+2;
			blockypos[1] = ypos;
			blockypos[2] = 0;
			blockypos[3] = 0;

		}
	}

	if (type == 4) {
		if (rot == 0 or rot == 2) {
			blockypos[0] = ypos+1;
			blockypos[1] = ypos+1;
			blockypos[2] = ypos;
			blockypos[3] = 0;
		}
		if (rot == 1 or rot == 3) {
			blockypos[0] = ypos+1;
			blockypos[1] = ypos+2;
			blockypos[2] = 0;
			blockypos[3] = 0;
		}
	}

	else if (type == 5) {
		if (rot == 0 or rot == 2) {
			blockypos[0] = ypos;
			blockypos[1] = ypos+1;
			blockypos[2] = ypos+1;
			blockypos[3] = 0;

		}
		if (rot == 1 or rot == 3) {
			blockypos[0] = ypos+2;
			blockypos[1] = ypos+1;
			blockypos[2] = 0;
			blockypos[3] = 0;

		}
	}

	else if (type == 6) {
		if (rot == 0) {
			blockypos[0] = ypos+1;
			blockypos[1] = ypos+1;
			blockypos[2] = ypos+1;
			blockypos[3] = 0;

		}
		if (rot == 1) {
			blockypos[0] = ypos+1;
			blockypos[1] = ypos+2;
			blockypos[2] = 0;
			blockypos[3] = 0;

		}
		if (rot == 2) {
			blockypos[0] = ypos;
			blockypos[1] = ypos+1;
			blockypos[2] = ypos;
			blockypos[3] = 0;

		}
		if (rot == 3) {
			blockypos[0] = ypos+2;
			blockypos[1] = ypos+1;
			blockypos[2] = 0;
			blockypos[3] = 0;
		}
	}
	getHeight(pTetrimino, ypos);
	if ((blockypos[0] == height[xpos] - 1) || (blockypos[1] == height[xpos + 1] - 1) || (blockypos[2] == height[xpos + 2] - 1) || (blockypos[3] == height[xpos + 3] - 1)) {
		 return true;
	}
	return false;

	
}

void CMap::RenderShadow(CConsoleOutput* pRender,CTetrimino* pTetrimino, int type) {
	int xpos = (pTetrimino->giveXpos() / 2) - 1;
	int ypos = pTetrimino->giveYpos();
	int blockypos[4] = { 0,0,0,0 };
	int rot = pTetrimino->giveRot();
	for (int i = 0; i < 18; i++) {
		for (int j = 0; j < 10; j++) {
			shadowdata[i][j] = 0;
		}
	}	
	while (1) {
	if (type == 0) {
		if (rot == 0 || rot == 2) {
			blockypos[0] = ypos + 3;
			blockypos[1] = 0;
			blockypos[2] = 0;
			blockypos[3] = 0;
		}

		else if (rot == 1 || rot == 3) {
			blockypos[0] = ypos;
			blockypos[1] = ypos;
			blockypos[2] = ypos;
			blockypos[3] = ypos;
		}
	}

	else if (type == 1) {
		blockypos[0] = ypos + 1;
		blockypos[1] = ypos + 1;
		blockypos[2] = 0;
		blockypos[3] = 0;
	}

	else if (type == 2) {
		if (rot == 0) {
			blockypos[0] = ypos;
			blockypos[1] = ypos;
			blockypos[2] = ypos + 1;
			blockypos[3] = 0;
		}

		if (rot == 1) {
			blockypos[0] = ypos + 2;
			blockypos[1] = ypos;
			blockypos[2] = 0;
			blockypos[3] = 0;
		}
		if (rot == 2) {
			blockypos[0] = ypos + 1;
			blockypos[1] = ypos + 1;
			blockypos[2] = ypos + 1;
			blockypos[3] = 0;

		}
		if (rot == 3) {
			blockypos[0] = ypos + 2;
			blockypos[1] = ypos + 2;
			blockypos[2] = 0;
			blockypos[3] = 0;
		}
	}

	else if (type == 3) {
		if (rot == 0) {
			blockypos[0] = ypos + 1;
			blockypos[1] = ypos + 1;
			blockypos[2] = ypos + 1;
			blockypos[3] = 0;

		}
		if (rot == 1) {
			blockypos[0] = ypos + 2;
			blockypos[1] = ypos + 2;
			blockypos[2] = 0;
			blockypos[3] = 0;

		}
		if (rot == 2) {
			blockypos[0] = ypos;
			blockypos[1] = ypos;
			blockypos[2] = ypos + 1;
			blockypos[3] = 0;

		}
		if (rot == 3) {
			blockypos[0] = ypos + 2;
			blockypos[1] = ypos;
			blockypos[2] = 0;
			blockypos[3] = 0;

		}
	}

	if (type == 4) {
		if (rot == 0 or rot == 2) {
			blockypos[0] = ypos + 1;
			blockypos[1] = ypos + 1;
			blockypos[2] = ypos;
			blockypos[3] = 0;
		}
		if (rot == 1 or rot == 3) {
			blockypos[0] = ypos + 1;
			blockypos[1] = ypos + 2;
			blockypos[2] = 0;
			blockypos[3] = 0;
		}
	}

	else if (type == 5) {
		if (rot == 0 or rot == 2) {
			blockypos[0] = ypos;
			blockypos[1] = ypos + 1;
			blockypos[2] = ypos + 1;
			blockypos[3] = 0;

		}
		if (rot == 1 or rot == 3) {
			blockypos[0] = ypos + 2;
			blockypos[1] = ypos + 1;
			blockypos[2] = 0;
			blockypos[3] = 0;

		}
	}

	else if (type == 6) {
		if (rot == 0) {
			blockypos[0] = ypos + 1;
			blockypos[1] = ypos + 1;
			blockypos[2] = ypos + 1;
			blockypos[3] = 0;

		}
		if (rot == 1) {
			blockypos[0] = ypos + 1;
			blockypos[1] = ypos + 2;
			blockypos[2] = 0;
			blockypos[3] = 0;

		}
		if (rot == 2) {
			blockypos[0] = ypos;
			blockypos[1] = ypos + 1;
			blockypos[2] = ypos;
			blockypos[3] = 0;

		}
		if (rot == 3) {
			blockypos[0] = ypos + 2;
			blockypos[1] = ypos + 1;
			blockypos[2] = 0;
			blockypos[3] = 0;
		}
	}
		if ((blockypos[0] == height[xpos] - 1) || (blockypos[1] == height[xpos + 1] - 1) || (blockypos[2] == height[xpos + 2] - 1) || (blockypos[3] == height[xpos + 3] - 1)) {
			break;
		}
		ypos++;
	}
	if (type == 0) {
		if (rot == 0 || rot == 2) {
			shadowdata[ypos][xpos] = type + 10;
			shadowdata[ypos + 1][xpos] = type + 10;
			shadowdata[ypos + 2][xpos] = type + 10;
			shadowdata[ypos + 3][xpos] = type + 10;
		}

		else if (rot == 1 || rot == 3) {
			shadowdata[ypos][xpos] = type +10;
			shadowdata[ypos][xpos + 1] = type + 10;
			shadowdata[ypos][xpos + 2] = type + 10;
			shadowdata[ypos][xpos + 3] = type + 10;
		}
	}

	else if (type == 1) {
		shadowdata[ypos][xpos] = type + 10;
		shadowdata[ypos][xpos + 1] = type + 10;
		shadowdata[ypos + 1][xpos] = type + 10;
		shadowdata[ypos + 1][xpos + 1] = type + 10;
	}

	else if (type == 2) {
		if (rot == 0) {
			shadowdata[ypos][xpos] = type + 10;
			shadowdata[ypos][xpos + 1] = type + 10;
			shadowdata[ypos][xpos + 2] = type+10;
			shadowdata[ypos + 1][xpos + 2] = type + 10;
		}

		if (type == 2 && rot == 1) {
			shadowdata[ypos][xpos] = type + 10;
			shadowdata[ypos][xpos + 1] = type + 10;
			shadowdata[ypos + 1][xpos] = type + 10;
			shadowdata[ypos + 2][xpos] = type + 10;
		}

		if (rot == 2) {
			shadowdata[ypos][xpos] = type + 10;
			shadowdata[ypos + 1][xpos] = type + 10;
			shadowdata[ypos + 1][xpos + 1] = type + 10;
			shadowdata[ypos + 1][xpos + 2] = type + 10;

		}
		if (rot == 3) {
			shadowdata[ypos][xpos + 1] = type + 10;
			shadowdata[ypos + 1][xpos + 1] = type + 10;
			shadowdata[ypos + 2][xpos + 1] = type + 10;
			shadowdata[ypos + 2][xpos] = type + 10;

		}
	}

	else if (type == 3) {
		if (rot == 0) {
			shadowdata[ypos][xpos] = type + 10;
			shadowdata[ypos + 1][xpos] = type + 10;
			shadowdata[ypos + 1][xpos + 1] = type + 10;
			shadowdata[ypos + 1][xpos + 2] = type + 10;

		}
		if (rot == 1) {
			shadowdata[ypos][xpos + 1] = type + 10;
			shadowdata[ypos + 1][xpos + 1] = type + 10;
			shadowdata[ypos + 2][xpos + 1] = type + 10;
			shadowdata[ypos + 2][xpos] = type + 10;

		}
		if (rot == 2) {
			shadowdata[ypos][xpos] = type + 10;
			shadowdata[ypos][xpos + 1] = type + 10;
			shadowdata[ypos][xpos + 2] = type + 10;
			shadowdata[ypos + 1][xpos + 2] = type + 10;

		}
		if (rot == 3) {
			shadowdata[ypos][xpos] = type + 10;
			shadowdata[ypos][xpos + 1] = type + 10;
			shadowdata[ypos + 1][xpos] = type + 10;
			shadowdata[ypos + 2][xpos] = type + 10;

		}
	}

	if (type == 4) {
		if (rot == 0 or rot == 2) {
			shadowdata[ypos][xpos + 1] = type + 10;
			shadowdata[ypos][xpos + 2] = type + 10;
			shadowdata[ypos + 1][xpos] = type + 10;
			shadowdata[ypos + 1][xpos + 1] = type + 10;

		}

		if (rot == 1 or rot == 3) {
			shadowdata[ypos][xpos] = type + 10;
			shadowdata[ypos + 1][xpos] = type + 10;
			shadowdata[ypos + 1][xpos + 1] = type + 10;
			shadowdata[ypos + 2][xpos + 1] = type + 10;

		}
	}

	else if (type == 5) {
		if (rot == 0 or rot == 2) {
			shadowdata[ypos][xpos] = type + 10;
			shadowdata[ypos][xpos + 1] = type + 10;
			shadowdata[ypos + 1][xpos + 1] = type + 10;
			shadowdata[ypos + 1][xpos + 2] = type + 10;
		}

		if (rot == 1 or rot == 3) {
			shadowdata[ypos][xpos + 1] = type + 10;
			shadowdata[ypos + 1][xpos + 1] = type + 10;
			shadowdata[ypos + 1][xpos] = type + 10;
			shadowdata[ypos + 2][xpos] = type + 10;
		}
	}

	else if (type == 6) {
		if (rot == 0) {
			shadowdata[ypos][xpos + 1] = type + 10;
			shadowdata[ypos + 1][xpos] = type + 10;
			shadowdata[ypos + 1][xpos + 1] = type + 10;
			shadowdata[ypos + 1][xpos + 2] = type + 10;
		}

		if (rot == 1) {
			shadowdata[ypos + 1][xpos] = type + 10;
			shadowdata[ypos][xpos + 1] = type + 10;
			shadowdata[ypos + 1][xpos + 1] = type + 10;
			shadowdata[ypos + 2][xpos + 1] = type + 10;
		}
		if (rot == 2) {
			shadowdata[ypos][xpos] = type + 10;
			shadowdata[ypos][xpos + 1] = type + 10;
			shadowdata[ypos][xpos + 2] = type + 10;
			shadowdata[ypos + 1][xpos + 1] = type + 10;

		}
		if (rot == 3) {
			shadowdata[ypos][xpos] = type + 10;
			shadowdata[ypos + 1][xpos] = type + 10;
			shadowdata[ypos + 2][xpos] = type + 10;
			shadowdata[ypos + 1][xpos + 1] = type + 10;

		}
	}
	for (int i = 0; i < 18; i++) {
		for (int j = 0; j < 10; j++) {
			if (shadowdata[i][j] == 0 + 10) {
				pRender->Printblock(2 * (j + 1), i, block_s, 2,type);
			}
			else if (shadowdata[i][j] == 1 + 10) {
				pRender->Printblock(2 * (j + 1), i, block_s, 2, type);
			}
			else if (shadowdata[i][j] == 2 + 10) {
				pRender->Printblock(2 * (j + 1), i, block_s, 2, type);
			}
			else if (shadowdata[i][j] == 3 + 10) {
				pRender->Printblock(2 * (j + 1), i, block_s, 2, type);
			}
			else if (shadowdata[i][j] == 4 + 10) {
				pRender->Printblock(2 * (j + 1), i, block_s, 2, type);
			}
			else if (shadowdata[i][j] == 5 + 10) {
				pRender->Printblock(2 * (j + 1), i, block_s, 2, type);
			}
			else if (shadowdata[i][j] == 6 + 10) {
				pRender->Printblock(2 * (j + 1), i, block_s, 2, type);
			}
		}
	}



}


void CMap::Pile(CTetrimino* pTetrimino,int type)
{
	int xpos = (pTetrimino->giveXpos()/2) -1;
	int ypos = pTetrimino->giveYpos();
	int rot = pTetrimino->giveRot();
	if (type == 0) {
		if (rot == 0 || rot == 2) {
			piledata[ypos][xpos] = type;
			piledata[ypos + 1][xpos] = type;
			piledata[ypos + 2][xpos] = type;
			piledata[ypos + 3][xpos] = type;
		}

		else if (rot == 1 || rot == 3) {
			piledata[ypos][xpos] = type;
			piledata[ypos][xpos + 1] = type;
			piledata[ypos][xpos + 2] = type;
			piledata[ypos][xpos + 3] = type;
		}
	}

	else if (type == 1) {
		piledata[ypos][xpos]= type;
		piledata[ypos][xpos + 1] = type;
			piledata[ypos + 1][xpos] = type;
			piledata[ypos + 1][xpos + 1] = type;
	}

	else if (type == 2) {
		if (rot == 0) {
			piledata[ypos][xpos] = type;
			piledata[ypos][xpos + 1] = type;
			piledata[ypos][xpos + 2] = type;
			piledata[ypos + 1][xpos + 2] = type;
		}

		if (type == 2 && rot == 1) {
			piledata[ypos][xpos] = type;
			piledata[ypos][xpos + 1] = type;
			piledata[ypos + 1][xpos] = type;
			piledata[ypos + 2][xpos] = type;
		}

		if (rot == 2) {
			piledata[ypos][xpos] = type;
			piledata[ypos + 1][xpos] = type;
			piledata[ypos + 1][xpos + 1] = type;
			piledata[ypos + 1][xpos + 2] = type;

		}
		if (rot == 3) {
			piledata[ypos][xpos + 1] = type;
			piledata[ypos + 1][xpos + 1] = type;
			piledata[ypos + 2][xpos + 1] = type;
			piledata[ypos + 2][xpos] = type;

		}
	}

	else if (type == 3) {
		if (rot == 0) {
			piledata[ypos][xpos] = type;
			piledata[ypos + 1][xpos] = type;
			piledata[ypos + 1][xpos + 1] = type;
			piledata[ypos + 1][xpos + 2] = type;

		}
		if (rot == 1) {
			piledata[ypos][xpos + 1] = type;
			piledata[ypos + 1][xpos + 1] = type;
			piledata[ypos + 2][xpos + 1] = type;
			piledata[ypos + 2][xpos] = type;

		}
		if (rot == 2) {
			piledata[ypos][xpos] = type;
			piledata[ypos][xpos + 1] = type;
			piledata[ypos][xpos + 2] = type;
			piledata[ypos + 1][xpos + 2] = type;

		}
		if (rot == 3) {
			piledata[ypos][xpos] = type;
			piledata[ypos][xpos + 1] = type;
			piledata[ypos + 1][xpos] = type;
			piledata[ypos + 2][xpos] = type;

		}
	}

	if (type == 4) {
		if (rot == 0 or rot == 2) {
			piledata[ypos][xpos + 1] = type;
			piledata[ypos][xpos + 2] = type;
			piledata[ypos + 1][xpos] = type;
			piledata[ypos + 1][xpos + 1] = type;

		}

		if (rot == 1 or rot == 3) {
			piledata[ypos][xpos] = type;
			piledata[ypos + 1][xpos] = type;
			piledata[ypos + 1][xpos + 1] = type;
			piledata[ypos + 2][xpos + 1] = type;

		}
	}

	else if (type == 5) {
		if (rot == 0 or rot == 2) {
			piledata[ypos][xpos] = type;
			piledata[ypos][xpos + 1] = type;
			piledata[ypos + 1][xpos + 1] = type;
			piledata[ypos + 1][xpos + 2] = type;
		}

		if (rot == 1 or rot == 3) {
			piledata[ypos][xpos + 1] = type;
			piledata[ypos + 1][xpos + 1] = type;
			piledata[ypos + 1][xpos] = type;
			piledata[ypos + 2][xpos] = type;
		}
	}

	else if (type == 6) {
		if (rot == 0) {
			piledata[ypos][xpos + 1] = type;
			piledata[ypos + 1][xpos] = type;
			piledata[ypos + 1][xpos + 1] = type;
			piledata[ypos + 1][xpos + 2] = type;
		}

		if (rot == 1) {
			piledata[ypos + 1][xpos] = type;
			piledata[ypos][xpos + 1] = type;
			piledata[ypos + 1][xpos + 1] = type;
			piledata[ypos + 2][xpos + 1] = type;
		}
		if (rot == 2) {
			piledata[ypos][xpos] = type;
			piledata[ypos][xpos + 1] = type;
			piledata[ypos][xpos + 2] = type;
			piledata[ypos + 1][xpos + 1] = type;

		}
		if (rot == 3) {
			piledata[ypos][xpos] = type;
			piledata[ypos + 1][xpos] = type;
			piledata[ypos + 2][xpos] = type;
			piledata[ypos + 1][xpos + 1] = type;

		}
	}
	getHeight(pTetrimino, ypos);

}

void CMap::OnDraw(CConsoleOutput* pRender)
{
		
	for (int i = 3; i < 18; i++)
	{
		pRender->Printblock(m_nPosX, m_nPosY + i, wall, 2,8);
		pRender->Printblock(m_nPosX+22, m_nPosY + i, wall, 2,8);
	}
	pRender->Printblock(m_nPosX, 18, bottom, 24 ,8);
	pRender->Printblock(m_nPosX, 19, bottom, 24,8);

	for (int i = 0; i < 18; i++) {
		for (int j = 0; j < 10; j++) {
			if (piledata[i][j] != 8) {
			pRender->Printblock(2 * (j + 1), i, block, 2, piledata[i][j]);
			}
		}
	}
}

void CMap::Crossline(CConsoleOutput* pRender)
{
	pRender->Printblock(m_nPosX, 3, bottom, 24, 8);
}

void CMap::EraseLine(int* score) {
	int sum;
	int cnt = 0;
	int num = 0;
	for (int i=0; i<18; i++) {
		sum = 0;
		for (int j = 0; j < 10; j++) {
			if (piledata[i][j] == 8) {
				break;
			}
			else {
				sum++;
			}
		}
		if (sum == 10) {
			cnt++;
			num = i;
		}
	}
	if (cnt != 0) {
		*score += cnt * 10;
		for (int i = num; cnt <= i; i--) {
			for (int j = 0; j < 10; j++) {
				piledata[i][j] = piledata[i - cnt][j];
			}
		}
	}
}


void CMap::Score(CConsoleOutput* pRender,int score, int time)
{	
	std::string sc =  string_format("Score : %d", score);
	std::string tm = string_format("Play time : %.2f sec",(double)time/(double)100);
	pRender->Print(30, 3, sc, 24);
	pRender->Print(30, 5, tm, 24);
}

void CMap::logo(CConsoleOutput* pRender)
{
		std::string logo1 = "tttttttt eeeeeeee tttttttt rrrrrrr   iiiiiiii   sssssss";
		std::string logo2 = "   tt    ee          tt    rr    rrr    ii    ssss     ";
		std::string logo3 = "   tt    ee          tt    rr    rrr    ii   ssss   ";
		std::string logo4 = "   tt    eeeeeeee    tt    rrrrrrrr     ii      ssssssss   ";
		std::string logo5 = "   tt    ee          tt    rr   rrr     ii            ssss";
		std::string logo6 = "   tt    ee          tt    rr    rrr    ii           ssss ";
		std::string logo7 = "   tt    eeeeeeee    tt    rr     rr iiiiiiii   ssssss   ";
		pRender->Print(27, 9, logo1, 104);
		pRender->Print(27, 10, logo2, 104);
		pRender->Print(27, 11, logo3, 104);
		pRender->Print(27, 12, logo4, 104);
		pRender->Print(27, 13, logo5, 104);
		pRender->Print(27, 14, logo6, 104);
		pRender->Print(27, 15, logo7, 104);
						
}