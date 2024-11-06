#pragma once

#include "Anchor.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/System/Vector2.hpp"
#include <deque>

class AnchorGenerator {
private:
    int m_anchorSpreadRadius;

    std::unique_ptr<sf::Image> m_anchorImage = std::make_unique<sf::Image>();
    std::shared_ptr<sf::Texture> m_anchorTexture = std::make_shared<sf::Texture>();

    std::deque<Anchor*> m_queue;
    Anchor* m_dirtyAnchor;
    Anchor* m_activeAnchor;

    void populateAnchorQueue();
    sf::Vector2i getNextAnchorPosition();
    int getRandomDistance(int min, int max);

public:
    AnchorGenerator(int anchorSpreadRadius);
    ~AnchorGenerator();

    void update();
    void render(sf::RenderTarget& target);

    void updateAnchorPosition();
};
