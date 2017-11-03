#pragma once
#include <Siv3D.hpp>
#include "Tile.h"

class Board
{
	const static uint16 width = 4 + 2;
	const static uint16 height = 4 + 2;
	const static uint16 size = width * height;

	Tile tiles[size];
public:
	Board();
	~Board();

	Board &init();
	Board &shuffle(uint32 count);

	void update();
	void draw();

	void keyInput();

	Tile &findTile(uint32 number);
	Tile &getPointTile(Vec2 pos);
	Tile &emptyTile();

	bool MoveTile(Vec2 pos);


	static Vec2 GetDrawStartPos();
};

