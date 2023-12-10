#ifndef MESH_H
#define MESH_H

#include <GL/glew.h>

class Mesh {
public:
	Mesh(float* vertices, size_t size);
	~Mesh();
	void Draw();

private:
	unsigned int VAO, VBO;
	void setupMesh();
};

#endif
