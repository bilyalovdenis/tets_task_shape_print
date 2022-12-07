#include "Toolbar.h"

using namespace ts;

Toolbar::Toolbar(WorkSpace* curr_workspace){
    _curr_workspace = curr_workspace;
    intialization_buttons();
}
Toolbar::~Toolbar(){
    close_space();
}
void Toolbar::close_space(){
    for (auto it : buttons){
        it->close_space();
        delete it;
    }
}
void Toolbar::click_handler(sf::Vector2i &position){
    std::string s;
    for (auto it : buttons){
        if(it->sprite->getGlobalBounds().contains(position.x, position.y)) it->click_handler();
    }
    
}
void Toolbar::intialization_buttons(){
    ToolButton *triangle = new ToolButton("Triangle",_curr_workspace); 
    triangle->set_position(0,0);
    std::basic_string<char> path{"../../images/triangle.png"}; 
    triangle->set_texture(path);
    ToolButton *quadrilateral= new ToolButton("Quadrilateral",_curr_workspace);
    quadrilateral->set_position(64,0); 
    std::basic_string<char> path2{"../../images/quadrilateral.png"}; 
    quadrilateral->set_texture(path2);
    ToolButton *circle = new ToolButton("Circle",_curr_workspace); 
    circle->set_position(128,0);
    std::basic_string<char> path3{"../../images/circle.png"}; 
    circle->set_texture(path3);
    buttons.push_back(triangle);
    buttons.push_back(quadrilateral);
    buttons.push_back(circle);
}
void Toolbar::draw( sf::RenderWindow *_window){
    for (auto it : buttons){
        _window->draw(*(it->get_sprite()));
    }
}