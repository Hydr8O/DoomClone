#include <iostream>
#include <glad/glad.h>
#include <texture.h>
#include <stb_image.h>
#include <string>


Texture::Texture(const std::string& texture_path, int rotate, GLenum type) {
    if (rotate) stbi_set_flip_vertically_on_load(true);
    int width, height, channels;
    uint8_t* data = stbi_load(texture_path.c_str(), &width, &height, &channels, 0);
    if (!data) {
        std::cout << "Failed to load texture!" << std::endl;
        stbi_image_free(data);
        return;
    }

    glGenTextures(1, &m_id);
    glBindTexture(GL_TEXTURE_2D, m_id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, type, width, height, 0, type, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);
    stbi_image_free(data);
}

uint32_t Texture::get_id() {
    return m_id;
}

void Texture::use(GLenum texture_number) {
    glActiveTexture(texture_number);
    glBindTexture(GL_TEXTURE_2D, m_id);
}