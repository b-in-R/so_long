
#include "so_long.h"

//------------------------------------
// 	appel: create_trbg(0, 255, 255, 255);
//	
int	create_trbg(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

// pour retrouver les valeurs int?
int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}
