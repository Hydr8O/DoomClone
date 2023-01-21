#pragma once

class Texture {
public:
    Texture(const std::string& texture_path, int rotate, GLenum type);
    void use(GLenum texture_number);
    uint32_t get_id();
private:
    uint32_t m_id;
};