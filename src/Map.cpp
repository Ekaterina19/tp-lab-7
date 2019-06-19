#include "Map.h"

using namespace std;

vector<string> Map = {	"0000000000000000",
						"0000000000000000",
						"0000000000000000",
						"0000000000s00000",
						"0000000000000000",
						"0000000000000000",
						"00000s0000000000",
						"00000000000s0000",
						"0000000000000000" };

bool isInBounds(int x, int y)
{
	if (x >= 0 && x < MAP_WIDTH &&
		y >= 0 && y < MAP_HEIGHT)
		return true;
	else
		return false;
	return false;
}
