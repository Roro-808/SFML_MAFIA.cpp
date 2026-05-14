#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <string>

using namespace sf;

std::fstream logFile("log.txt");

static SoundBuffer soundBuffer;
static Sound sound;

void PlaySound(const std::string& FileName, int volume = 100) {
    if (!soundBuffer.loadFromFile(FileName)) {
        logFile<<"ОШИБКА! Не найден файл: "<<FileName<< std::endl;
        return;
    }
    sound.setBuffer(soundBuffer);
    sound.setVolume(volume);
    sound.play();
}

Music currentMusic;

void PlayMusic(const std::string& FileName, bool loop = true) {
    if (currentMusic.getStatus() == Music::Playing) {
        currentMusic.stop();
    }
    if (!currentMusic.openFromFile(FileName)) {
        logFile<< "ОШИБКА! Не найден файл: " << FileName << std::endl;
        return;
    }
    currentMusic.setLoop(loop);
    currentMusic.play();
}

void StopMusic() {currentMusic.stop();}

struct Button {
    RectangleShape shape;
    Text text;
    bool isHovered;
 
    Button() : isHovered(false) {}
    
    void init(float x, float y, float width, float height, const std::string& text_label, Font& font, int charSize = 24, Color FillColor = Color(0, 100, 200), Color OutlineColor = Color::White, Color TextColor = Color::White) {

        shape.setSize(Vector2f(width, height));
        shape.setPosition(x, y);
        shape.setFillColor(FillColor);
        shape.setOutlineThickness(2);
        shape.setOutlineColor(OutlineColor);
        
        text.setFont(font);
        text.setString(text_label);
        text.setCharacterSize(charSize);
        text.setFillColor(TextColor);
        
        FloatRect textBounds = text.getLocalBounds();
        text.setOrigin(textBounds.left + textBounds.width / 2, textBounds.top + textBounds.height / 2);
        text.setPosition(x + width / 2, y + height / 2);
        isHovered = false;
    }
    
    void update(RenderWindow& window, Color FillColor = Color(200, 100, 200), Color HowerColor = Color(255, 150, 255)) {
        Vector2i mousePos = Mouse::getPosition(window);
        isHovered = shape.getGlobalBounds().contains(mousePos.x, mousePos.y);
        
        if (isHovered) {
            shape.setFillColor(HowerColor);
        } else {
            shape.setFillColor(FillColor);
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

int getScreenWidth() {
    return sf::VideoMode::getDesktopMode().width;
}

int getScreenHeight() {
    return sf::VideoMode::getDesktopMode().height;
}