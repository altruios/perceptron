#include <Perceptron.hpp>
#include <vector>

Perceptron::Perceptron(float x,float y, float offset){
     this->x=x;
     this->y=y;
     this->offset=offset;
     this->Activation= this->activation_fn((x+y)*(x-y));
     this->bias= this->activation_fn((x*x)-(y*y));
     this->debug_on=true;
     this->update();
     sf::FloatRect shape_bounds = this->shape.getLocalBounds();
     this->shape.setOrigin(shape_bounds.width/2.f, shape_bounds.height/2.f);
}
void Perceptron::update(){
     this->shape.setPosition(sf::Vector2f{this->x*this->offset+offset,this->y*this->offset+offset});
     this->shape.setRadius((20));


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
void Perceptron::set_weight(float weight){
     this->weight=weight;
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

