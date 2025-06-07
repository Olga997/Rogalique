#include "Creeper.h"

namespace RogaliqueGame 
{
Creeper::Creeper( XYZEngine::GameObject* player, sf::Color color) 
    : AI(player,color)
{
    
}
std::unique_ptr<AI> Creeper::Clone() const { return std::make_unique<Creeper>(*this); };
}  // namespace RogaliqueGame
