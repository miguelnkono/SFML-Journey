#include "../include/Window.hpp"

Window::Window()
{
    Setup("Window", sf::Vector2u(640, 480));
}
Window::Window(const std::string& l_title, const sf::Vector2u& l_size)
{
    Setup(l_title, l_size);
}
Window::~Window()
{
    Destroy();
}

void Window::Setup(const std::string& l_title, const sf::Vector2u& l_size)
{
    m_title         = l_title;
    m_windowSize    = l_size;
    m_isFullScreen  = false;
    m_isDone        = false;
    Create();
}

void Window::Create()
{
    sf::Uint32 /* unsign */ Style = (m_isFullScreen ? sf::Style::Fullscreen : sf::Style::Default);
    m_window.create({m_windowSize.x, m_windowSize.y, 32}, m_title, Style );
    //m_window.setFramerateLimit(60);       // Using sf::RenderWindow::setFramerateLimit() to ensures the frame-rate
}

void Window::Destroy()
{
    m_window.close();
}

void Window::Update()
{
    sf::Event event;
    while (m_window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed || (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape))
        {
            m_isDone = true;
        } else if (event.type == sf::Event::KeyPressed && event.key.code  == sf::Keyboard::F5)
        {
            //m_isFullScreen = true;
            ToggleFullScreen();
        }
        
    }
    
}

void Window::ToggleFullScreen()
{
    m_isFullScreen = !m_isFullScreen;
    Destroy();
    Create();
}

void Window::BeginDrawing()
{
    m_window.clear(sf::Color::Black);
}

void Window::EndDrawing()
{
    m_window.display();
}

bool Window::isDone()
{
    return m_isDone;
}

bool Window::isFullScreen()
{
    return m_isFullScreen;
}

sf::Vector2u Window::GetWindowSize()
{
    return m_windowSize;
}

void Window::Draw(sf::Drawable& l_drawable)
{
    m_window.draw(l_drawable);
}