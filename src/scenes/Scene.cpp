#include "Scene.hpp"
#include <iostream>

Scene::Scene(/* args */)
{

}

Scene::~Scene()
{
    //this->boxes_.clear();
}

std::vector<Textbox> Scene::getBoxes() {
  return boxes_;
}

Textbox Scene::getBox(int index) {
    try
    {
        if (index + 1 > boxes_.size()){
            throw("Out of bounds vector");
        }
        else return boxes_[index];
    }
    catch(const std::string& e)
    {
        std::cerr << e << '\n';
        return Textbox(); //if error creates a temporary default textbox and pushes that
    }
}

void Scene::draw(sf::RenderWindow& window) {
    for (size_t i = 0; i < this->boxes_.size(); i++)
    {
        this->boxes_[i].draw(window);
    }
    
}

void Scene::setBox(int index, Textbox box) {
    try
    {
        if (index + 1 > boxes_.size()){
            throw("Out of bounds vector");
        }
        else this->boxes_[index] = std::move(box);
    }
    catch(const std::string& e)
    {
        std::cerr << e << '\n';
    }
}

void Scene::addBox(Textbox box) { this->boxes_.push_back(std::move(box)); }
