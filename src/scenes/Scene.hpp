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
    
    std::vector<std::shared_ptr<Textbox>> boxes_;

public:

    Scene();
    ~Scene();

    std::vector<std::shared_ptr<Textbox>> getBoxes();
    std::shared_ptr<Textbox> getBox(int index);

    /**
     * @brief Should handle events of child classes
     * 
     * @param event sfml event from main loop 
     */
    virtual void input(sf::Event event) = 0;

    void draw(sf::RenderWindow& window);

};

#endif //SCENE_HPP