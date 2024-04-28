#ifndef SCENE_HPP
#define SCENE_HPP

#include <vector>
#include "../SFMLsupport/Textbox.hpp"
#include <memory>

/**
 * @brief Generic game scene class
 * 
 */
class Scene
{
protected:
    
    std::vector<Textbox> boxes_;

public:

    Scene();
    ~Scene();

    std::vector<Textbox> getBoxes();
    Textbox getBox(int index);

    /**
     * @brief Should handle events of child classes
     * 
     * @param event sfml event from main loop 
     */
    virtual void input(sf::Event& event, sf::RenderWindow& window) = 0;

    void draw(sf::RenderWindow& window);

    //TODO: add functions to add boxes (done?) and edit them easy (should be able to move the getter to protected)

    /**
     * @brief Set a Textbox at index
     * 
     * @param index 
     * @param box 
     */
    void setBox(int index, Textbox box);

    /**
     * @brief Add a Textbox at end of vector
     * 
     * @param box 
     */
    void addBox(Textbox box);
};

#endif //SCENE_HPP