#include "../include/Game.hpp"

Game::Game(/* args */):
    m_window("Chapter 2", sf::Vector2u(800, 600))
{
    // setting up the class memeber
    m_MushroomTexture.loadFromFile("/home/gost/Bureau/SFML/Shape/images/mushroom1.jpeg");
    m_Mushroom.setTexture(m_MushroomTexture);
    m_increment = sf::Vector2i(400, 400);
}

Game::~Game()
{
}

void Game::Update()
{
    m_window.Update();
    MoveMushroom();
}

void Game::MoveMushroom()
{
    float fElapsed = m_elapsted.asSeconds();
    sf::Vector2u l_windSize = m_window.GetWindowSize();
    sf::Vector2u l_textSize = m_MushroomTexture.getSize();

    if((m_Mushroom.getPosition().x > l_windSize.x - l_textSize.x&& m_increment.x > 0) || (m_Mushroom.getPosition().x < 0 && m_increment.x < 0))
    {
        m_increment.x = -m_increment.x;
    }

    if((m_Mushroom.getPosition().y > l_windSize.y - l_textSize.y&& m_increment.y > 0) || (m_Mushroom.getPosition().y < 0 && m_increment.y < 0))
    {
        m_increment.y = -m_increment.y;
    }

    m_Mushroom.setPosition(
        m_Mushroom.getPosition().x + m_increment.x * fElapsed,
        m_Mushroom.getPosition().y + m_increment.y * fElapsed
    );
}

void Game::Render()
{
    m_window.BeginDrawing();
    m_window.Draw(m_Mushroom);
    m_window.EndDrawing();
}

void Game::HandleInput()
{
}
Window* Game::GetWindow()
{
    return &(m_window);
}

sf::Time Game::GetElapsed()
{
    return m_elapsted;
}

void Game::RestartClock()
{
    m_elapsted =  m_clock.restart();
}