#pragma once

#include "Anchor.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/System/Vector2.hpp"
#include <deque>

class AnchorGenerator {
private:
    int m_anchorSpreadRadius;
    double m_deltaTime;

    std::unique_ptr<sf::Image> m_anchorImage = std::make_unique<sf::Image>();
    std::shared_ptr<sf::Texture> m_anchorTexture = std::make_shared<sf::Texture>();

    std::deque<Anchor*> m_queue;
    Anchor* m_dirtyAnchor;
    Anchor* m_activeAnchor;

    void populateAnchorQueue();
    sf::Vector2i getNextAnchorPosition();
    int getRandomDistance(int min, int max);

public:
    AnchorGenerator(int anchorSpreadRadius, double& deltaTime);
    ~AnchorGenerator();

    void update();
    void render(sf::RenderTarget& target);

    void updateAnchorPosition(float playerPositionCopy, float destination);
};
