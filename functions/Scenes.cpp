#include "func.cpp"

struct MainScreen {
    Font font;
    Text title;
    Button playButton;
    Button exitButton;
    
    void init() {
        if (!font.loadFromFile("assets/fonts/jesaya free.ttf")) {
            logFile<<"Ошибка загрузки шрифта!";
        }

        PlayMusic("assets/music/01.Title Screen.ogg");

        title.setFont(font);
        title.setString("MAFIA GAME");
        title.setCharacterSize(72);
        title.setFillColor(Color::White);
        title.setPosition(getScreenWidth()/2 - 35*5, 100);
        
        playButton.init(getScreenWidth()/2 - 200, 300, 400, 100, "PLAY", font, 35, Color::Green);
        exitButton.init(getScreenWidth()/2 - 200, 500, 400, 100, "EXIT", font, 35);
        
        logFile<<"Главный экран создан";
    }
    
    // 0 Возвращается при событиях, когда всё действие происходит в данном файле, другая цифра, если что-то продолжается в файле main.cpp
    int handleEvents(RenderWindow& window) {

        if (playButton.isPressed()) {
            logFile<<"Нажата кнопка ИГРАТЬ";
            StopMusic();
            return 1;
        }
        
        if (exitButton.isPressed()) {
            logFile<<"Нажата кнопка ВЫХОД";
            window.close();
            return 0;
        }
        return 0;
    }
    
    void update(RenderWindow& window) {
        playButton.update(window, Color::Green, Color(100, 255, 100));
        exitButton.update(window);
    }
    
    void draw(RenderWindow& window) {
        window.draw(title);
        playButton.draw(window);
        exitButton.draw(window);
    }
};