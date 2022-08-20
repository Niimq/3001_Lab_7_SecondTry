#include "EnemyHealthCondition.h"

EnemyHealthCondition::EnemyHealthCondition(Agent* agent, const bool healthy)
	:ConditionNode(agent)
{
	m_name = "EnemyHealthCondition Condition";
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
