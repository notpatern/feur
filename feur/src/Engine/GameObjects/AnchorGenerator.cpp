#include "AnchorGenerator.hpp"
#include "SFML/Graphics/RenderTarget.hpp"
#include "SFML/System/Vector2.hpp"
#include <random>

AnchorGenerator::AnchorGenerator(int anchorSpreadRadius) : m_anchorSpreadRadius{anchorSpreadRadius} {
    m_anchorImage->loadFromFile(".\\feur\\src\\Resources\\anchor.png");
    m_anchorTexture->loadFromImage(*m_anchorImage);

    populateAnchorQueue();
}

AnchorGenerator::~AnchorGenerator() {
    delete m_dirtyAnchor;
    delete m_activeAnchor;
}

void AnchorGenerator::update() {
    for (auto& anchor : m_queue) {
        anchor->update();
    }
}

void AnchorGenerator::render(sf::RenderTarget& target) {
    for (auto& anchor : m_queue) {
        anchor->render(target);
    }
}

void AnchorGenerator::populateAnchorQueue() {
    m_queue.push_back(new Anchor(1, {300, 400}, m_anchorTexture, 2));
    m_activeAnchor = m_queue.front();

    for (int i{0}; i < 5; i++) {
        sf::Vector2i nextPosition = getNextAnchorPosition();
        sf::Vector2i newPosition = { m_queue.front()->getPosition().x + nextPosition.x, m_queue.front()->getPosition().y - nextPosition.y };
        m_queue.push_front(new Anchor(1, newPosition, m_anchorTexture, 2));
    }
}

sf::Vector2i AnchorGenerator::getNextAnchorPosition() {
    sf::Vector2i lastPosition = m_queue.front()->getPosition();
    int distance = getRandomDistance(350, m_anchorSpreadRadius);
    int theta = getRandomDistance(25, 45);

    if (lastPosition.x > 600) {
        theta = getRandomDistance(135, 155);
    }

    return {static_cast<int>(distance * std::cos(theta * 0.01745329251994329576923690768489f)), static_cast<int>(distance * std::sin(theta * 0.01745329251994329576923690768489f))};
}

int AnchorGenerator::getRandomDistance(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(min, max);

    return distr(gen);
}
