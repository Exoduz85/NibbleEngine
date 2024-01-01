#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera {
public:
	Camera(glm::vec3 position, glm::vec3 front, glm::vec3 up);

	void moveForward(float delta);
	void moveBackward(float delta);
	void moveLeft(float delta);
	void moveRight(float delta);
	void moveUp(float delta);
	void moveDown(float delta);

	void rotate(float yaw, float pitch);

	glm::mat4 get_view_matrix() const;
	glm::mat4 get_projection_matrix(float fov, float aspectRatio, float nearPlane, float farPlane) const;

private:
	glm::vec3 position;
	glm::vec3 front;
	glm::vec3 up;
	glm::vec3 right;
	glm::vec3 worldUp;

	float yaw;
	float pitch;

	void updateCameraVectors();
};

#endif // CAMERA_H
