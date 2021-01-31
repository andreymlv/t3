
#include <array>
#include <cstdio>

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
    std::array<sf::VertexArray, 4> grid;
    std::array<int, 9> game;

    void initWindow()
    {
        /*
            Create a window, adjust antialiasing, limit FPS
        */
        settings.antialiasingLevel = 8;
        this->window = new sf::RenderWindow(sf::VideoMode(WIDHT, HEIGHT), "t3");
        this->window->setFramerateLimit(60);
        this->grid = this->makeGrid();
    }

    void pollEvents()
    {
        /*
            Read events
        */
        sf::Vector2i position = sf::Mouse::getPosition(*(this->window));

        while (this->window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                this->window->close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                this->window->close();

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                if (position.x < 100)
                {
                    // Left side
                    if (position.y < 100)
                    {
                        if ((this->game[0] != 0 || this->game[0] != 1))
                        {
                            /* code */
                        }

                        // 0
                        std::printf("0\n");
                    }
                    else if (position.y > 100 && position.y < 200)
                    {
                        if (this->game[3] != 0 || this->game[3] != 1)
                        {
                            /* code */
                        }

                        // 3
                        std::printf("3\n");
                    }
                    else
                    {
                        if (this->game[6] != 0 || this->game[6] != 1)
                        {
                            /* code */
                        }
                        // 6
                        std::printf("6\n");
                    }
                }
                else if (position.x > 100 && position.x < 200)
                {
                    // Central side
                    if (position.y < 100)
                    {
                        if (this->game[1] != 0 || this->game[1] != 1)
                        {
                            /* code */
                        }

                        // 1
                        std::printf("1\n");
                    }
                    else if (position.y > 100 && position.y < 200)
                    {
                        if (this->game[4] != 0 || this->game[4] != 1)
                        {
                            /* code */
                        }

                        // 4
                        std::printf("4\n");
                    }
                    else
                    {
                        if (this->game[7] != 0 || this->game[7] != 1)
                        {
                            /* code */
                        }
                        // 7
                        std::printf("7\n");
                    }
                }
                else if (position.x > 200)
                {
                    // Right side
                    if (position.y < 100)
                    {
                        if (this->game[2] != 0 || this->game[2] != 1)
                        {
                            /* code */
                        }

                        // 2
                        std::printf("2\n");
                    }
                    else if (position.y > 100 && position.y < 200)
                    {
                        if (this->game[5] != 0 || this->game[5] != 1)
                        {
                            /* code */
                        }

                        // 5
                        std::printf("5\n");
                    }
                    else
                    {
                        if (this->game[8] != 0 || this->game[8] != 1)
                        {
                            /* code */
                        }
                        // 8
                        std::printf("8\n");
                    }
                }
            }
        }
    }

    void update()
    {
        this->pollEvents();
    }

    sf::CircleShape makeO(float x_0, float y_0)
    {
        sf::CircleShape o;

        o.setPosition(x_0, y_0);
        o.setRadius(30);
        o.setOutlineColor(sf::Color::White);
        o.setOrigin(30, 30);

        return o;
    }

    std::array<sf::VertexArray, 2> makeX(float x_0, float y_0)
    {

        sf::VertexArray first(sf::LineStrip, 2);
        first[0].position = sf::Vector2f(x_0 - 25, y_0 - 25);
        first[1].position = sf::Vector2f(x_0 + 25, y_0 + 25);

        sf::VertexArray second(sf::LineStrip, 2);
        second[0].position = sf::Vector2f(x_0 + 25, y_0 - 25);
        second[1].position = sf::Vector2f(x_0 - 25, y_0 + 25);

        std::array<sf::VertexArray, 2> x = {first, second};

        return x;
    }

    std::array<sf::VertexArray, 4> makeGrid()
    {
        sf::VertexArray first(sf::LineStrip, 2);
        first[0].position = sf::Vector2f(0, 100);
        first[1].position = sf::Vector2f(300, 100);

        sf::VertexArray second(sf::LineStrip, 2);
        second[0].position = sf::Vector2f(0, 200);
        second[1].position = sf::Vector2f(300, 200);

        sf::VertexArray third(sf::LineStrip, 2);
        third[0].position = sf::Vector2f(100, 0);
        third[1].position = sf::Vector2f(100, 300);

        sf::VertexArray fourth(sf::LineStrip, 2);
        fourth[0].position = sf::Vector2f(200, 0);
        fourth[1].position = sf::Vector2f(200, 300);

        std::array<sf::VertexArray, 4> grid = {first, second, third, fourth};

        return grid;
    }

    void render()
    {
        this->window->clear();

        // Example of drawing 'O'
        this->window->draw(this->makeO(50.0f, 50.0f));

        // Example of drawing 'X'
        for (int i = 0; i < (int) this->makeX(150.0f, 150.0f).size(); i++)
        {
            this->window->draw(this->makeX(150.0f, 150.0f)[i]);
        }

        // Drawing '#' grid
        for (int i = 0; i < (int) this->grid.size(); ++i)
        {
            this->window->draw(this->grid[i]);
        }

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
