#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader {
public:
	Shader(const char* vertexPath, const char* fragmentPath);
	void use();
	void set_bool(const std::string &name, bool value) const;
	void set_int(const std::string &name, int value) const;
	void set_float(const std::string &name, float value) const;
	void set_mat4(const std::string &name, const glm::mat4 &mat) const;
	unsigned int ID;

private:
	void check_compile_errors(unsigned int shader, std::string type);
};

#endif // SHADER_H
