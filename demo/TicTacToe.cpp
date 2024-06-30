// 控制台井字棋游戏：方向键控制下棋位置，enter键下棋。
// 刚学cpp类的时候心血来潮搞的，花了好长时间才做出来的四不像。
// 虽然做得很烂，但有一说一，当时的我真的好有耐心，竟然可以忍受把所有东西都写在一个文件里（世称：单文件战神），而且还能写出来。
// 以后有空了会重构，还是用控制台做UI，争取多点功能。

// ONLY UTF-8
#include <iostream>
#include <string>
#include <stdlib.h>
#include <conio.h>

void cls()
{
    system("cls");
}

int GetKeycode();

class Chess;

class Cursor
{
public:
    int CursorX = 0;
    int CursorY = 0;
    int MoveArrow = 0;
    // MoveArrow:1->left,2->right,3->down,4->up
    bool IsOut();
    bool isoccupy = 0;
    void IsOccupy(Chess C);
    int CursorArrow(int Keycode);
    void GetCursorArrow(int k);
    void CursorJump();
    void CursorMove(Chess C);
    void CursorWalk();
    void outputXY()
    {
        std::cout << CursorX << '\t' << CursorY << std::endl;
    }
} Cursor1;

class Chess
{
public:
    bool IsExist[3][3] = {0};
    bool IsCross[3][3] = {0}; // "x" or "o"
    int record[9] = {0};      // Recording IsExist (e.g. {1,1,1,0,0,0,0,1,0})
    void PlayerPress(Cursor A);
    void ComputerPress(int i, int j);
    void Record();
    bool IsPress();
    bool IsWin();
    bool IsLose();
    bool IsFull();
    void CMPlaying();
    // debug
    void OutputIsExist();
    void OutputIsCross();

} Chess1;

class Blocks
{
public:
    std::string Block[14][7];
    Blocks();
    void Loadscene(Cursor A, Chess C);
    void MoveFrame();
    void Print();
} Blocks1;

bool IsEnd(Chess C)
{
    if (C.IsWin() || C.IsLose() || C.IsFull())
    {
        return true;
    }
    return false;
}

void Endscreen(Blocks B, Chess C)
{
    B.MoveFrame();
    B.Print();
    if (C.IsWin())
    {
        std::cout << "Win(●'◡'●)" << std::endl;
    }
    else if (C.IsLose())
    {
        std::cout << "Lose(; w ;)" << std::endl;
    }
    else
    {
        std::cout << "Draw(~ ￣▽￣)~ " << std::endl;
    }
}

int GetKeycode()
{
    // Pressing the arrow keys would return 2 keycodes:"224", and a number indicates the direction.
    int Keycode1, Keycode2;
    while (1)
    {
        if (_kbhit())
        {
            Keycode1 = _getch();
            if (Keycode1 != 224) // If not pressing arrow key
            {
                return Keycode1;
            }
            Keycode2 = _getch();
            return Keycode2;
        }
    }
}

Blocks::Blocks()
{
    {
        for (int i = 0; i < 7; i++)
        {
            Block[13][i] = "\n";
        }
        for (int i = 0; i < 7; i += 2)
        {
            for (int j = 1; j < 13; j += 4)
            {
                for (int k = j; k < j + 3; k++)
                {
                    Block[k][i] = "\u2501";
                }
            }
        }
        for (int i = 0; i < 7; i += 2)
        {
            for (int j = 4; j < 9; j += 4)
            {
                if (i == 0)
                {
                    Block[j][i] = "\u2533";
                }
                else if (i == 6)
                {
                    Block[j][i] = "\u253B";
                }
                else
                {
                    Block[j][i] = "\u254B";
                }
            }
        }

        for (int i = 2; i < 5; i += 2)
        {
            for (int j = 0; j < 13; j += 12)
            {
                if (j == 0)
                {
                    Block[j][i] = "\u2523";
                }
                else
                {
                    Block[j][i] = "\u252b";
                }
            }
        }
        Block[0][0] = "\u250F";
        Block[12][0] = "\u2513";
        Block[0][6] = "\u2517";
        Block[12][6] = "\u251B";
        for (int i = 1; i <= 5; i += 2)
        {
            for (int j = 0; j < 13; j++)
            {

                if (j % 4 == 0)
                {
                    Block[j][i] = "\u2503";
                }
                else
                {
                    Block[j][i] = " ";
                }
            }
        }
        Block[2][1] = "·";
    }
}

