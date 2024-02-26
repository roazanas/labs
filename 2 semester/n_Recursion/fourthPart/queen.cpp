#include <iostream>
#include <string>
#include <fstream>
using namespace std;
int board[8][8] = { 0 };        // ������������� ����� �� 0 (��������� ������)
int iteration = 0;              // ���������� ���������� ��� �������� ��������
int solution = 1;               // ���������� ���������� ��� �������� �������
bool inner = false;             // �������� �������� ���������� ������?

void saveBoard(bool is_inner, string type) {
    if (!is_inner) {
        ofstream fout("queen\\" + to_string(solution) + "_solution.txt", ios_base::app);
        fout << "�������� #" + to_string(iteration) + " | " + type + "\n";
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                switch (board[i][j]) {
                    case -10: fout << "� "; break;
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
        fout << "�������� #" + to_string(iteration) + " | " + type + "\n";
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
        ++board[x][j];          // �������� ���������
        ++board[i][x];          // �������� �����������

        int d;
        // �������� ������� ���������
        d = j - i + x;
        if (0 <= d && d <= 7) {
            ++board[x][d];
        }
        // �������� �������� ���������
        d = j + i - x;
        if (0 <= d && d <= 7) {
            ++board[x][d];
        }
    }
    board[i][j] = -1;           // �������� �����
}

void resetQueen(int i, int j) {
    for (int x = 0; x < 8; x++) {
        --board[x][j];          // �������� ���������
        --board[i][x];          // �������� �����������

        int d;
        // �������� ������� ���������
        d = j - i + x;
        if (0 <= d && d <= 7) {
            --board[x][d];
        }
        // �������� �������� ���������
        d = j + i - x;
        if (0 <= d && d <= 7) {
            --board[x][d];
        }
    }
    board[i][j] = -10;           // �������� �����
}

bool tryQueen(int i) {
    bool result = false;
    for (int j = 0; (j < 8) && (!result); j++) {
        if (i == 0) { j = solution - 1; }
        if ((board[i][j] == 0) || (board[i][j] == -10)) {
            setQueen(i, j);
            saveBoard(inner, "+����� �� " + to_string(i+1) + " ������");

            if (i == 7) {
                result = true;  // ���������� ����� ���������
            }
            else {
                result = tryQueen(i + 1);
                if (!result) {
                    resetQueen(i, j);
                    if ((i+1) < 8) { checkResetedQueen(i+1); }
                    saveBoard(inner, "-����� �� " + to_string(i+1) + " ������");
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
        saveBoard(inner, "������������� �����");
        tryQueen(0);
    }
    return 0;
}
