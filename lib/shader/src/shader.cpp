#include <fstream>
#include <iostream>
#include <shader.h>
#include <glad/glad.h>


Shader::Shader(const std::string& vertex_shader_path, const std::string& fragment_shader_path) {
    std::string vertex_shader_src = read_shader(vertex_shader_path);
    std::string fragment_shader_src = read_shader(fragment_shader_path);
    uint32_t vertex_shader_id = compile_shader(vertex_shader_src, GL_VERTEX_SHADER);
    if (!m_success) {
        std::string error_message = get_shader_compile_error_message(vertex_shader_id);
        std::cout << "Vertex " << error_message << std::endl; 
    } else {
        std::cout << "Vertex shader compiled successfuly" << std::endl;
    }

    uint32_t fragment_shader_id = compile_shader(fragment_shader_src, GL_FRAGMENT_SHADER);
    if (!m_success) {
        std::string error_message = get_shader_compile_error_message(fragment_shader_id);
        std::cout << "Fragment " << error_message << std::endl; 
    } else {
        std::cout << "Fragment shader compiled successfuly" << std::endl;
    }
    
    create_shader_program(vertex_shader_id, fragment_shader_id);
    if (!m_success) {
        std::string error_message = get_shader_link_error_message();
        std::cout << error_message << std::endl; 
    } else {
        std::cout << "Shader program created successfuly" << std::endl;
    }

    glDeleteShader(vertex_shader_id);
    glDeleteShader(fragment_shader_id);
}

void Shader::create_shader_program(uint32_t vertex_shader_id, uint32_t fragment_shader_id) {
    m_id = glCreateProgram();
    glAttachShader(m_id, vertex_shader_id);
    glAttachShader(m_id, fragment_shader_id);
    glLinkProgram(m_id);
    glGetProgramiv(m_id, GL_LINK_STATUS, &m_success);
}

std::string Shader::get_shader_compile_error_message(uint32_t shader_id) {
    const size_t message_length = 512;
    char message[message_length];
    if (!m_success) {
        glGetShaderInfoLog(shader_id, 512, nullptr, message);
    }
    std::string error_message{message, message + strlen(message)};
    return error_message;
}

std::string Shader::get_shader_link_error_message() {
    const size_t message_length = 512;
    char message[message_length];
    if (!m_success) {
        glGetProgramInfoLog(m_id, 512, nullptr, message);
    }
    std::string error_message{message, message + strlen(message)};
    return error_message;
}

uint32_t Shader::compile_shader(const std::string& shader_src, uint32_t shader_type) {
    uint32_t shader_id;
    shader_id = glCreateShader(shader_type);
    
    const char* shader_src_char = shader_src.c_str();
    glShaderSource(shader_id, 1, &shader_src_char, nullptr);
    glCompileShader(shader_id);
    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &m_success);
    return shader_id;
}

std::string Shader::read_shader(const std::string& shader_path) {
    std::ifstream in(shader_path);
    return std::string{std::istreambuf_iterator<char>(in), std::istreambuf_iterator<char>()};
}

void Shader::use() {
    glUseProgram(m_id);
}

int Shader::get_uniform_location(const std::string& variable_name) {
    return glGetUniformLocation(m_id, variable_name.c_str());
}

uint32_t Shader::get_id() {
    return m_id;
}

void Shader::set_model_matrix(glm::mat4 model_matrix) {
    int location = get_uniform_location("model");
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(model_matrix));
}

void Shader::set_view_matrix(glm::mat4 view_matrix) {
    int location = get_uniform_location("view");
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(view_matrix));
}

void Shader::set_projection_matrix(glm::mat4 projection_matrix) {
    int location = get_uniform_location("projection");
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(projection_matrix));
}