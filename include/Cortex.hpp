#pragma once
#include <SFML/Graphics.hpp>
#include <Perceptron.hpp>
#include <vector>
#include <math.h>
#include <cmath>
class Cortex{
     public:
     float offset;
     std::vector<Perceptron> output_layer;
     std::vector<std::vector<Perceptron>> hidden_layer;
     std::vector<Perceptron> input_layer;
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
     void forward_propagate(std::vector<float> inputs);
     void train(std::vector<std::vector<std::vector<float>>>& training_data, int epoc);
     void render(sf::RenderWindow &window);
     std::vector<float> get_weights(int index);
     std::vector<float> get_activtions(int index);
};
