#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <unordered_map>
#include <string>

/**
 * Represents a manager for loading and retrieving images (textures) for the game.
 */

class ResourceManager {
public:

    static ResourceManager& getInstance();
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager& operator=(const ResourceManager&) = delete;
    const sf::Texture& getImage(const std::string& name) const;
    const sf::Font& getFont(const std::string& name) const;

private:
    ResourceManager();

    template <typename Resource>
    void loadResource(std::unordered_map<std::string, Resource>& resourceMap, const std::string& name, 
                      const std::string& filename);

    std::unordered_map<std::string, sf::Texture> textures;
    std::unordered_map<std::string, sf::Font> m_fonts;

};


