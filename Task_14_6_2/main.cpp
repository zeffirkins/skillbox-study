#include <iostream>


void input (char field [][3], char ch)
{
    int x, y;
    do
    {
        std::cout << "\nTurn " << ch << ". Input coordinates: ";
        std::cin >> x >> y;
    } while ((x < 0 || x > 2) || (y < 0 || y > 2) || (field[x][y] != '-'));

    field[x][y] = ch;
}


void print (char field [][3])
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            std::cout << field[i][j] << " ";
        }
        std::cout << std::endl;
    }
}


bool isWin (char field[][3])
{

    // Проверка выигрыша по горизонтали \ вертикали
    for (int i = 0; i < 3; ++i)
    {
        bool matchHorizont = false;
        bool matchVertical = false;
        for (int j = 0; j < 2; ++j)
        {
            if ((field[i][j] == field[i][j+1]) && (field[i][j] != '-') && matchHorizont)
                return true;
            else
            if ((field[i][j] == field[i][j+1]) && (field[i][j] != '-'))
                matchHorizont = true;

            if ((field[j][i] == field[j+1][i]) && (field[j][i] != '-') && matchVertical)
                return true;
            else
            if ((field[j][i] == field[j+1][i]) && (field[j][i] != '-'))
                matchVertical = true;
        }
    }

    // Проверка выигрыша по диагоналям
    bool matchMainDiag = false;
    bool matchSideDiag = false;
    for (int i = 0; i < 2; ++i)
    {
        if ((field[i][i] == field[i+1][i+1]) && (field[i][i] != '-') && matchMainDiag)
            return true;
        else
        if ((field[i][i] == field[i+1][i+1]) && (field[i][i] != '-'))
            matchMainDiag = true;

        if ((field[i][2-i] == field[i+1][2-(i+1)]) && (field[i][2-i] != '-') && matchSideDiag)
            return true;
        else
        if ((field[i][2-i] == field[i+1][2-(i+1)]) && (field[i][2-i] != '-'))
            matchSideDiag = true;
    }

    return false;
}


int main()
{
    char playingField [3][3] = {'-', '-', '-',
                                '-', '-', '-',
                                '-', '-', '-'};

    for (int turn = 1; (turn <= 9) && !(isWin(playingField)); ++turn)
    {
        input (playingField, ((turn % 2 == 0) ? 'X' : 'O'));
        print (playingField);
        if (isWin (playingField))
            std::cout << "\n>>> " << ((turn % 2 == 0) ? 'X' : 'O') << " win <<<";
    }

    if (!isWin(playingField))
        std::cout << "\n>>> Draw <<<";

}