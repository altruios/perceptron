#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>
#include <optional>
#include <Cortex.hpp>
template <typename... Args>
void print(Args &&...args)
{
     (std::cout << ... << args) << '\n';
}

void render_step(sf::RenderWindow &window){

}
void draw(sf::RenderWindow &window){

}

void player_controls(sf::RenderWindow &window){

}


int main(){
     //WINDOW SETUP:
     sf::RenderWindow window(sf::VideoMode(1920, 1080), "perceptron");
     window.setFramerateLimit(60);
     // Create a graphical text to display

     Cortex c{&window,1,1,1,1};
     while (window.isOpen()){
          sf::Event event;
          while (window.pollEvent(event)){
               if (event.type == sf::Event::Closed){
                    window.close();
               }
          }
          player_controls(window);
          render_step(window);
          draw(window);
          window.display();
     }
     return 0;
}