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
void draw(sf::RenderWindow &window,Cortex &c){
     c.render(window);
}

void player_controls(sf::RenderWindow &window){

}


int main(){
     //WINDOW SETUP:
     sf::RenderWindow window(sf::VideoMode(1920, 1080), "perceptron");
     // Create a graphical text to display

     Cortex c{&window,4,4,4,4};
     while (window.isOpen()){
          sf::Event event;
          while (window.pollEvent(event)){
               if (event.type == sf::Event::Closed){
                    window.close();
               }
          }
          player_controls(window);
          render_step(window);
          draw(window,c);
          window.display();
     }
     return 0;
}