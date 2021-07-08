#include <Perceptron.hpp>
#include <vector>

Perceptron::Perceptron(float x,float y, float offset){
     this->x=x;
     this->y=y;
     this->Activation= this->activation_fn((x+y)*(x-y));
     this->bias= this->activation_fn((x*x)+(y*y));
     this->shape.setPosition(sf::Vector2f{x*offset,y*offset});
     this->shape.setRadius(this->bias*offset);
     this->shape.setOutlineColor(sf::Color(sf::Uint32(this->Activation*offset)));
     this->shape.setOutlineThickness(this->Activation*offset);
}
void Perceptron::update(sf::RenderWindow &window){}
void Perceptron::render(sf::RenderWindow &window){
     window.draw(this->shape);
}
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
     return float(value) / (1 + abs(value));
}
