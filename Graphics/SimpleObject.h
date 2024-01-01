#ifndef SIMPLEOBJECT_H
#define SIMPLEOBJECT_H

#include "Mesh.h"
#include "Shader.h"
#include "ShapeTypes.h"

class SimpleObject {
public:
	SimpleObject(Shader* usedShader, ShapeTypes shape);
	static void draw();

private:
	static Shader* shader;
	static Mesh* mesh;
	struct MeshData;
	static MeshData create_cube();
	
};
#endif // SIMPLEOBJECT_H
