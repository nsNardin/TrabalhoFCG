// The board is represented as a 2D array of blocks. 

#include "minesweeper_logic.hpp"
#include "collisions.hpp"

glm::vec3 CrossProduct(glm::vec3 a, glm::vec3 b)
{
    return glm::vec3(
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    );
}

bool RayIntersectsTopFace(glm::vec3 ray_origin, glm::vec3 ray_dir, glm::vec3 block_pos, float block_size, float& t_out)
{
    float y_plane = block_pos.y + block_size / 2.0f;

    if (std::abs(ray_dir.y) < 1e-6f) return false;

    float t = (y_plane - ray_origin.y) / ray_dir.y;
    if (t < 0.0f) return false;

    glm::vec3 hit = ray_origin + ray_dir * t;

    if (hit.x >= block_pos.x - block_size/2 && hit.x <= block_pos.x + block_size/2 &&
        hit.z >= block_pos.z - block_size/2 && hit.z <= block_pos.z + block_size/2)
    {
        t_out = t;
        return true;
    }
    return false;
}

std::vector<glm::vec3> getSoldiersBottomFaceEdges(
    glm::vec3 soldier_pos, 
    glm::vec3 soldier_dir, 
    glm::vec3 soldier_dimentions
){
    // Returns the positions of the four edges of the soldier's bottom face
    // Assumes y=1 for all points
    glm::vec3 up(0.0f, 1.0f, 0.0f);
    glm::vec3 right = CrossProduct(soldier_dir, up);
    glm::vec3 front = soldier_dir * (soldier_dimentions.z / 2.0f);
    glm::vec3 back = -soldier_dir * (soldier_dimentions.z / 2.0f);
    glm::vec3 left = -right * (soldier_dimentions.x / 2.0f);
    right = right * (soldier_dimentions.x / 2.0f);

    glm::vec3 center_bottom = glm::vec3(soldier_pos.x, 1.0f, soldier_pos.z);

    std::vector<glm::vec3> edges;
    // Front left
    edges.push_back(center_bottom + front + left);
    // Front right
    edges.push_back(center_bottom + front + right);
    // Back left
    edges.push_back(center_bottom + back + left);
    // Back right
    edges.push_back(center_bottom + back + right);

    return edges;
}

// Just gets the integer part of the soldier's position
glm::vec3 SoldierStepsOnBlock(glm::vec3 soldier_pos){
    
}
    

bool InSoldiersRange(
    glm::vec3 soldier_pos, 
    glm::vec3 block_pos
){
    // Disconsiders vertical position of soldier and block
    // Considers if block_pos is inside a circle with radius 1.0f
    float dx = soldier_pos.x - block_pos.x;
    float dz = soldier_pos.z - block_pos.z;
    float distance = std::sqrt(dx * dx + dz * dz);
    return distance <= SOLDIER_RANGE;
}