
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
    bool state = false; // false == move makes x

    void initWindow()
    {
        /*
            Create a window, adjust antialiasing, limit FPS
        */
        settings.antialiasingLevel = 8;
        this->window = new sf::RenderWindow(sf::VideoMode(WIDHT, HEIGHT), "t3");
        this->window->setFramerateLimit(60);
        this->game = {6, 6, 6, 6, 6, 6, 6, 6, 6};
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
                        this->changeState(0);
                    }
                    else if (position.y > 100 && position.y < 200)
                    {
                        this->changeState(3);
                    }
                    else
                    {
                        this->changeState(6);
                    }
                }
                else if (position.x > 100 && position.x < 200)
                {
                    // Central side
                    if (position.y < 100)
                    {
                        this->changeState(1);
                    }
                    else if (position.y > 100 && position.y < 200)
                    {
                        this->changeState(4);
                    }
                    else
                    {
                        this->changeState(7);
                    }
                }
                else if (position.x > 200)
                {
                    // Right side
                    if (position.y < 100)
                    {
                        this->changeState(2);
                    }
                    else if (position.y > 100 && position.y < 200)
                    {
                        this->changeState(5);
                    }
                    else
                    {
                        this->changeState(8);
                    }
                }
            }
        }
    }

    void changeState(int numberOfCell)
    {
        if (this->game[numberOfCell] == 0 || this->game[numberOfCell] == 1)
        {
            std::printf("the move was made in cell #");
        }
        else
        {
            if (this->state == false)
            {
                // move makes o
                this->game[numberOfCell] = 0;
                this->state = !this->state;
            }
            else
            {
                // move makes x
                this->game[numberOfCell] = 1;
                this->state = !this->state;
            }
        }

        std::printf("%d - %d\n", numberOfCell, this->game[numberOfCell]);
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
        o.setFillColor(sf::Color::Black);
        o.setOutlineColor(sf::Color::White);
        o.setOutlineThickness(1);
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

    std::array<sf::VertexArray, 2> drawX(int numberOfCell)
    {
        switch (numberOfCell)
        {
        case 0:
            return this->makeX(50, 50);
            break;
        case 1:
            return this->makeX(150, 50);
            break;
        case 2:
            return this->makeX(250, 50);
            break;
        case 3:
            return this->makeX(50, 150);
            break;
        case 4:
            return this->makeX(150, 150);
            break;
        case 5:
            return this->makeX(250, 150);
            break;
        case 6:
            return this->makeX(50, 250);
            break;
        case 7:
            return this->makeX(150, 250);
            break;
        case 8:
            return this->makeX(250, 250);
            break;

        default:
            throw std::runtime_error("wrong cell");
            break;
        }
    }

    sf::CircleShape drawO(int numberOfCell)
    {
        switch (numberOfCell)
        {
        case 0:
            return this->makeO(50, 50);
            break;
        case 1:
            return this->makeO(150, 50);
            break;
        case 2:
            return this->makeO(250, 50);
            break;
        case 3:
            return this->makeO(50, 150);
            break;
        case 4:
            return this->makeO(150, 150);
            break;
        case 5:
            return this->makeO(250, 150);
            break;
        case 6:
            return this->makeO(50, 250);
            break;
        case 7:
            return this->makeO(150, 250);
            break;
        case 8:
            return this->makeO(250, 250);
            break;

        default:
            throw std::runtime_error("wrong cell");
            break;
        }
    }

    void render()
    {
        this->window->clear();

        for (int i = 0; i < (int)this->game.size(); i++)
        {
            if (this->game[i] == 0)
            {
                this->window->draw(this->drawO(i));
            }
            else if (this->game[i] == 1)
            {
                for (int j = 0; j < (int)this->drawX(0).size(); j++)
                {
                    this->window->draw(this->drawX(i)[j]);
                }
            }
        }

        // Drawing '#' grid
        for (int i = 0; i < (int)this->grid.size(); ++i)
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
