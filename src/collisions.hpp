#include <glm/ext/vector_float3.hpp>

const float SOLDIER_RANGE = 5.0f;

glm::vec3 CrossProduct(glm::vec3 a, glm::vec3 b);

bool RayIntersectsTopFace(glm::vec3 ray_origin, glm::vec3 ray_dir, glm::vec3 block_pos, float block_size, float& t_out);

std::vector<glm::vec3> getSoldiersBottomFaceEdges(
    glm::vec3 soldier_pos, 
    glm::vec3 soldier_dir, 
    glm::vec3 soldier_dimentions
);

bool SoldierStepsOnBlock(
    glm::vec3 soldier_pos,
    int& selected_x,
    int& selected_z
);

bool InSoldiersRange(
    glm::vec3 soldier_pos, 
    int selected_x,
    int selected_z
);

bool GetBlockThatIntersectsWithRay(
    glm::vec3 ray_origin, 
    glm::vec3 ray_dir, 
    int& selected_x, 
    int& selected_y
);