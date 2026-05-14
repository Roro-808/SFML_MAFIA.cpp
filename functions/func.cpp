#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>

using namespace sf;

std::fstream logFile("log.txt");

static sf::SoundBuffer soundBuffer;
static sf::Sound sound;

void PlaySound(const std::string& FileName, int volume = 100) {
    if (!soundBuffer.loadFromFile(FileName)) {
        logFile<<"ОШИБКА! Не найден файл: "<<FileName<< std::endl;
        return;
    }
    sound.setBuffer(soundBuffer);
    sound.setVolume(volume);
    sound.play();
}

static sf::Music currentMusic;

void PlayMusic(const std::string& FileName, bool loop = true) {
    if (currentMusic.getStatus() == sf::Music::Playing) {
        currentMusic.stop();
    }
    if (!currentMusic.openFromFile(FileName)) {
        logFile<< "ОШИБКА! Не найден файл: " << FileName << std::endl;
        return;
    }
    currentMusic.setLoop(loop);
    currentMusic.play();
}


struct Button {
    RectangleShape shape;
    Text text;
    bool isHovered;

    Button() : isHovered(false) {}
    
    void init(float x, float y, float width, float height, 
              const std::string& text_label, Font& font) {
        shape.setSize(Vector2f(width, height));
        shape.setPosition(x, y);
        shape.setFillColor(Color(100, 100, 200));
        shape.setOutlineThickness(2);
        shape.setOutlineColor(Color::White);
        
        text.setFont(font);
        text.setString(text_label);
        text.setCharacterSize(24);
        text.setFillColor(Color::White);
        
        FloatRect textBounds = text.getLocalBounds();
        text.setOrigin(textBounds.left + textBounds.width / 2, textBounds.top + textBounds.height / 2);
        text.setPosition(x + width / 2, y + height / 2);
        
        isHovered = false;
    }
    
    void update(RenderWindow& window) {
        Vector2i mousePos = Mouse::getPosition(window);
        isHovered = shape.getGlobalBounds().contains(mousePos.x, mousePos.y);
        
        if (isHovered) {
            shape.setFillColor(Color(150, 150, 255));
        } else {
            shape.setFillColor(Color(100, 100, 200));
        }
    }
    
    bool isPressed() const {
        return isHovered && Mouse::isButtonPressed(Mouse::Left);
    }
    
    void draw(RenderWindow& window) {
        window.draw(shape);
        window.draw(text);
    }
};