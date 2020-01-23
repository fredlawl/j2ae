
#ifndef J2AE_QUADTREE_H
#define J2AE_QUADTREE_H


#include <vector>
#include <SFML/Graphics/Rect.hpp>

template<class T>
struct QuadTreeNode
{
	T* obj;
	sf::FloatRect bounds;
};

class QuadTree
{
public:

	explicit QuadTree(unsigned level, sf::FloatRect bounds) :
		level(level),
		bounds(bounds)
	{

	}

	void clear()
	{
		int i = 0;
		treeNodes.clear();
		for (; i < NUM_OF_NODES; ++i) {
			nodes[i]->clear();
			delete nodes[i];
			nodes[i] = nullptr;
		}
	}

	void insert(const QuadTreeNode& treeNode)
	{
		if (nodes[0] != nullptr) {
			int index = getIndex(treeNode);

			if (index != -1) {
				nodes[index]->insert(treeNode);
				return;
			}
		}

		treeNodes.push_back(treeNode);

		if (treeNodes.size() > MAX_OBJECTS_PER_LEVEL && level < MAX_LEVELS) {
			if (nodes[0] == nullptr) {
				split();
			}

			int i = 0;
			while (i < treeNodes.size()) {
				int index = getIndex(treeNode);
				if (index != -1) {
					nodes[index]->insert(treeNode);
				} else {
					i++;
				}
			}
		}
	}

	std::vector<QuadTreeNode> getNeighbors(const QuadTreeNode& treeNode) const
	{
        std::vector<QuadTreeNode> returnObjects;
		int index = getIndex(treeNode);
        int i = 0;

		if (index != -1 && nodes[0] != nullptr) {
			nodes[index]->getNeighbors(treeNode);
		}

        returnObjects
        getNearestNeighborsHelper(returnObjects);

		return returnObjects;
	}


private:
	const int NUM_OF_NODES = 4;
	const int MAX_OBJECTS_PER_LEVEL = 10;
	const int MAX_LEVELS = 5;

	unsigned level = 0;
	sf::FloatRect bounds;
	std::vector<QuadTreeNode> treeNodes;
	QuadTree* nodes[NUM_OF_NODES];

	void split()
	{
		float subWidth = (bounds.width / 2);
		float subHeight = (bounds.height / 2);
		float x = bounds.left;
		float y = bounds.top;

		nodes[0] = new QuadTree(level + 1, {x + subWidth, y, subWidth, subHeight});
		nodes[1] = new QuadTree(level + 1, {x, y, subWidth, subHeight});
		nodes[2] = new QuadTree(level + 1, {x, y + subHeight, subWidth, subHeight});
		nodes[3] = new QuadTree(level + 1, {x + subWidth, y + subHeight, subWidth, subHeight});
	}

	int getIndex(const QuadTreeNode& treeNode) const
	{
		int index = -1;
		double verticalMidpoint = bounds.left + (bounds.width / 2);
		double horizontalMidpoint = bounds.top + (bounds.height / 2);

		// Object can completely fit within the top quadrants
		bool topQuadrant = (treeNode.bounds.top < horizontalMidpoint && treeNode.bounds.top + treeNode.bounds.height < horizontalMidpoint);
		// Object can completely fit within the bottom quadrants
		bool bottomQuadrant = (treeNode.bounds.top > horizontalMidpoint);

		// Object can completely fit within the left quadrants
		if (treeNode.bounds.left < verticalMidpoint && treeNode.bounds.left + treeNode.bounds.width < verticalMidpoint) {
			if (topQuadrant) {
				index = 1;
			}
			else if (bottomQuadrant) {
				index = 2;
			}
		}
        // Object can completely fit within the right quadrants
		else if (treeNode.bounds.left > verticalMidpoint) {
			if (topQuadrant) {
				index = 0;
			}
			else if (bottomQuadrant) {
				index = 3;
			}
		}

		return index;
	}

    void getNearestNeighborsHelper(std::vector<QuadTreeNode>& list) const
    {

    }

};

#endif