void Blocks::Loadscene(Cursor A, Chess C)
{
    bool IsEnd;
    if (C.IsWin() || C.IsLose() || C.IsFull())
    {
        IsEnd = true;
    }
    else
    {
        IsEnd = false;
    }
    for (int i = 1; i <= 5; i += 2)
    {
        for (int j = 0; j < 13; j++)
        {
            if (j % 4 != 0)
            {
                Block[j][i] = " ";
            }
        }
    }
    Block[4 * (A.CursorX + 1) - 2][2 * (A.CursorY + 1) - 1] = "·";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (C.IsExist[i][j])
            {
                if (C.IsCross[i][j] == true)
                {
                    if (A.CursorX == i && A.CursorY == j && !IsEnd)
                    {
                        Block[4 * (i + 1) - 2][2 * (j + 1) - 1] = "\u1e8b";
                    }
                    else
                    {
                        Block[4 * (i + 1) - 2][2 * (j + 1) - 1] = "x";
                    }
                }
                else
                {
                    if (A.CursorX == i && A.CursorY == j && !IsEnd)
                    {
                        Block[4 * (i + 1) - 2][2 * (j + 1) - 1] = "\u022f";
                    }
                    else
                    {
                        Block[4 * (i + 1) - 2][2 * (j + 1) - 1] = "o";
                    }
                }
            }
        }
    }
}
void Blocks::MoveFrame()
{
    for (int i = 0; i < 7; i += 2)
    {
        for (int j = 0; j < 13; j++)
        {
            Block[j][i] = " ";
        }
    }
    for (int i = 1; i < 7; i += 2)
    {
        for (int j = 0; j < 13; j += 4)
        {
            Block[j][i] = " ";
        }
    }
}

void Blocks::Print()
{
    for (int c = 0; c < 7; c++)
    {
        for (int i = 0; i < 14; i++)
        {
            std::cout << Block[i][c];
        }
    }
}
void Cursor::CursorMove(Chess C)
{
    CursorWalk();
    CursorJump();
}

bool Cursor::IsOut()
{
    if (CursorX > 2 || CursorX < 0 || CursorY > 2 || CursorY < 0)
    {
        return 1;
    }
    return 0;
}

void Cursor::IsOccupy(Chess C)
{
    if (C.IsExist[CursorX][CursorY])
    {
        isoccupy = true;
    }
    else
    {
        isoccupy = false;
    }
}

int Cursor::CursorArrow(int Keycode)
{
    switch (Keycode)
    {
    case 75:
    {
        return 1; // left
    }
    case 77:
    {
        return 2; // right
    }
    case 80:
    {
        return 3; // down
    }
    case 72:
    {
        return 4; // up
    }
    default:
    {
        std::cout << "something wrong" << std::endl;
        break;
    }
    }
    return 0;
}

void Cursor::GetCursorArrow(int k)
{
    MoveArrow = CursorArrow(k);
}

void Cursor::CursorJump()
{
    if (IsOut())
    {
        switch (MoveArrow)
        {
        case 1:
        {
            CursorX = 2;
            break;
        }
        case 2:
        {
            CursorX = 0;
            break;
        }
        case 3:
        {
            CursorY = 0;
            break;
        }
        case 4:
        {
            CursorY = 2;
            break;
        }
        default:
            break;
        }
    }
}

void Cursor::CursorWalk()
{
    switch (MoveArrow)
    {
    case 1:
    {
        --CursorX;
        break;
    }
    case 2:
    {
        CursorX++;
        break;
    }
    case 3:
    {
        CursorY++;
        break;
    }
    case 4:
    {
        --CursorY;
        break;
    }
    default:
        break;
    }
}

void Chess::PlayerPress(Cursor A)
{
    if (!IsExist[A.CursorX][A.CursorY])
    {
        IsExist[A.CursorX][A.CursorY] = true;
        IsCross[A.CursorX][A.CursorY] = false;
    }
}

void Chess::ComputerPress(int i, int j)
{
    if (!IsExist[i][j])
    {
        IsExist[i][j] = true;
        IsCross[i][j] = true;
    }
}

void Chess::OutputIsExist()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << IsExist[j][i] << '\t';
        }
        std::cout << std::endl;
    }
}
void Chess::OutputIsCross()
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << IsCross[j][i] << '\t';
        }
        std::cout << std::endl;
    }
}

bool Chess::IsWin()
{
    for (int i = 0; i < 3; i++)
    {
        if (IsExist[i][0] && IsExist[i][1] && IsExist[i][2])
        {
            if (!IsCross[i][0] && !IsCross[i][1] && !IsCross[i][2])
            {
                return true;
            }
        }
        if (IsExist[0][i] && IsExist[1][i] && IsExist[2][i])
        {
            if (!IsCross[0][i] && !IsCross[1][i] && !IsCross[2][i])
            {
                return true;
            }
        }
    }
    if (IsExist[0][0] && IsExist[1][1] && IsExist[2][2])
    {
        if (!IsCross[0][0] && !IsCross[1][1] && !IsCross[2][2])
        {
            return true;
        }
    }
    if (IsExist[2][0] && IsExist[1][1] && IsExist[0][2])
    {
        if (!IsCross[2][0] && !IsCross[1][1] && !IsCross[0][2])
        {
            return true;
        }
    }
    return false;
}

