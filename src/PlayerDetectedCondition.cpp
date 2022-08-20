#include "PlayerDetectedCondition.h"

PlayerDetectedCondition::PlayerDetectedCondition(const bool detected)
{
	m_name = "Player Detected Condition";
	SetDetected(detected);
}

PlayerDetectedCondition::~PlayerDetectedCondition()
= default;

bool PlayerDetectedCondition::GetDetected()
{
	return m_detected;
}

void PlayerDetectedCondition::SetDetected(const bool state)
{
	m_detected = state;
}

bool PlayerDetectedCondition::Condition()
{
	return m_detected;
}
