#pragma once
#include <vector>
#include <string>

#define MAP_WIDTH 16
#define MAP_HEIGHT 9

#define X_FACTOR 1366.0f / (float)MAP_WIDTH
#define Y_FACTOR 768.0f / (float)MAP_HEIGHT

extern std::vector<std::string> Map;

bool isInBounds(int x, int y);
