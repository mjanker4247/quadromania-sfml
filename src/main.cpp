#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>

int main()
{
    // Desired logical size and aspect ratio
    const float logicalWidth = 640.f;
    const float logicalHeight = 480.f;
    const float aspectRatio = logicalWidth / logicalHeight;

    // Load the frame image
    sf::Texture frameTexture;
    if (!frameTexture.loadFromFile("data/frame.png"))
    {
        // If loading fails, create a default window
        sf::RenderWindow window(sf::VideoMode({640, 480}), "CMake SFML Project - Error Loading Image");
        window.setFramerateLimit(144);
        
        while (window.isOpen())
        {
            while (const std::optional event = window.pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                {
                    window.close();
                }
            }

            window.clear(sf::Color::Red); // Red background to indicate error
            window.display();
        }
        return -1;
    }

    // Get the size of the loaded image
    sf::Vector2u imageSize = frameTexture.getSize();
    
    // Create window with raster-adjusted size that maintains proportions

    // Create resizable window
    sf::RenderWindow window(sf::VideoMode((unsigned int)logicalWidth, (unsigned int)logicalHeight),
                            "Aspect-Ratio Locked Window",
                            sf::Style::Default); // Resizable
    window.setFramerateLimit(144);
    // Set initial view
    sf::View view(sf::FloatRect(0, 0, logicalWidth, logicalHeight));
    window.setView(view);

    // Create a sprite to display the image
    sf::Sprite frameSprite(frameTexture);

    // Create a graphical text to display
    sf::Font font;
    if (!font.openFromFile("data/font.ttf")) {
        std::cerr << "Failed to load font!\n";
        return -1;
    }
    sf::Text headline(font, "QUADROMANIA", 50);
    headline.setCharacterSize(rasterSize.y / 20); // Relative size based on window height
    headline.setFillColor(sf::Color::White);
    headline.setPosition(sf::Vector2f(rasterSize.x * 0.5f - 100.0f, rasterSize.y * 0.1f)); // Centered horizontally, 10% from top

    // Load a music to play
    sf::Music music("data/sound/music.ogg");
 
    // Play the music
    music.play();

    while (window.isOpen()) {
        sf::Event event;
        while (const std::optional event = window.pollEvent()) {
            // Close window
            if (event->is<sf::Event::Closed>())
                window.close();

            // Handle resizing while preserving aspect ratio
            if (event.type == sf::Event::Resized) {
                float newWidth = event.size.width;
                float newHeight = event.size.height;
                float newAspect = newWidth / newHeight;

                sf::FloatRect viewport;

                if (newAspect > aspectRatio) {
                    // Window too wide: add horizontal bars
                    float widthFactor = aspectRatio / newAspect;
                    viewport = sf::FloatRect((1 - widthFactor) / 2.f, 0.f, widthFactor, 1.f);
                } else {
                    // Window too tall: add vertical bars
                    float heightFactor = newAspect / aspectRatio;
                    viewport = sf::FloatRect(0.f, (1 - heightFactor) / 2.f, 1.f, heightFactor);
                }

                view.setViewport(viewport);
                window.setView(view);

                window.clear();
                window.draw(frameSprite); // Draw the frame image
                window.draw(headline); // Draw the headline text
                window.display();
            }
        }
}
