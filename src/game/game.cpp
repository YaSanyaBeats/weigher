#include <SFML/Graphics.hpp>
#include <bg.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
using namespace sf;

struct keyboardSymbol {
    string str;
    string folder;
};

void drawKeyboard(RenderWindow& window, vector<keyboardSymbol> keyboardSymbols)
{
    for (unsigned int i = 0; i < keyboardSymbols.size(); i++) {
        RectangleShape currentSymbol;
        Texture texture;
        if (!texture.loadFromFile(keyboardSymbols[i].folder)) {
            cout << "Error, " + keyboardSymbols[i].folder + " not found";
        }
        currentSymbol.setTexture(&texture);
        currentSymbol.setSize(Vector2f(50, 50));
        currentSymbol.setPosition(
                Vector2f((i % 10) * 60 + 100, 100 + (i / 10 * 100)));
        window.draw(currentSymbol);
    }
}

void startGame(RenderWindow& window, int difficult)
{
    string symbols[33]
            = {"а", "б", "в", "г", "д", "е", "ё", "ж", "з", "и", "й",
               "к", "л", "м", "н", "о", "п", "р", "с", "т", "у", "ф",
               "х", "ц", "ч", "ш", "щ", "ъ", "ы", "ь", "э", "ю", "я"};
    vector<keyboardSymbol> keyboardSymbols;
    for (int i = 0; i < 33; i++) {
        keyboardSymbol currentSymbol;
        currentSymbol.str = symbols[i];
        currentSymbol.folder = "images/" + to_string(i + 1) + ".png";
        keyboardSymbols.push_back(currentSymbol);
    }

    // bg
    Texture texture;
    if (!texture.loadFromFile("images/bg.jpg")) {
        cout << "Error, images/bg.jpg not found" << endl;
    }
    RectangleShape bg = initBg(window);
    bg.setTexture(&texture);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            if (event.type == Event::MouseButtonPressed) {
                if (event.mouseButton.button == Mouse::Left) {
                }
            }
        }

        window.clear();
        window.draw(bg);
        drawKeyboard(window, keyboardSymbols);
        window.display();
        sleep(milliseconds(1000 / 60));
    }
}
