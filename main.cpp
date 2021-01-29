#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Window.hpp>

enum
{
    HEIGHT = 300,
    WIDTH = 300,
    RADIUS = 30
};

class Ball
{
private:
    sf::CircleShape shape;

public:
    sf::CircleShape get()
    {
        return shape;
    }

    Ball(float x_0, float y_0)
    {
        shape.setPosition(x_0, y_0);
        shape.setRadius(RADIUS);
        shape.setFillColor(sf::Color::White);
        shape.setOrigin(RADIUS, RADIUS);
    }

    ~Ball()
    {
    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "t3");
    window.setFramerateLimit(60);
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    Ball o_player(WIDTH / 2.0f, HEIGHT / 2.0f);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                window.close();
        }

        window.clear(sf::Color::Black);
        window.draw(o_player.get());
        window.display();
    }

    return 0;
}
