#include <Perceptron.hpp>
#include <vector>
#include <iostream>


Perceptron::Perceptron(float x,float y, float offset, sf::Font &font){

     this->x=x;
     this->y=y;
     this->offset=offset;
     this->Activation= this->activation_fn((x+y)*(x-y));
     this->bias= this->activation_fn((x*x)-(y*y));
     this->debug_on=true;
     this->update();
     this->text.setFont(font);
     this->text.setCharacterSize(20);
     this->text.setFillColor(sf::Color::Red);
     sf::FloatRect shape_bounds = this->shape.getLocalBounds();
     this->shape.setOrigin(shape_bounds.width/2.f, shape_bounds.height/2.f);
}

void Perceptron::update(){
     this->shape.setPosition(sf::Vector2f{this->x*this->offset+offset,this->y*this->offset+offset});
     this->shape.setRadius(this->Activation*40);
     this->shape.setOutlineThickness(this->bias*5);
     this->shape.setOutlineColor(this->Activation>0?sf::Color::Red:sf::Color::Blue);
     sf::FloatRect shape_bounds = this->shape.getLocalBounds();
     this->shape.setOrigin(shape_bounds.width/2.f, shape_bounds.height/2.f);

}
void Perceptron::render(sf::RenderWindow &window){
     window.draw(this->shape);
     if(this->debug_on){
          this->debug(window);
     }
}
void Perceptron::activate(std::vector<float>&weights, std::vector<float>&activations){
     float act=0;
     for(int i=0;i<weights.size();i++){
          act+= weights[i]*activations[i];
     }
     act+=bias;
     this->Activation=this->activation_fn(act);
}
float Perceptron::get_weight(int key){
     return this->weights[key];
}
void Perceptron::make_weights(int count){
     for(int i=0;i<count;i++){
          this->weights.push_back(sin(i));
     }
}
void Perceptron::set_weights(float weight,int index){
     this->weights[index]=weight;
}
void Perceptron::set_bias(float bias){
     this->bias=bias;
}
float Perceptron::activation_fn(float value){
     return float(value) / (1 + abs(value));
}
void Perceptron::debug(sf::RenderWindow &window){
     window.draw(this->debug_box);     
}