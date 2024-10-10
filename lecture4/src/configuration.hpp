#pragma once

#include <SFML/System/Vector2.hpp>
#include <cstdint>

namespace conf {
// window configuration
sf::Vector2u const window_size = {2560, 1440};
sf::Vector2f const window_size_f = static_cast<sf::Vector2f>(window_size);
uint32_t const max_framerate = 144;
float const dt = 1.0f / static_cast<float>(max_framerate);

// star configuration
uint32_t const count = 1000;
float const radius = 20.0f;
float const far = 10.0f;
float const near = 1.0f;
float const speed = 1.0f;
}
