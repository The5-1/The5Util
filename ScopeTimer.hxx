#pragma once

#include <string>
#include <chrono>
#include <iostream>

namespace the5 {
namespace util {

	class ScopeTimer {
	public:
		ScopeTimer(const char* text = "", int line = -1, unsigned int iterations = 0) :text(text), line(line), iterations(iterations)
		{
			start = std::chrono::high_resolution_clock::now();
		}

		~ScopeTimer()
		{
			auto end = std::chrono::high_resolution_clock::now();
			auto dur = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
			long long int microsec = static_cast<long long int>(dur.count());
			if (iterations > 2) microsec /= iterations;

			long double millisec = microsec / 1000.0;

			printf("Timer: %s ", text);
			if (line > -1) printf("in line %u", line);
			if (iterations > 2) printf("(avg. for %u iterations) ", iterations);
			printf("took %Lfms\n", millisec);
		}

	protected:
		unsigned int iterations;
		const char* text;
		unsigned int line;
		std::chrono::time_point<std::chrono::high_resolution_clock> start;
	};

#define SCOPETIMER() the5::util::ScopeTimer t(__FILE__, __LINE__, 0)
#define SCOPETIMERAVG(iterations) the5::util::ScopeTimer t(__FILE__, __LINE__,iterations)

}
}