#include "Board.h"
#include <cstdlib>

Board::Board() {
    // Заполняем обе карты стартовыми значениями
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            hiddenMap[i][j] = '0';  // Пусто
            visibleMap[i][j] = '#'; // Закрытая клетка (туман войны)
        }
    }
    placeMines(12); // Ставим 12 мин
}

void Board::placeMines(int count) {
    int placed = 0;
    while (placed < count) {
        int x = rand() % SIZE;
        int y = rand() % SIZE;
        // Ставим мину, если в этой клетке её еще нет
        if (hiddenMap[y][x] != '*') {
            hiddenMap[y][x] = '*';
            placed++;
        }
    }
}

char Board::getVisibleCell(int x, int y) const {
    return visibleMap[y][x];
}
