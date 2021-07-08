#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <math.h>
#include <cmath>
class Cortex{
     std::vector<Perceptron>*output_layer;
     std::vector<std::vector<Perceptron>*hidden_layer;
     std::vector<Perceptron>*input_layer;
     public:
     sf::RenderWindow *window;
     Cortex(sf::RenderWindow*window, 
          int input_count, 
          int hidden_layer_count, 
          int hidden_layer_depth, 
          int output_layer_count
     );
     std::vector<float> prediect(std::vector<float>&inputs);
     void learn(std::vector<float> given, std::vector<float>expected, float learn_rate);
     void backwards_propagate(std::vector<float>);
     void forward_propagate();
     void train(std::vector<std::vector<float[2]>>& training_data);
};
