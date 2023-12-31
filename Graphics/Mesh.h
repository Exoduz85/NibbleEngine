#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>
#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>

struct Vertex {
	glm::vec3 Position;
	glm::vec3 Normal;
	glm::vec2 TexCoords;
};

class Mesh {
public:
	Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices);
	~Mesh();
	void draw();

private:
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
	unsigned int VAO, VBO, EBO;

	void setup_mesh();
};

#endif
