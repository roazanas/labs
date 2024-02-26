#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int board[8][8] = { 0 };        // Инициализация доски из 0 (свободных клеток)
int iteration = 0;              // Глобальная переменная для подсчёта итераций
int solution = 1;               // Глобальная переменная для подсчёта решений
bool inner = false;             // Выводить элементы двумерного списка?

void saveBoard(bool is_inner, string type) {
    if (!is_inner) {
        ofstream fout("queen\\" + to_string(solution) + "_solution.txt", ios_base::app);
        fout << "Итерация #" + to_string(iteration) + " | " + type + "\n";
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                switch (board[i][j]) {
                    case -10: fout << "• "; break;
                    case  -1: fout << "Q "; break;
                    case   0: fout << ". "; break;
                    default : fout << "x "; break;
                }
            }
            fout << '\n';
        }
        fout << "\n|==============|\n\n";
    }
    else {
        ofstream fout("queen\\" + to_string(solution) + "_solution_inner.txt", ios_base::app);
        fout << "Итерация #" + to_string(iteration) + " | " + type + "\n";
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                fout << board[i][j] << ' ';
            }
            fout << '\n';
        }
        fout << "\n|==============|\n\n";
    }
    iteration++;
}

void resetBoard() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board[i][j] = 0;
        }
    }
}

void checkResetedQueen(int i) {
    for (int j = 0; j < 8; j++) {
        if ((-10 <= board[i][j]) && (board[i][j] < -1)) {
            board[i][j] += 10;
        }
    }
}

void setQueen(int i, int j) {
    for (int x = 0; x < 8; x++) {
        ++board[x][j];          // Разметка вертикали
        ++board[i][x];          // Разметка горизонтали

        int d;
        // Разметка главной диагонали
        d = j - i + x;
        if (0 <= d && d <= 7) {
            ++board[x][d];
        }
        // Разметка побочной диагонали
        d = j + i - x;
        if (0 <= d && d <= 7) {
            ++board[x][d];
        }
    }
    board[i][j] = -1;           // Разметка ферзя
}

void resetQueen(int i, int j) {
    for (int x = 0; x < 8; x++) {
        --board[x][j];          // Разметка вертикали
        --board[i][x];          // Разметка горизонтали

        int d;
        // Разметка главной диагонали
        d = j - i + x;
        if (0 <= d && d <= 7) {
            --board[x][d];
        }
        // Разметка побочной диагонали
        d = j + i - x;
        if (0 <= d && d <= 7) {
            --board[x][d];
        }
    }
    board[i][j] = -10;           // Разметка ферзя
}

bool tryQueen(int i) {
    bool result = false;
    for (int j = 0; (j < 8) && (!result); j++) {
        if (i == 0) { j = solution - 1; }
        if ((board[i][j] == 0) || (board[i][j] == -10)) {
            setQueen(i, j);
            saveBoard(inner, "+ферзь на " + to_string(i+1) + " строке");

            if (i == 7) {
                result = true;  // Последнего ферзя поставили
            }
            else {
                result = tryQueen(i + 1);
                if (!result) {
                    resetQueen(i, j);
                    if ((i+1) < 8) { checkResetedQueen(i+1); }
                    saveBoard(inner, "-ферзь на " + to_string(i+1) + " строке");
                }
            }
        }
    }
    if ((i == 0) && (result)) {
        iteration = 0;
        solution++;
        resetBoard();
    }
    return result;
}

int main() {
    setlocale(LC_ALL, "Russian");
    while (solution <= 8) {
        saveBoard(inner, "инициализация доски");
        tryQueen(0);
    }
    return 0;
}
