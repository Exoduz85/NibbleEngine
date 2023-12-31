#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:
	Camera(glm::vec3 position, glm::vec3 target, glm::vec3 up);

	glm::mat4 get_view_matrix() const;
	glm::mat4 get_projection_matrix(float fov, float aspectRatio, float nearPlane, float farPlane) const;

	private:
	glm::vec3 position;
	glm::vec3 target;
	glm::vec3 up;
};

#endif // CAMERA_H
