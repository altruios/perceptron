#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <math.h>
#include <optional>
#include <Cortex.hpp>
/*
learning how to learn
brain->cortexes->audio
               ->video
               ->motor
               ->ego
               ->id

     the ego is capable of retraining the other cortexes besides id
     the id is capable of retraining the ego
     the ego is a cortex with inputs being the other cortexes - it feeds back temporally
     the id is a core goal - or the defined model?

*/
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

     Cortex c{&window,3,5,4,2};
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