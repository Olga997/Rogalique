#include <stack>
#include <vector>

#include "DeveloperLevel.h"

namespace RogaliqueGame {
class MazeGenerator {
   public:
    MazeGenerator(int width, int height, DeveloperLevel* level);
    void Generate();

   private:
    int width, height;
    DeveloperLevel* level;
    std::vector<std::vector<bool>> grid;

    std::vector<std::pair<int, int>> GetAvailableDirections(int x, int y);
    void RemoveWall(int x1, int y1, int x2, int y2);
};
}  // namespace RogaliqueGame
