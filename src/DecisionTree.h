#pragma once
#ifndef __DECISION_TREE__
#define __DECISION_TREE__

#include "Agent.h"
#include "CloseCombatCondition.h"
#include "LOSCondition.h"
#include "RadiusCondition.h"
#include "TreeNode.h"
#include "TreeNodeType.h"
#include "RangedCombatCondition.h"
#include "EnemyHealthCondition.h"
#include "EnemyHitCondition.h"
#include "PlayerDetectedCondition.h"

#include <vector>
#include "../../../AI 3001 second Half/Lab 7.1 Starter/src/RangedCombatCondition.h"

class DecisionTree
{
public:
	// Constructor(s)
	DecisionTree(); // default constructor
	DecisionTree(Agent* agent);

	// Destructor
	~DecisionTree();

	// Getters and Setters (Accessors and Mutators)
	[[nodiscard]] Agent* GetAgent() const;
	void SetAgent(Agent* agent);

	[[nodiscard]] LOSCondition* GetLOSNode() const;
	[[nodiscard]] RadiusCondition* GetRadiusNode() const;
	[[nodiscard]] CloseCombatCondition* GetCloseCombatNode() const;
	RangedCombatCondition* GetRangedCombatNode() const;
	std::vector<TreeNode*>& GetTree();

	// New for ab 7 part 3
	EnemyHealthCondition* GetEnemyHealthNode() const;
	EnemyHitCondition* GetEnemyHitNode() const;
	PlayerDetectedCondition* GetPlayerDetectionNode() const;

	// New for Lab 7 part 2
	void SetLOSNode(LOSCondition* node);
	void SetRadiusNode(RadiusCondition* node);
	void SetCloseCombatNode(CloseCombatCondition* node);
	void SetRangedCombatNode(RangedCombatCondition* node);

	// New for ab 7 part 3
	void SetEnemyHealthNode(EnemyHealthCondition* node);
	void SetEnemyHithNode(EnemyHitCondition* node);
	void setPlayerDetectedNode(PlayerDetectedCondition* node);

	// Public Utility / Convenience Methods
	TreeNode* AddNode(TreeNode* parent, TreeNode* child_node, TreeNodeType type);
	void Display() const;
	void Update();
	void Clean();

	void MakeDecision() const; // in-order traversal

private:
	// Private Data Members (Fields)
	Agent* m_agent{};
	LOSCondition* m_LOSNode{};
	RadiusCondition* m_RadiusNode{};
	CloseCombatCondition* m_CloseCombatNode{};
	// new for Lab 7 part 2
	RangedCombatCondition* m_RangedCombatNode{};
	// New for Lab 7 part 3
	EnemyHealthCondition* m_EnemyHealthNode{};
	EnemyHitCondition* m_EnemyHithNode{};
	PlayerDetectedCondition* m_playerDetectedNode{};

	// TreeNode List
	std::vector<TreeNode*> m_treeNodeList;

	// Private Methods
	//void m_buildTree();
};

#endif /* defined (__DECISION_TREE__) */