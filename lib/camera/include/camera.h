#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:
    Camera(glm::vec3 camera_pos, glm::vec3 camera_front, glm::vec3 camera_up);
    glm::mat4 compute_view();
    void move(float speed);
    void strafe(float speed);
    void compute_direction(glm::vec2 mouse_pos, double sensitivity);
private:
    glm::vec3 m_camera_pos, m_camera_front, m_camera_up;
    double m_yaw = -90, m_pitch = 0, m_last_x = 400, m_last_y = 300;
};