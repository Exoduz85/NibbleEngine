#include "Camera.h"

Camera::Camera(glm::vec3 position, glm::vec3 target, glm::vec3 up)
	: position(position), target(target), up(up) {}

glm::mat4 Camera::get_view_matrix() const {
	return glm::lookAt(position, position + target, up);
}

glm::mat4 Camera::get_projection_matrix(float fov, float aspectRatio, float nearPlane, float farPlane) const {
	return glm::perspective(glm::radians(fov), aspectRatio, nearPlane, farPlane);
}
