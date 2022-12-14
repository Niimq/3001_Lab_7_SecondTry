#pragma once
#ifndef __PLAY_SCENE__
#define __PLAY_SCENE__

#include "Background.h"
#include "Obstacle.h"
#include "Scene.h"
#include "PathNode.h"
#include "Target.h"
#include "LOSMode.h"
#include "Agent.h"
//#include "CloseCombatEnemy.h"
#include "RangedCombatCondition.h"
//#include "../../../AI 3001 second Half/Lab 7.1 Starter/src/CloseCombatEnemy.h"
#include "../../../AI 3001 second Half/Lab 7.1 Starter/src/RangedCombatEnemy.h"


class PlayScene : public Scene
{
public:
	PlayScene();
	~PlayScene() override;

	// Scene LifeCycle Functions
	virtual void Draw() override;
	virtual void Update() override;
	virtual void Clean() override;
	virtual void HandleEvents() override;
	virtual void Start() override;
private:
	// IMGUI Function
	void GUI_Function();
	std::string m_guiTitle;
	bool m_isGridEnabled;
	// New for Lab 7
	int m_shipPosition[2];
	int m_angle;

	// Input Control
	int m_pCurrentInputType{};
	void GetPlayerInput();
	void GetKeyboardInput();

	// Game Objects
	Background* m_pBackground;
	Target* m_pTarget;
	// New for Lab 7
	// CloseCombatEnemy* m_pStarship;
	RangedCombatEnemy* m_pStarship;
	std::vector<Obstacle*> m_pObstacles;

	void BuildObstaclePool();

	// Create our Division Scheme (Grid of PathNodes)
	std::vector<PathNode*> m_pGrid;
	void m_buildGrid();
	void m_toggleGrid(bool state) const;
	bool m_checkAgentLOS(Agent* agent, DisplayObject* target_object) const;
	bool m_checkPathNodeLOS(PathNode* path_node, DisplayObject* target_object) const;
	void m_checkAllNodesWithTarget(DisplayObject* target_object) const;
	void m_checkAllNodesWithBoth() const;
	void m_setPathNodeLOSDistance(int dist) const;
	LOSMode m_LOSMode{};

	void m_clearNodes();
	int m_pathNodeLOSDistance;

};

#endif /* defined (__PLAY_SCENE__) */