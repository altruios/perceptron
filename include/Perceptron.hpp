#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include <cmath>
class Perceptron{
     public:
     sf::CircleShape shape;
     float Activation;
     float bias;
     float weight;
     float x;
     float y;
     Perceptron(float x, float y,float offset);
     void update(sf::RenderWindow &window);
     void render(sf::RenderWindow &window);
     void activate(std::vector<float>&weights,std::vector<float>&activations);
     void set_weight(float weight);
     void set_bias(float bias);
     float activation_fn(float value);
};