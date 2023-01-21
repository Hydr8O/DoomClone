#include <camera.h>

Camera::Camera(glm::vec3 camera_pos, glm::vec3 camera_front, glm::vec3 camera_up) :
    m_camera_pos(camera_pos), m_camera_front(camera_front), m_camera_up(camera_up) {
}

glm::mat4 Camera::compute_view() {
    return glm::lookAt(m_camera_pos, m_camera_pos + m_camera_front, m_camera_up);
}

void Camera::compute_direction(glm::vec2 mouse_pos, double sensitivity) {
    m_yaw += (mouse_pos.x - m_last_x) * sensitivity;
    m_pitch += (m_last_y - mouse_pos.y) * sensitivity;
    m_last_x = mouse_pos.x;
    m_last_y = mouse_pos.y;
    glm::vec3 direction;
    direction.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    direction.y = sin(glm::radians(m_pitch));
    direction.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
    m_camera_front = direction;
}

void Camera::move(float speed) {
    m_camera_pos += speed * m_camera_front;
}

void Camera::strafe(float speed) {
    m_camera_pos += speed * glm::normalize(glm::cross(m_camera_up, m_camera_front));
}