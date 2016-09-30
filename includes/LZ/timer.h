#ifndef TIMER_H
# define TIMER_H

# include <chrono>

namespace lz
{
	class timer
	{
	private:
		typedef std::chrono::high_resolution_clock t_high_res_clock;
		typedef std::chrono::duration<float, std::milli> t_milli_type;
		std::chrono::time_point<t_high_res_clock> m_start;

	public:
		timer();
		~timer();

		void reset();

		inline float elapsed()
		{
			return (std::chrono::duration_cast<t_milli_type>(t_high_res_clock::now() - m_start).count());
		}
	};
}
#endif
