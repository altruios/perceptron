#include <Cortex.hpp>
#include <vector>

Cortex::Cortex(sf::RenderWindow *window, 
          int input_count, 
          int hidden_layer_count, 
          int hidden_layer_depth, 
          int output_layer_count
     ){
          this->window=window;
          this->offset=50;
          int _y=0;
          this->hidden_layer.resize(hidden_layer_depth);
          for(int x=0;x<input_count;x++){
                    Perceptron p{float(x),float(_y),this->offset}; 
                    this->output_layer.push_back(p);
          }
          _y++;
          for(int y=0;y<hidden_layer_depth;y++){
               for(int x=0;x<hidden_layer_count;x++){
                    Perceptron p{float(x),float(_y),this->offset}; 
                    this->hidden_layer[y].push_back(p);
               }
               _y++;
          }
          for(int x=0;x<output_layer_count;x++){
                    Perceptron p{float(x),float(_y),this->offset}; 
                    this->output_layer.push_back(p);
          }
     }
void Cortex::learn(std::vector<float> given, std::vector<float>expected, float learn_rate){}
void Cortex::backwards_propagate(std::vector<float>){}
void Cortex::forward_propagate(std::vector<float> inputs){
     for(int i=0;i<inputs.size();i++){
          this->input_layer[i].Activation=inputs[i];
     }
     for(int y=0;y<this->hidden_layer.size();y++){
          for(int x=0;x<this->hidden_layer[y].size();x++){
               std::vector<float> weights=this->get_weights(y);
               std::vector<float> activations=this->get_activtions(y);
               this->hidden_layer[y][x].activate(weights,activations);
          }
     }
}
std::vector<float> Cortex::get_weights(int index){
     std::vector<float> t;
     return t;
}
std::vector<float> Cortex::get_activtions(int index){
     std::vector<float> t;
     return t;
}

void Cortex::train(std::vector<std::vector<std::vector<float>>>& training_data, int epoc)
     {
     for(int j=0;j<epoc;j++){
          for(int i =0;i<training_data.size();i++){
               this->forward_propagate(training_data[i][0]);
               this->backwards_propagate(training_data[i][1]);
          }
     }
}
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

