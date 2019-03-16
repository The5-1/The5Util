#pragma once

#include <string>
#include <chrono>
#include <cstdint>
#include <iostream>

namespace the5 {
namespace util {

	class ScopeTimer {
	public:
		ScopeTimer(const char* text = "", size_t iterations = 0, unsigned int line = 0) :text(text), line(line), iterations(iterations)
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
			if (line > 0) printf("in line %u ", line);
			if (iterations > 1) printf("(avg. for %u iterations) ", iterations);
			printf("took %Lfms\n", millisec);
		}

	protected:
		size_t iterations;
		const char* text;
		unsigned int line;
		std::chrono::time_point<std::chrono::high_resolution_clock> start;
	};

#define SCOPETIMER() the5::util::ScopeTimer t(__FILE__, 0, __LINE__)
#define SCOPETIMERAVG(iterations) the5::util::ScopeTimer t(__FILE__, iterations, __LINE__)

}
}