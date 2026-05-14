// Серверная часть, принимает команды и отдает команды
#include <iostream>
#include <string>
#include <SFML/Network.hpp>

using namespace sf;

int players[15];

// Вводимые данные (от клиента) - имя пользователя и имя другого пользователя (на кого направлено действие)
// Выходные данные (от сервера) - Оставшиеся живые/смена суток/запросы клиента

void CreateServer(int port) {
    Packet packet;
    packet<<
}