void Chess::Record()
{
    int count = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (IsExist[i][j])
            {
                record[count] = 1;
                count++;
            }
        }
    }
}

bool Chess::IsPress()
{
    int orec[9];
    for (int i = 0; i < 9; i++)
    {
        orec[i] = record[i];
    }
    Record();
    for (int i = 0; i < 9; i++)
    {
        if (orec[i] != record[i])
        {
            return true;
        }
    }
    return false;
}
bool Chess::IsLose()
{
    for (int i = 0; i < 3; i++)
    {
        if (IsExist[i][0] && IsExist[i][1] && IsExist[i][2])
        {
            if (IsCross[i][0] && IsCross[i][1] && IsCross[i][2])
            {
                return true;
            }
        }
        if (IsExist[0][i] && IsExist[1][i] && IsExist[2][i])
        {
            if (IsCross[0][i] && IsCross[1][i] && IsCross[2][i])
            {
                return true;
            }
        }
    }
    if (IsExist[0][0] && IsExist[1][1] && IsExist[2][2])
    {
        if (IsCross[0][0] && IsCross[1][1] && IsCross[2][2])
        {
            return true;
        }
    }
    if (IsExist[2][0] && IsExist[1][1] && IsExist[0][2])
    {
        if (IsCross[2][0] && IsCross[1][1] && IsCross[0][2])
        {
            return true;
        }
    }
    return false;
}

bool Chess::IsFull()
{
    Record();
    int count = 0;
    for (int i = 0; i < 9; i++)
    {
        count += record[i];
    }
    if (count == 9)
    {
        return true;
    }
    return false;
}

void Chess::CMPlaying()
{
    int i, j = 0;
    int Judge;
    for (i = 0; i < 3; i++)
    {
        Judge = 0;
        for (j = 0; j < 3; j++)
        {
            if (IsCross[i][j])
            {
                Judge++;
            }
        }
        if (Judge == 2)
        {
            for (j = 0; j < 3; j++)
            {
                if (!IsExist[i][j])
                {
                    ComputerPress(i, j);
                    return;
                }
            }
        }
    }

    for (i = 0; i < 3; i++)
    {
        Judge = 0;
        for (j = 0; j < 3; j++)
        {
            if (IsCross[j][i])
            {
                Judge++;
            }
        }
        if (Judge == 2)
        {
            for (j = 0; j < 3; j++)
            {
                if (!IsExist[j][i])
                {
                    ComputerPress(j, i);
                    return;
                }
            }
        }
    }

    Judge = 0;
    for (i = 0; i < 3; i++)
    {
        if (IsCross[i][i])
        {
            Judge++;
        }
        if (Judge == 2)
        {
            for (j = 0; j < 3; j++)
            {
                if (!IsExist[j][j])
                {
                    ComputerPress(j, j);
                    return;
                }
            }
        }
    }
    Judge = 0;
    for (i = 0; i < 3; i++)
    {
        if (IsCross[i][2 - i])
        {
            Judge++;
        }
        if (Judge == 2)
        {
            for (j = 0; j < 3; j++)
            {
                if (!IsExist[j][2 - j])
                {
                    ComputerPress(j, 2 - j);
                    return;
                }
            }
        }
    }

    if (!IsExist[1][1])
    {
        ComputerPress(1, 1);
        return;
    }
    for (i = 0; i < 3; i += 2)
    {
        for (j = 0; j < 3; j += 2)
        {
            if (!IsExist[i][j])
            {
                ComputerPress(i, j);
                return;
            }
        }
    }
    for (i = 1; i < 3; i++)
    {
        j = i - 1;
        if (!IsExist[i][j])
        {
            ComputerPress(i, j);
            return;
        }
        if (!IsExist[j][i])
        {
            ComputerPress(j, i);
            return;
        }
    }
}

int main(void)
{
    system("chcp 65001");
    int keycode;
    while (true)
    {
        cls();
        // debug
        // Cursor1.outputXY();
        // Chess1.OutputIsExist();
        // std::cout << std::endl;
        // Chess1.OutputIsCross();
        Blocks1.Loadscene(Cursor1, Chess1);
        if (IsEnd(Chess1))
        {
            Endscreen(Blocks1, Chess1);
            system("pause");
            return 0;
        }
        Blocks1.Print();
        keycode = GetKeycode();
        if (keycode == 13) // If pressing "ENTER"
        {
            Chess1.Record();
            Chess1.PlayerPress(Cursor1);
            if (!IsEnd(Chess1) && Chess1.IsPress())
            {
                Chess1.CMPlaying();
            }
        }
        else if (keycode == 27) // If pressing "ESC"
        {
            break;
        }
        else
        {
            Cursor1.GetCursorArrow(keycode);
            Cursor1.CursorMove(Chess1);
        }
        Blocks1.Loadscene(Cursor1, Chess1);
    }
    cls();
    std::cout << "Thanks for playing!" << std::endl;
    return 0;
}
