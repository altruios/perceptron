#include <Perceptron.hpp>
#include <vector>

Perceptron::Perceptron(float x,float y){
     this->x=x;
     this->y=y;
     this->Activation= this->activation_fn((x+y)*(x-y));
     this->bias= this->activation_fn((x*x)+(y*y));
}
void Perceptron::update(sf::RenderWindow &window){}
void Perceptron::render(sf::RenderWindow &window){}
void Perceptron::activate(std::vector<float>&weights, std::vector<float>&activations){
     float act=0;
     for(int i=0;i<weights.size();i++){
          act+= weights[i]*activations[i];
     }
     act+=bias;
     this->Activation=this->activation_fn(act);
}
void Perceptron::set_weight(float weight){
     this->weight=weight;
}
void Perceptron::set_bias(float bias){
     this->bias=bias;
}
float Perceptron::activation_fn(float value){
     float a = pow(exp(1.0),value);
     float b = pow(exp(1.0),-value);
     float v = a-b;
     float k = a+b;
     return (v)/(k);
}
