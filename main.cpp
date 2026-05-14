// Собирает все файлы вместе

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "functions/Scenes.cpp"

using namespace sf;

int main() {

    std::ofstream("log.txt", std::ios::trunc).close(); // Очистка лога от предыдущих записей

    RenderWindow window(VideoMode::getDesktopMode(), "MAFIA", Style::Fullscreen);

    MainScreen mainScreen;
    mainScreen.init();
    
    enum stste {MENU, ServerChoose};
    stste Curr_state = MENU;

    while (window.isOpen()) {
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

        if (Curr_state == MENU) {
            mainScreen.update(window);
            int action = mainScreen.handleEvents(window);
            if (action == 1) {
                Curr_state = ServerChoose;
                
            }
            window.clear(Color::Black);
            mainScreen.draw(window);
        }
        else if (Curr_state == ServerChoose) {
            
        }
        
        window.display();
    }
    
    logFile << "Программа завершена" << std::endl;
    return 0;
}