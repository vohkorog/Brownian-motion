#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main() {
    const int n = 50;
    std::vector<float> x(n);
    std::vector<float> y(n);

    // Инициализация генератора случайных чисел
    std::srand(static_cast<unsigned int>(std::time(0)));

    // Заполнение массивов случайными значениями
    for (int i = 0; i < n; ++i) {
        x[i] = 400.0f * static_cast<float>(rand()) / RAND_MAX - 200.0f;
        y[i] = 300.0f * static_cast<float>(rand()) / RAND_MAX - 150.0f;
    }

    // Создание окна
    sf::RenderWindow window(sf::VideoMode(640, 480), "Random Circles");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        for (int i = 0; i < n; ++i) {
            float dx = 10.0f * static_cast<float>(rand()) / RAND_MAX - 5.0f;
            float dy = 10.0f * static_cast<float>(rand()) / RAND_MAX - 5.0f;
            x[i] += dx;
            y[i] += dy;

            // Рисуем круг
            sf::CircleShape circle(1);
            circle.setPosition(x[i] + 320, 240 - y[i]); // Центрируем по окну
            window.draw(circle);
        }

        window.display();

        // Задержка
        sf::sleep(sf::milliseconds(10));
        
        // Удаляем круги на следующем кадре
        // Можно оставить без действия, так как окно очищается каждый цикл
    }

    return 0;
}