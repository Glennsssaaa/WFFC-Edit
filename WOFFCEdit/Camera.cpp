#include "Camera.h"

Camera::Camera(Vector3 pos, Vector3 lookAt, int height, int width)
{
	m_position = pos;
	m_lookAt = lookAt;
	m_orientation = Vector3::Zero;
	m_lookDirection = Vector3::Forward;
	m_up = Vector3::Up;
	m_right = Vector3::Right;

	m_yaw = 0.0f;
	m_pitch = 0.0f;
	m_roll = 0.0f;

	m_moveSpeed = 10.0f;
	m_turnSpeed = 4.0f;

	m_height = height;
	m_width = width;

}

void Camera::Update(const InputCommands& input, const float deltaTime){

	
	if (!input.mouse_RB_Down) {
		m_mousePosPrev = Vector2(input.mouse_X, input.mouse_Y);
		return;
	}


	
	Vector2 mouseDelta = Vector2(input.mouse_X, input.mouse_Y) - m_mousePosPrev;
	m_mousePosPrev = Vector2(input.mouse_X, input.mouse_Y);
	
	m_orientation.y += mouseDelta.x * m_turnSpeed * deltaTime;
	m_orientation.x -= mouseDelta.y * m_turnSpeed * deltaTime;

	//clamp x orientation
	if (m_orientation.x > 1.5f)
	{
		m_orientation.x = 1.5f;
	}
	if (m_orientation.x < -1.5f)
	{
		m_orientation.x = -1.5f;
	}

	//create right vector from look Direction
	m_lookDirection.Cross(Vector3::UnitY, m_right);

	//process input and update stuff
	if (input.forward)
	{
		m_position += m_lookDirection;
	}
	if (input.back)
	{
		m_position -= m_lookDirection;
	}
	if (input.right)
	{
		m_position += m_right;
	}
	if (input.left)
	{
		m_position -= m_right;
	}
	

	//create look direction from Euler angles in m_camOrientation
	m_lookDirection.x = cos(m_orientation.y) * cos(m_orientation.x);
	m_lookDirection.y = sin(m_orientation.x);
	m_lookDirection.z = sin(m_orientation.y) * cos(m_orientation.x);
	m_lookDirection.Normalize();

	m_lookDirection.Cross(Vector3::UnitY, m_right);

	//update lookat point
	m_lookAt = m_position + m_lookDirection;

	//apply camera vectors
	m_viewMatrix = Matrix::CreateLookAt(m_position, m_lookAt, Vector3::UnitY);
	
}