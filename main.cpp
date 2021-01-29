
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Ball
{
private:
    sf::CircleShape shape;
    float radius = 30.0f;
    float ball_velocity = 3.0f;
    sf::Vector2f velocity{-ball_velocity, ball_velocity};

public:
    sf::CircleShape get()
    {
        return shape;
    }

    float get_x()
    {
        return shape.getPosition().x;
    }

    float get_y()
    {
        return shape.getPosition().y;
    }

    float left()
    {
        return get_x() - radius;
    }

    float right()
    {
        return get_x() + radius;
    }

    float top()
    {
        return get_y() - radius;
    }

    float bottom()
    {
        return get_y() + radius;
    }

    void update()
    {
        shape.move(velocity);

        if (left() < 0)
        {
            velocity.x = ball_velocity;
        }
        else if (right() > 300.0f)
        {
            velocity.x = -ball_velocity;
        }

        if (top() < 0)
        {
            velocity.y = ball_velocity;
        }
        else if (bottom() > 300.0f)
        {
            velocity.y = -ball_velocity;
        }
        
    }

    Ball(float x_0, float y_0)
    {
        shape.setPosition(x_0, y_0);
        shape.setRadius(radius);
        shape.setFillColor(sf::Color::White);
        shape.setOrigin(radius, radius);
    }
};

class Window
{
private:
    float width = 300.0f;
    float height = 300.0f;
    std::string title = "t3";
    sf::RenderWindow window{sf::VideoMode(width, height), title};
    Ball o_player{width / 2.0f, height / 2.0f};

public:

    float get_w()
    {
        return width;
    }

    float get_h()
    {
        return height;
    }

    void make_grid()
    {
    }

    void run()
    {
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
            o_player.update();
            window.draw(o_player.get());
            window.display();
        }
    }

    Window()
    {
        sf::ContextSettings settings;
        settings.antialiasingLevel = 8;

        window.setFramerateLimit(60);
    }
};

int main()
{
    Window win;
    win.run();
    return 0;
}
