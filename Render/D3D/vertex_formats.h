#include <d3d9.h>

#define CUSTOMFVF (D3DFVF_XYZRHW | D3DFVF_DIFFUSE)

struct CUSTOMVERTEX
{
    FLOAT x, y, z, rhw;
    DWORD color;
};