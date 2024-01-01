#include "Camera.h"

Camera::Camera(glm::vec3 position, glm::vec3 front, glm::vec3 up)
	: position(position), front(front), worldUp(up), yaw(-90.0), pitch(0.0) {
	this->right = glm::normalize(glm::cross(this->front, this->worldUp));
	this->up = glm::normalize(glm::cross(this->right, this->front));
}

glm::mat4 Camera::get_view_matrix() const {
	return glm::lookAt(position, position + front, up);
}

glm::mat4 Camera::get_projection_matrix(float fov, float aspectRatio, float nearPlane, float farPlane) const {
	return glm::perspective(glm::radians(fov), aspectRatio, nearPlane, farPlane);
}

void Camera::moveForward(float delta) {
	position += front * delta;
}

void Camera::moveBackward(float delta) {
	position -= front * delta;
}

void Camera::moveLeft(float delta) {
	position -= right * delta;
}

void Camera::moveRight(float delta) {
	position += right * delta;
}

void Camera::moveUp(float delta) {
	position += up * delta;
}

void Camera::moveDown(float delta) {
	position -= up * delta;
}

void Camera::rotate(float yawOffset, float pitchOffset) {
	yaw += yawOffset;
	pitch += pitchOffset;
	
	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;

	updateCameraVectors();
}

void Camera::updateCameraVectors() {
	glm::vec3 newFront;
	newFront.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	newFront.y = sin(glm::radians(pitch));
	newFront.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	front = glm::normalize(newFront);

	right = glm::normalize(glm::cross(newFront, worldUp));
	up = glm::normalize(glm::cross(right, newFront));
}
