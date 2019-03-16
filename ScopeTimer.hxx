#pragma once

#include <string>
#include <chrono>
#include <cstdint>
#include <iostream>

namespace the5 {
namespace util {

	class ScopeTimer {
	public:
		ScopeTimer(const char* text = "", size_t iterations = 0) :text(text), iterations(iterations)
		{
			start = std::chrono::high_resolution_clock::now();
		}

		~ScopeTimer()
		{
			auto end = std::chrono::high_resolution_clock::now();
			auto delta = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
			long double millisec = delta / 1000.0;
			if (iterations > 2) millisec /= iterations;

			printf("ScopeTimer: \"%s\" ", text);
			if (iterations > 1) printf("(avg. for %u iterations) ", iterations);
			printf("took %f ms\n", millisec);
		}

	protected:
		size_t iterations;
		const char* text;
		std::chrono::time_point<std::chrono::high_resolution_clock> start;
	};

}
}