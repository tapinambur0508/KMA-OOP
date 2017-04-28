#include <iostream>
#include "Time.h"

using namespace std;

class Date;
class Time;
class Timer
{
private:
	Date _d;
	Time _t;
	int _replay_count;
	int _interval_between_replay;
	void beep_beep();
public:
	Timer(Date&, Time&, int&, int&);
	~Timer();

	Date date() const { return _d; }
	Time time() const { return _t; }
	void launch();

	int& replay_count() { return _replay_count;  }
	int& interval_between_replay() { return _interval_between_replay; }
};