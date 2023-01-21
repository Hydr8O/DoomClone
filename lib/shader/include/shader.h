#pragma once
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader {
public:
    Shader(const std::string& vertex_shader_path, const std::string& fragment_shader_path);
    void use();
    uint32_t get_id();
    int get_uniform_location(const std::string& variable_name);
    void set_model_matrix(glm::mat4 model_matrix);
    void set_view_matrix(glm::mat4 view_matrix);
    void set_projection_matrix(glm::mat4 projection_matrix);

private:
    uint32_t m_id;
    int m_success;
    std::string read_shader(const std::string& shader_path);
    uint32_t compile_shader(const std::string& shader_src, uint32_t shader_type);
    std::string get_shader_compile_error_message(uint32_t shader_id);
    std::string get_shader_link_error_message();
    void create_shader_program(uint32_t vertex_shader_id, uint32_t fragment_shader_id);
};