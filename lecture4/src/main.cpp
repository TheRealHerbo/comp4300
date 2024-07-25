#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <istream>
#include <vector>

class CWindow {
public:
    int height = 200;
    int width = 200;

    CWindow() {}
    CWindow(int iheight, int iwidth)
        : height(iheight), width(iwidth) {}
};

class CCircle {
public:
    sf::CircleShape *circle;
    std::string name;
    float speedx;
    float speedy;

    CCircle() {}
    CCircle(sf::CircleShape *circle, std::string sname, float fspeedx, float fspeedy)
        : name(sname), speedx(fspeedx), speedy(fspeedy) {}

    void moveCircle() {
        circle->move(speedx, speedy);
    }
};

class CRectangle {
public:
    sf::RectangleShape *rectangle;
    std::string name;
    float speedx;
    float speedy;

    CRectangle() {}
    CRectangle(sf::RectangleShape *rectangle,std::string sname, float fspeedx, float fspeedy)
        : name(sname), speedx(fspeedx), speedy(fspeedy) {}

    void moveRectangle() {
        rectangle->move(speedx, speedy);
    }
};

std::vector<CCircle> circles;
std::vector<CRectangle> rectangles;

/*
 * Read the context from the file and create the objects
 * Window width:int height:int
 * Font font_file:string size:int r:int g:int b:int
 * Rectangle name:string x:float y:float speedx:float speedy:float r:int g:int b:int width:float height:float
 * Circle name:string x:float y:float speedx:float speedy:float r:int g:int b:int radius:float
*/

void read_context(sf::Text& text, CWindow& window) {

}

int main()
{
    sf::RenderWindow renderWindow(sf::VideoMode(800, 800), "SFML works!");

    CWindow window = CWindow(200, 200);

    sf::Text text = sf::Text();
    sf::Font font = sf::Font();
    std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;
    if (!font.loadFromFile("tech.ttf")) {
        std::cerr << "Couldn't load the font!" << std::endl;
        return -1;
    }

    text.setFont(font);
    text.setCharacterSize(12);
    text.setFillColor(sf::Color(250,155,55));

    // read_context(text, window);

    sf::CircleShape circle = sf::CircleShape(100);

    circle.setPosition(100, 100);
    circle.setFillColor(sf::Color(255, 0, 0));

    CCircle circle1 = CCircle(&circle, "circle1", 1, 1);

    sf::RectangleShape rectangle = sf::RectangleShape(sf::Vector2f(50, 50));

    rectangle.setPosition(200, 200);
    rectangle.setFillColor(sf::Color(0, 255, 0));

    CRectangle rectangle1 = CRectangle(&rectangle, "rectangle1", 1, 1);

    circles.push_back(circle1);
    rectangles.push_back(rectangle1);

    while (renderWindow.isOpen())
    {
        sf::Event event;
        while (renderWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                renderWindow.close();
        }

        renderWindow.clear();

        renderWindow.draw(*circle1.circle);
        renderWindow.draw(*rectangle1.rectangle);

        renderWindow.display();
    }

    return 0;
}
