#ifndef SIMPLEOBJECT_H
#define SIMPLEOBJECT_H
#include "Mesh.h"

class SimpleObject {
public:
	SimpleObject(Mesh* mesh) : mesh(mesh) {}

	void draw() {
		mesh->draw();
	}

private:
	Mesh* mesh;
};
#endif // SIMPLEOBJECT_H
