#include "SimpleObject.h"

struct SimpleObject::MeshData {
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
};

Shader* SimpleObject::shader;
Mesh* SimpleObject::mesh;

SimpleObject::SimpleObject(Shader* usedShader, ShapeTypes shape)
{
	shader = usedShader;
	MeshData data;
	switch(shape)
	{
		case ShapeTypes::Cube:
			data = create_cube();
			break;
		case ShapeTypes::Cylinder: break;
		case ShapeTypes::Circle: break;
		case ShapeTypes::Box: break;
		case ShapeTypes::Triangle: break;
		default: ;
	}

	mesh = new Mesh(data.vertices, data.indices);
	const auto model = glm::mat4(1.0f);
	shader->set_mat4("model", model);
}

void SimpleObject::draw()
{
	mesh->draw();
}

SimpleObject::MeshData SimpleObject::create_cube()
{
	MeshData data;
	data.vertices = {
		// Front face
	    {glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(0.0f, 0.0f,  1.0f), glm::vec2(0.0f, 0.0f)},
	    {glm::vec3( 0.5f, -0.5f,  0.5f), glm::vec3(0.0f, 0.0f,  1.0f), glm::vec2(1.0f, 0.0f)},
	    {glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec3(0.0f, 0.0f,  1.0f), glm::vec2(1.0f, 1.0f)},
	    {glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(0.0f, 0.0f,  1.0f), glm::vec2(0.0f, 1.0f)},
	    
	    // Back face
	    {glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(1.0f, 0.0f)},
	    {glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(0.0f, 0.0f)},
	    {glm::vec3( 0.5f,  0.5f, -0.5f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(0.0f, 1.0f)},
	    {glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(0.0f, 0.0f, -1.0f), glm::vec2(1.0f, 1.0f)},
	    
	    // Left face
	    {glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(-1.0f, 0.0f,  0.0f), glm::vec2(1.0f, 0.0f)},
	    {glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(-1.0f, 0.0f,  0.0f), glm::vec2(1.0f, 1.0f)},
	    {glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(-1.0f, 0.0f,  0.0f), glm::vec2(0.0f, 1.0f)},
	    {glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(-1.0f, 0.0f,  0.0f), glm::vec2(0.0f, 0.0f)},

	    // Right face
	    {glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec3( 1.0f, 0.0f,  0.0f), glm::vec2(1.0f, 0.0f)},
	    {glm::vec3( 0.5f, -0.5f,  0.5f), glm::vec3( 1.0f, 0.0f,  0.0f), glm::vec2(0.0f, 0.0f)},
	    {glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec3( 1.0f, 0.0f,  0.0f), glm::vec2(0.0f, 1.0f)},
	    {glm::vec3( 0.5f,  0.5f, -0.5f), glm::vec3( 1.0f, 0.0f,  0.0f), glm::vec2(1.0f, 1.0f)},

	    // Top face
	    {glm::vec3(-0.5f,  0.5f, -0.5f), glm::vec3(0.0f,  1.0f,  0.0f), glm::vec2(0.0f, 1.0f)},
	    {glm::vec3(-0.5f,  0.5f,  0.5f), glm::vec3(0.0f,  1.0f,  0.0f), glm::vec2(0.0f, 0.0f)},
	    {glm::vec3( 0.5f,  0.5f,  0.5f), glm::vec3(0.0f,  1.0f,  0.0f), glm::vec2(1.0f, 0.0f)},
	    {glm::vec3( 0.5f,  0.5f, -0.5f), glm::vec3(0.0f,  1.0f,  0.0f), glm::vec2(1.0f, 1.0f)},

	    // Bottom face
	    {glm::vec3(-0.5f, -0.5f, -0.5f), glm::vec3(0.0f, -1.0f,  0.0f), glm::vec2(1.0f, 1.0f)},
	    {glm::vec3( 0.5f, -0.5f, -0.5f), glm::vec3(0.0f, -1.0f,  0.0f), glm::vec2(0.0f, 1.0f)},
	    {glm::vec3( 0.5f, -0.5f,  0.5f), glm::vec3(0.0f, -1.0f,  0.0f), glm::vec2(0.0f, 0.0f)},
	    {glm::vec3(-0.5f, -0.5f,  0.5f), glm::vec3(0.0f, -1.0f,  0.0f), glm::vec2(1.0f, 0.0f)},
	};
	
	data.indices = {
		// Front face
		0, 1, 2, 0, 2, 3,
		// Back face
		4, 5, 6, 4, 6, 7,
		// Left face
		8, 9, 10, 8, 10, 11,
		// Right face
		12, 13, 14, 12, 14, 15,
		// Top face
		16, 17, 18, 16, 18, 19,
		// Bottom face
		20, 21, 22, 20, 22, 23
	};

	return data;
}
