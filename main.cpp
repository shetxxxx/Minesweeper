#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime>
#include "Board.h"

void setCursorPosition(int x, int y) {
    COORD coord = { (SHORT)x, (SHORT)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

int main() {
    srand(time(0));
    Board board; // Создаем игровое поле

    int cursorX = 0, cursorY = 0; // Координаты прицела игрока
    bool running = true;

    // Скрываем стандартный мигающий курсор консоли
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info = { 100, FALSE };
    SetConsoleCursorInfo(consoleHandle, &info);

    while (running) {
        setCursorPosition(0, 0);
        std::cout << "=== SAPER (Step 1: Board & Cursor) ===\n\n";

        // Отрисовка сетки 10x10 с курсором [ ]
        for (int y = 0; y < board.getSize(); y++) {
            for (int x = 0; x < board.getSize(); x++) {
                if (x == cursorX && y == cursorY) {
                    std::cout << "[" << board.getVisibleCell(x, y) << "]";
                } else {
                    std::cout << " " << board.getVisibleCell(x, y) << " ";
                }
            }
            std::cout << "\n";
        }
        std::cout << "\nControls: Arrows / WASD | ESC to exit\n";

        // Ждем нажатия клавиши (в Сапёре экран обновляется только после хода)
        int key = _getch();
        if (key == 224 || key == 0) { // Стрелочки
            key = _getch();
            if (key == 72 && cursorY > 0) cursorY--;
            if (key == 80 && cursorY < board.getSize() - 1) cursorY++;
            if (key == 75 && cursorX > 0) cursorX--;
            if (key == 77 && cursorX < board.getSize() - 1) cursorX++;
        } else {
            if ((key == 'w' || key == 'W') && cursorY > 0) cursorY--;
            if ((key == 's' || key == 'S') && cursorY < board.getSize() - 1) cursorY++;
            if ((key == 'a' || key == 'A') && cursorX > 0) cursorX--;
            if ((key == 'd' || key == 'D') && cursorX < board.getSize() - 1) cursorX++;
            if (key == 27) running = false; // ESC
        }
    }

    return 0;
}
