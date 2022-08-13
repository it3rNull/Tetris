#include "pch.h"
#include "Tetris.h"

enum E_GAMEKEY_TYPE
{
    GAMEKEY_LEFT,
    GAMEKEY_RIGHT,
    GAMEKEY_ROTATE,
    GAMEKEY_DOWN,
    GAMEKEY_SMASH,
};

CTetris::CTetris(void)
    : m_Map()
    , m_Tetrimino()
    , m_Input()
    , m_Output()
    , type()
{
    arr = new int[7];
    for (int i = 0; i < 7; i++) {
        arr[i] = i;
    }
    shuffle(arr, 7);
    type = arr[count];
    m_Map.Clear();
    m_Tetrimino.Reset(type);
    count++;
    m_Input.Register(GAMEKEY_LEFT,      VK_LEFT);
    m_Input.Register(GAMEKEY_RIGHT,     VK_RIGHT);
    m_Input.Register(GAMEKEY_ROTATE,        VK_UP);
    m_Input.Register(GAMEKEY_DOWN,      VK_DOWN);
    m_Input.Register(GAMEKEY_SMASH,    VK_SPACE);
    m_Output.Create(TEXT("BoB TETRIS"), COORD{ 100, 30 }, COORD{ 400, 30 });
}

CTetris::~CTetris(void)
{
    m_Output.Destroy();
}

void CTetris::Input(std::list<ST_KEYSTATE>& outState)
{
    m_Input.Query(outState);
}

void CTetris::Update(const std::list<ST_KEYSTATE> stKeyState, int nElapsedTick, int tick)
{
    int xpos = m_Tetrimino.giveXpos();
    int ypos = m_Tetrimino.giveYpos();
    m_Tetrimino.PushState();
    if (tick % 35 == 0) {
     m_Tetrimino.Fall();
    }
    for (ST_KEYSTATE key : stKeyState)
    {
        if (!key.bPressed)
            continue;

        switch (key.nID)
        {
        case GAMEKEY_LEFT:
            m_Tetrimino.Move(-1,type);
            break;
        case GAMEKEY_RIGHT:
            m_Tetrimino.Move(1,type);
            break;
        case GAMEKEY_ROTATE:
            m_Tetrimino.Rotate();
            break;
        case GAMEKEY_DOWN:
            m_Tetrimino.Move(2, type);
            break;
        case GAMEKEY_SMASH:
            while (!(m_Map.IsBottom(&m_Tetrimino, type))) {
                m_Tetrimino.Move(2,type);
            }
            break;
        }
    }
    m_Tetrimino.Rightend(type);
    if (m_Map.IsBottom(&m_Tetrimino, type)) {
        m_Map.Pile(&m_Tetrimino, type);
        m_Map.EraseLine(&score);
        if (m_Map.Gameover()) {
            shuffle(arr, 7);
            count = 0;
            type = arr[count % 7];
            m_Map.Clear();
            m_Tetrimino.Reset(type);
            return;
        }
        if (count % 7 == 0) {
            shuffle(arr, 7);
        }
        type = arr[count%7];
        count++;
        m_Tetrimino.Reset(type);
    }
    if (m_Map.IsCollide(&m_Tetrimino, type)) {
        m_Tetrimino.RestoreState();
    }
    else
        m_Tetrimino.PopState();
}

void CTetris::Render(int tick)
{
    m_Output.Clear();
    m_Map.RenderShadow(&m_Output, &m_Tetrimino, type);
    m_Tetrimino.Draw(&m_Output,type);
    m_Map.Crossline(&m_Output);
    m_Map.OnDraw(&m_Output);
    m_Map.Score(&m_Output,score,tick);
    m_Map.logo(&m_Output);
    m_Output.Flip(SMALL_RECT{ 0, 0, 400, 300 }, COORD{ 10, 5 });
}

bool CTetris::Next(void) {
    return m_Map.IsBottom(&m_Tetrimino, type);
}


void printarr(int* arr, int num)
{
    for (int i = 0; i < num; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


void shuffle(int* arr, int num)
{
    srand(time(NULL));
    int temp;
    int rn;
    for (int i = 0; i < num - 1; i++)
    {
        rn = rand() % (num - i) + i; 
        temp = arr[i];
        arr[i] = arr[rn];
        arr[rn] = temp;
    }
}