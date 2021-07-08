#include <Cortex.hpp>
#include <vector>

Cortex::Cortex(sf::RenderWindow *window, 
          int input_count, 
          int hidden_layer_count, 
          int hidden_layer_depth, 
          int output_layer_count
     ){
          this->window=window;
          this->offset=20;
          this->hidden_layer.resize(hidden_layer_depth);
          for(int i=0+hidden_layer_depth;i<input_count;i++){
                    Perceptron p{float(i),float(0),this->offset}; 
                    this->output_layer.push_back(p);
          }
          

          for(int y=0;y<hidden_layer_depth;y++){
               for(int x=0;x<hidden_layer_count;x++){
                    Perceptron p{float(x),float(y+1),this->offset}; 
                    this->hidden_layer[y].push_back(p);
               }
          }
          for(int i=0+hidden_layer_depth;i<output_layer_count+hidden_layer_depth;i++){
                    Perceptron p{float(i),float(hidden_layer_depth+1),this->offset}; 
                    this->output_layer.push_back(p);

          }
     }
void Cortex::learn(std::vector<float> given, std::vector<float>expected, float learn_rate){}
void Cortex::backwards_propagate(std::vector<float>){}
void Cortex::forward_propagate(){}
void Cortex::train(std::vector<std::vector<float[2]>>& training_data){}
void Cortex::render(sf::RenderWindow &window){
     for(Perceptron p:this->input_layer){
          p.render(window);
     }     
     for(std::vector<Perceptron>layer:this->hidden_layer){
          for(Perceptron p:layer){
          p.render(window);
          }
     }
     for(Perceptron p:this->output_layer){
          p.render(window);
     }
}
