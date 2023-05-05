#pragma once
#include "pch.h"
#include "InputCommands.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

class Camera
{
public:
	Camera();
	Camera(Vector3 pos, Vector3 lookAt, int height, int width);

	void Update(const InputCommands& inputCommands, float deltaTime);
	void LookAtObject(Vector3 objLoc);
	
	Vector3 GetPosition() const { return m_position; }
	Vector3 GetLookAt() const { return m_lookAt; }
	Matrix GetView() const { return m_viewMatrix; }
	Matrix GetProjection() const { return m_projectionMatrix; }


	void SetProjection(const Matrix& proj){m_projectionMatrix = proj;};

private:
	Vector3 m_orientation;
	Vector3 m_up;
	Vector3 m_right;

	float m_yaw;
	float m_pitch;
	float m_roll;

	float m_moveSpeed;
	float m_turnSpeed;

	int m_height;
	int m_width;

	Matrix m_viewMatrix;
	Matrix m_projectionMatrix;

	Vector2 m_mousePos;
	Vector2 m_mousePosPrev;

public:
	Vector3 m_position;
	Vector3 m_lookDirection;
	Vector3 m_lookAt;

};

