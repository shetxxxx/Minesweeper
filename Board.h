#ifndef BOARD_H
#define BOARD_H

class Board {
private:
    static const int SIZE = 10; // Размер поля 10x10
    char hiddenMap[SIZE][SIZE]; // Скрытая карта (где лежат мины '*')
    char visibleMap[SIZE][SIZE]; // Видимая игроку карта (пока все закрыто '#')

public:
    Board(); // Конструктор
    void placeMines(int count); // Расстановка мин
    char getVisibleCell(int x, int y) const; // Узнать символ клетки для отрисовки
    int getSize() const { return SIZE; }
};

#endif
