#pragma once
#ifndef __TREE_NODE__
#define __TREE_NODE__
#include <string>
#include "Agent.h"

struct TreeNode
{
	TreeNode()
	{
		m_agent = nullptr;
	}

	virtual ~TreeNode() = default;

	std::string m_name = "";

	TreeNode* m_pLeft = nullptr;
	TreeNode* m_pRight = nullptr;
	TreeNode* m_pParent = nullptr;
	bool m_isLeaf = false;

	[[nodiscrd]] Agent* GetAgent() const { return m_agent; }
	void SetAgent(Agent* agent) { m_agent = agent; }

protected:
	Agent* m_agent;
};

#endif /* defined (__TREE_NODE__) */
