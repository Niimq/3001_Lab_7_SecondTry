#include "EnemyHealthCondition.h"

EnemyHealthCondition::EnemyHealthCondition(const bool healthy)
{
	m_name = "Radius Condition";
	SetHealth(healthy);
}

EnemyHealthCondition::~EnemyHealthCondition()
= default;

void EnemyHealthCondition::SetHealth(const bool healthy)
{
	m_healthy = healthy;
}

bool EnemyHealthCondition::Condition()
{
	return m_healthy;
}
