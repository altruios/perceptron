#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include <cmath>
class Perceptron{
     public:
     sf::CircleShape shape;
     sf::CircleShape debug_box;
     float Activation;
     float bias;
     std::vector<float> weights;
     float x;
     int offset;
     float y;
     bool debug_on;

     Perceptron(float x, float y,float offset);
     void update();
     void render(sf::RenderWindow &window);
     void activate(std::vector<float>&weights,std::vector<float>&activations);
     void set_weights(float weight,int index);
     void set_bias(float bias);
     float activation_fn(float value);
     void debug(sf::RenderWindow &window);
     float get_weight(int key);

};