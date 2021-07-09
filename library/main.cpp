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


int main(){
     //WINDOW SETUP:
     sf::RenderWindow window(sf::VideoMode(1920, 1080), "perceptron");
     // Create a graphical text to display
     sf::Font font;
     if(!font.loadFromFile("arial.ttf")){
          std::cout<<"what?0"<<std::endl;
     }
     std::vector<std::vector<std::vector<float>>> training_data {
          {{0,1,2},{1,0}},
          {{3,1,2},{0,1}},
          {{1,2,3},{1,0}},
          {{11,-11,2},{0,1}},
          {{3,1,2},{0,1}},
          {{1,2,3},{1,0}},
          {{3,3,1},{0,1}},
          {{3,3,3},{0,1}},
          {{0,3,0},{0,1}},
          {{3,2,1},{1,0}}
          };
     Cortex c{&window,3,5,4,2,font};

     c.run(training_data);

     
     return 0;
}