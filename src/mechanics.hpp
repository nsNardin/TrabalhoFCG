// Objectives: 
// 1) detect colisions
    // a) character X block
    // b) character X rock
    // c) center viewline X block
// 2) calculate at colision
    // a) normal
    // b) location
// 3) calculate character
    // a) location
    // b) velocity
    // c) acceleration

#include "minesweeper_logic.hpp"

// Note: there is a 3D block grid
// where the coodinates of the botton edge of the first block is (0, 0, 0)
// each block is 1x1x1

bool inField(std::vector<float> position){
    if (position[0] < 0 
        || position[0] > BOARD_WIDTH 
        || position[1] < 0 
        || position[1] > BOARD_DEPTH 
        || position[2] < 0 
        || position[2] > BOARD_DEPTH){
        return false;
    }
    return true;
}

bool collidable(Block block){
    return true;
}

// Detect where the view line intersects with the y=1 plane
std::vector<float> viewLineXPlane(std::vector<float> cameraPosition, std::vector<float> cameraDirection){
    float t = (1 - cameraPosition[1]) / cameraDirection[1];
    std::vector<float> intersection = {cameraPosition[0] + t * cameraDirection[0], 1, cameraPosition[2] + t * cameraDirection[2]};
    return intersection;
}

// Detect which block is the first colidable block the player is looking at
std::vector<int> lookingAtBlock(
    std::vector<float> cameraPosition, 
    std::vector<float> cameraDirection, 
    Board board){
        std::vector<float> intersection = viewLineXPlane(cameraPosition, cameraDirection);
        std::vector<int> blockPosition = {int(intersection[0]), int(intersection[1]), int(intersection[2])};
        return blockPosition;
    }
