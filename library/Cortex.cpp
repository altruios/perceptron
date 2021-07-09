#include <Cortex.hpp>
#include <vector>
#include <iostream>

Cortex::Cortex(sf::RenderWindow *window, 
          int input_count, 
          int hidden_layer_count, 
          int hidden_layer_depth, 
          int output_layer_count,
          sf::Font &font
     ){
          this->window=window;
          this->offset=200;
          this->font=&font;
          int _y=0;
          this->hidden_layer.resize(hidden_layer_depth);
          for(int x=0;x<input_count;x++){
                    Perceptron p{float(x),float(_y),this->offset,*this->font}; 
                    p.make_weights(hidden_layer_count);
                    this->input_layer.push_back(p);

          }
          _y++;
          for(int y=0;y<hidden_layer_depth;y++){
               for(int x=0;x<hidden_layer_count;x++){
                    Perceptron p{float(x),float(_y),this->offset,*this->font}; 
                    p.make_weights(y==hidden_layer_depth?output_layer_count:hidden_layer_count);
                    this->hidden_layer[y].push_back(p);
               }
               _y++;
          }
          for(int x=0;x<output_layer_count;x++){
                    Perceptron p{float(x),float(_y),this->offset,*this->font}; 
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
          std::cout<<"forward propagating"<<std::endl;

     for(int i=0;i<inputs.size();i++){
          std::cout<<inputs[i]<<std::endl;
          
          this->input_layer[i].Activation=inputs[i];
     }
     for(int y=0;y<this->hidden_layer.size();y++){
          for(int x=0;x<this->hidden_layer[y].size();x++){
                    std::vector<float> weights=this->get_weights(y,x);
                    std::vector<float> activations=this->get_activtions(y);
                    this->hidden_layer[y][x].activate(weights,activations);
          }
     }
     std::cout<<"forward_propagating finished"<<std::endl;
}
std::vector<float> Cortex::get_weights(int index, int key){
     std::vector<float> w;
     int last_row_index = index-1;
     if(index==0){
          for(int i=0;i<this->input_layer.size();i++){
               w.push_back(this->input_layer[i].get_weight(key));
          }
     }else{
          for(int x=0;x<this->hidden_layer[last_row_index].size();x++){
               Perceptron *p = &this->hidden_layer[last_row_index][x];
               w.push_back(p->get_weight(key));
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
          for(int x=0;x<this->hidden_layer[index-1].size();x++){
               a.push_back(this->hidden_layer[index-1][x].Activation);
          }
     }
     return a;
}

void Cortex::train(std::vector<std::vector<std::vector<float>>>& training_data, int epoc)
     {
     std::cout<<"training"<<std::endl;
     for(int j=0;j<epoc;j++){
          for(int i =0;i<training_data.size();i++){
               std::cout<<"traning "<< i <<std::endl;
               this->forward_propagate(training_data[i][0]);
//               this->backwards_propagate(training_data[i][1]);
               this->render();

          }
     }
}
void Cortex::render(){
     for(Perceptron p:this->input_layer){
          p.update();
          p.render(*this->window);
     }     
     for(std::vector<Perceptron>layer:this->hidden_layer){
          for(Perceptron p:layer){
          p.update();
          p.render(*this->window);
          }
     }
     for(Perceptron p:this->output_layer){
          p.update();
          p.render(*this->window);
     }
          this->window->display();

     
}
void Cortex::run(std::vector<std::vector<std::vector<float>>> &training_data){
    sf::Event event;
     while (this->window->pollEvent(event)){
          if (event.type == sf::Event::Closed){
               this->window->close();
          }
     }
     this->train(training_data,100);
    // this->render(window);



}

