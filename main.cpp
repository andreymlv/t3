
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

enum
{
    WIDHT = 300,
    HEIGHT = 300,
};

class Game
{
private:
    sf::RenderWindow *window;
    sf::ContextSettings settings;
    sf::Event event;

    void initWindow()
    {
        /*
            Create a window, adjust antialiasing, limit FPS
        */
        settings.antialiasingLevel = 8;
        this->window = new sf::RenderWindow(sf::VideoMode(WIDHT, HEIGHT), "t3");
        this->window->setFramerateLimit(60);
    }

    void pollEvents()
    {
        /*
            Read events
        */
        while (this->window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                this->window->close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                this->window->close();
        }
    }

    void update()
    {
        this->pollEvents();
    }

    sf::CircleShape makeCircle(float x_0, float y_0)
    {
        sf::CircleShape shape;
        shape.setPosition(x_0, y_0);
        shape.setRadius(30);
        shape.setOutlineColor(sf::Color::White);
        shape.setOrigin(30, 30);
        return shape;
    }

    /*
    sf::Shape makeX(float x_0, float y_0)
    {
        sf::Shape *shape;
        
        return shape;
    }
    */

    void render()
    {
        this->window->clear(sf::Color::Black);
        this->window->draw(this->makeCircle(39.0f, 30.0f));
        //this->window->draw(this->makeX(90.0f, 90.f));
        this->window->display();
    }

public:
    void run()
    {
        /*
            Main game loop
        */
        while (this->window->isOpen())
        {
            this->update();
            this->render();
        }
    }

    Game()
    {
        this->initWindow();
    }

    ~Game()
    {
        delete this->window;
    }
};

int main(void)
{
    Game game;
    game.run();

    return 0;
}
