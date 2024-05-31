#ifndef GAME_HPP
    #define Game_HPP
    #include "Window.hpp"
    #include <string>
    class Game
    {
    private:
        void MoveMushroom();
        Window m_window;
        
    public:
        Window* GetWindow();
        Game();
        ~Game();
        void HandleInput();
        void Update();
        void Render();
        sf::Texture m_MushroomTexture;
        sf::Sprite m_Mushroom;
        sf::Vector2i m_increment;
    };  

#endif