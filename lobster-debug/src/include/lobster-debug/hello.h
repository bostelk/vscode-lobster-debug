#pragma once

#include <unordered_set>
#include <functional>
#include <mutex>

// sourceContent holds the synthetic file source.
constexpr char sourceContent[] = R"(// Hello Debugger!

This is a synthetic source file provided by the DAP debugger.

You can set breakpoints, and single line step.

You may also notice that the locals contains a single variable for the currently executing line number.)";

// Total number of newlines in source.
constexpr int64_t numSourceLines = 7;

// Debugger holds the dummy debugger state and fires events to the EventHandler
// passed to the constructor.
class Debugger {
public:
	enum class Event { BreakpointHit, Stepped, Paused };
	using EventHandler = std::function<void(Event)>;

	Debugger(const EventHandler&);

	// run() instructs the debugger to continue execution.
	void run();

	// pause() instructs the debugger to pause execution.
	void pause();

	// currentLine() returns the currently executing line number.
	int64_t currentLine();

	// stepForward() instructs the debugger to step forward one line.
	void stepForward();

	// clearBreakpoints() clears all set breakpoints.
	void clearBreakpoints();

	// addBreakpoint() sets a new breakpoint on the given line.
	void addBreakpoint(int64_t line);

private:
	EventHandler onEvent;
	std::mutex mutex;
	int64_t line = 1;
	std::unordered_set<int64_t> breakpoints;
};
