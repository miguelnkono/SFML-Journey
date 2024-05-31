#ifndef GAME_HPP
    #define Game_HPP
    #include "Window.hpp"

    class Game
    {
    private:
        void MoveMushroom();
        Window m_window;
        
    public:
        Game();
        ~Game();
        void HandleInput();
        void Update();
        void Render();
        Window* GetWindow();
        sf::Texture m_MushroomTexture;
        sf::Sprite m_Mushroom;
        sf::Vector2i m_increment;
    };
    

#endif