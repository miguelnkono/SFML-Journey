#ifndef WINDOW_HPP
    #define WINDOW_HPP

    #include <string>
    #include <SFML/Graphics.hpp>
    //#include <SFML/Graphics/RenderWindow.hpp>

    class Window
    {
    private:
        void Setup(const std::string& l_title, const sf::Vector2u& l_size);
        void Destroy();
        void Create();

        sf::RenderWindow m_window;
        sf::Vector2u m_windowSize;
        std::string m_title;
        bool m_isDone;
        bool m_isFullScreen;

    public:
        Window(const std::string& l_title, const sf::Vector2u& l_size);
        Window();
        ~Window();

        void BeginDrawing();        // Clear the window
        void EndDrawing();          // Display the changes

        void Update();

        bool isDone();
        bool isFullScreen();
        sf::Vector2u GetWindowSize();

        void ToggleFullScreen();

        void Draw(sf::Drawable& l_drawable);
    };
    

#endif