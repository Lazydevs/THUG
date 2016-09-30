#include "LZ/timer.h"

using namespace lz;

timer::timer()
{
	reset();
}

timer::~timer()
{
}

void timer::reset()
{
	m_start = t_high_res_clock::now();
}
