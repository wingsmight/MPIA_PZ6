#pragma once
#include <chrono>

typedef std::chrono::high_resolution_clock hrc;
namespace {
	class Timer {
	public:
		Timer() {}

		void start() {
			begin = hrc::now();
		}

		double getTime() {
			return std::chrono::duration<double>(hrc::now() - begin).count();
		}

		double click() {
			double res = std::chrono::duration<double>(hrc::now() - begin).count();
			begin = hrc::now();
			return res;
		}

	private:
		hrc::time_point begin;
	};
}