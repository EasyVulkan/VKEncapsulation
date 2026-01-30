#include <format>
#include <chrono>
#include <iostream>

class Timer {
	using time_point = std::chrono::steady_clock::time_point;
	time_point start;
	time_point last;
	time_point present;
	void(*fPrint)(double);
	/* Static */
	static constexpr auto PrintToConsole = [](double value) { std::cout << std::format("{}\n", value); };
public:
	Timer(void(*fPrint)(double) = PrintToConsole) :fPrint(fPrint) {
		start = last = std::chrono::steady_clock::now();
	}
	~Timer() { if (fPrint) fPrint(DurationFromStart()); }
	/* Setter */
	void FPrint(void(*fPrint)(double)) { this->fPrint = fPrint; }
	/* Non-const Function */
	void TickTock() {
		last = present = std::chrono::steady_clock::now();
	}
	double DurationFromStart() {
		TickTock();
		return std::chrono::duration<double>(present - start).count();
	}
	double DurationFromLast() {
		present = std::chrono::steady_clock::now();
		double duration = std::chrono::duration<double>(present - last).count();
		last = present;
		return duration;
	}
	operator double() { return DurationFromLast(); }
	void Print() { fPrint(DurationFromLast()); }
};