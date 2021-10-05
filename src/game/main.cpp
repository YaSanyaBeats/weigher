#include <SFML/Graphics.hpp>
#include <game.h>
#include <iostream>
#include <menu.h>
#include <string>
#include <vector>

using namespace std;
using namespace sf;

int main()
{
    RenderWindow window(sf::VideoMode(1000, 600), "Weigher game");

    vector<vector<string>> words;

    string easyWords[3][4]
            = {{"������", "������", "�����", "�����"},
               {"������", "�������", "������", "�����"},
               {"��������", "����", "�����", "���"}};
    string middleWords[3][4]
            = {{"������", "������", "��������", "�����"},
               {"������", "������", "������", "������"},
               {"��������", "�����", "�����", "�������"}};
    string hardWords[3][4]
            = {{"������", "�������", "�����", "������"},
               {"������", "������", "�������", "���������"},
               {"��������", "����", "�����", "������"}};

    int win;
    while (1) {
        int difficult = callMenu(window);
        if (difficult == 1) {
            win = startGame(window, easyWords);
        } else if (difficult == 2) {
            win = startGame(window, middleWords);
        } else {
            win = startGame(window, hardWords);
        }
        cout << win;
    }

    return 0;
}
