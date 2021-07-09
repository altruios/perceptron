#include <Cortex.hpp>
#include <vector>

Cortex::Cortex(sf::RenderWindow *window, 
          int input_count, 
          int hidden_layer_count, 
          int hidden_layer_depth, 
          int output_layer_count
     ){
          this->window=window;
          this->offset=100;

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
float Cortex::learn(std::vector<float> given, std::vector<float>expected, float learn_rate){}
void Cortex::backwards_propagate(std::vector<float> expected_results){
     std::vector<float> prediction = this->predict();
     //for loop here?
     float error =0.0f;
     float calculated_error = 0.0f;
     int max_count=1024;
     int count =0;
     while(error>calculated_error && count<max_count){
          calculated_error = learn(prediction,expected_results,0.1f);
          count++;
     }

}
std::vector<float> Cortex::predict(){
     std::vector<float>result;
     for(int i=0;i<this->output_layer.size();i++){
          result.push_back(this->output_layer[i].Activation);
     }
     return result;
}
void Cortex::forward_propagate(std::vector<float> inputs){
     for(int i=0;i<inputs.size();i++){
          this->input_layer[i].Activation=inputs[i];
     }
     for(int y=0;y<this->hidden_layer.size();y++){
          for(int x=0;x<this->hidden_layer[y].size();x++){
               std::vector<float> weights=this->get_weights(y,x);
               std::vector<float> activations=this->get_activtions(y);
               this->hidden_layer[y][x].activate(weights,activations);
          }
     }
}
std::vector<float> Cortex::get_weights(int index, int key){
     std::vector<float> w;
     if(index==0){
          for(int i=0;i<this->input_layer.size();i++){
               w.push_back(this->input_layer[i].get_weight(key));
          }
     }else{
          for(int x=0;x<this->hidden_layer[index].size();x++){
               w.push_back(this->hidden_layer[index][x].get_weight(key));
          }
     }
     return w;
}
std::vector<float> Cortex::get_activtions(int index){
     std::vector<float> a;
     if(index==0){
          for(int i=0;i<this->input_layer.size();i++){
               a.push_back(this->input_layer[i].Activation);
          }
     }else{
          for(int x=0;x<this->hidden_layer[index].size();x++){
               a.push_back(this->hidden_layer[index][x].Activation);
          }
     }
     return a;
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
void Cortex::run(sf::RenderWindow &window, std::vector<std::vector<float>>&training_data){
     this->render(window);



}

