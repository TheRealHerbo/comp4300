#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <random>
#include "events.hpp"
#include "configuration.hpp"
#include "star.hpp"

/*
 * Read the context from the file and create the objects
 * Window width:int height:int
 * Font font_file:string size:int r:int g:int b:int
 * Rectangle name:string x:float y:float speedx:float speedy:float r:int g:int b:int width:float height:float
 * Circle name:string x:float y:float speedx:float speedy:float r:int g:int b:int radius:float
*/

void read_context() {

}

std::vector<Star> createStars(uint32_t count) {
    std::vector<Star> stars;
    
    stars.reserve(count);

    // Random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dis(0.0f, 1.0f);

    // Create randomly distributed stars
    for (uint32_t i{count}; i--;) {
        float const x = dis(gen) * conf::window_size_f.x;
        float const y = dis(gen) * conf::window_size_f.y;
        float const z = dis(gen) * (conf::far - conf::near) + conf::near;

        stars.push_back({{x, y}, z});
    }

    return stars;
}

int main()
{
    auto window = sf::RenderWindow{{conf::window_size.x, conf::window_size.y}, "Game"};
    window.setFramerateLimit(conf::max_framerate);

    std::vector<Star> stars = createStars(conf::count);

    while (window.isOpen()) {

        processEvents(window);

        window.clear();

        sf::CircleShape shape{conf::radius};
        shape.setOrigin(conf::radius, conf::radius);

        for (auto const& s : stars) {
            float const scale = 1.0f / s.z;
            shape.setPosition(s.position);
            shape.setScale(scale, scale);
            window.draw(shape);
        }

        window.display();
    }
    return 0;

}
