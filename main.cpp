// Собирает все файлы вместе

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "functions/func.cpp"

using namespace sf;

int main() {

    std::ofstream("log.txt", std::ios::trunc).close(); // Очистка лога от предыдущих записей

    RenderWindow window(VideoMode::getDesktopMode(), "MAFIA", Style::Fullscreen);

    Vector2u scrBorders = window.getSize();
    int scrBorder[2] = {(int)scrBorders.x, (int)scrBorders.y};
    Text MainText;
    MainText.Bold;
    MainText.setPosition(Vector2f(scrBorder[0]/2,scrBorder[1]/2));
    
    PlayMusic("assets/music/01.Title Screen.mp3");

    while (window.isOpen()) {
        bool fullscreen = true;
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed) {
                logFile<<"Нажата клавиша: "<<event.key.code<<std::endl;
                
                if (event.key.code == Keyboard::Escape)
                    window.close();
                if (event.key.code == Keyboard::Tab)
                    RenderWindow window(VideoMode::getDesktopMode(), "MAFIA", Style::Default);

            }
            if (event.type == Event::MouseButtonPressed) {
                logFile<<"Нажата кнопка мыши:"<<event.mouseButton.button<<std::endl;
            }
        }
        window.display();
    }
    
    logFile << "Программа завершена" << std::endl;
    return 0;
}