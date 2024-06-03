#ifndef GAME_HPP
    #define Game_HPP
    #include "Window.hpp"
    #include <string>
    class Game
    {
    private:
        void MoveMushroom();
        Window m_window;
        sf::Clock  m_clock;
        sf::Time m_elapsted;
        
    public:
        Window* GetWindow();
        Game();
        ~Game();
        void HandleInput();
        void Update();
        void Render();
        sf::Time GetElapsed();
        void RestartClock();
        sf::Texture m_MushroomTexture;
        sf::Sprite m_Mushroom;
        sf::Vector2i m_increment;
    };  

#endif