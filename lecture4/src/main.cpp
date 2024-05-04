#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Shape.hpp>
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
    sf::CircleShape circle;
    std::string name;
    float speedx;
    float speedy;

    CCircle() {}
    CCircle(sf::CircleShape circle, std::string sname, float fspeedx, float fspeedy)
        : name(sname), speedx(fspeedx), speedy(fspeedy) {}
};

class CRectangle {
public:
    sf::RectangleShape rectangle;
    std::string name;
    float speedx;
    float speedy;

    CRectangle() {}
    CRectangle(sf::RectangleShape rectangle,std::string sname, float fspeedx, float fspeedy)
        : name(sname), speedx(fspeedx), speedy(fspeedy) {}
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
    std::string file = "context.txt";
    std::string obj_name;
    std::ifstream fin(file);

    while(fin >> obj_name) {
        if (obj_name == "Window") {
            int height;
            int width;
            fin >> width >> height;

            CWindow(height, width);
        }
        else if(obj_name == "Font") {
            std::string font_file;
            int size;
            int r;
            int g;
            int b;
            fin >> font_file >> size >> r >> g >> b;

            sf::Font font;

            if(!font.loadFromFile(font_file)) {
                std::cerr << "Couldn't load the font!" << std::endl;

                exit(-1);
            }
            text.setFont(font);
            text.setCharacterSize(size);
            text.setFillColor(sf::Color(r,g,b));
        }
        else if(obj_name == "Circle") {
            CCircle circle;
            sf::CircleShape circleShape;
            std::string name;
            float x;
            float y;
            float speedx;
            float speedy;
            int r;
            int g;
            int b;
            float radius;

            fin >> name >> x >> y >> speedx >> speedy >> r >> g >> b >> radius;

            circleShape.setPosition(x, y);
            circleShape.setFillColor(sf::Color(r,g,b));
            circleShape.setRadius(radius);

            circle.circle = circleShape;
            circle.speedx = speedx;
            circle.speedy = speedy;
            circle.name = name;

            circles.push_back(circle);
        }
        else if(obj_name == "Rectangle") {
            CRectangle rectangle;
            sf::RectangleShape rectangleShape;
            std::string name;
            float x;
            float y;
            float speedx;
            float speedy;
            int r;
            int g;
            int b;
            float width;
            float height;

            fin >> name >> x >> y >> speedx >> speedy >> r >> g >> b >> width >> height;

            rectangleShape.setPosition(x, y);
            rectangleShape.setFillColor(sf::Color(r,g,b));
            rectangleShape.setSize(sf::Vector2f(width, height));

            rectangle.rectangle = rectangleShape;
            rectangle.speedx = speedx;
            rectangle.speedy = speedy;
            rectangle.name = name;

            rectangles.push_back(rectangle);
        }
    }
}

int main()
{
    sf::RenderWindow renderWindow(sf::VideoMode(200, 200), "SFML works!");
    CWindow window;
    sf::Text text;

    read_context(text, window);

    while (renderWindow.isOpen())
    {
        sf::Event event;
        while (renderWindow.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                renderWindow.close();
        }

        renderWindow.clear();
        for(auto& circle : circles) {
            circle.circle.move(circle.speedx, circle.speedy);
            renderWindow.draw(circle.circle);
        }
        for(auto& rectangle : rectangles) {
            rectangle.rectangle.move(rectangle.speedx, rectangle.speedy);
            renderWindow.draw(rectangle.rectangle);
        }
        renderWindow.display();
    }

    return 0;
}



