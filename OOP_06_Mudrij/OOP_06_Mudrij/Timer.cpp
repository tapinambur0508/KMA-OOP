#include "Timer.h"
#include <ctime>
#include <Windows.h>

Timer::Timer(Date& d, Time& t, int& replay_count, int& interval_between_replay) : _d(d), _t(t), 
	_replay_count(replay_count), _interval_between_replay(interval_between_replay)
{
	cout << "Timer has been created:" << endl;
	return;
}

Timer::~Timer()
{
	cout << "Timer has been removed:" << endl;;
	return;
}

void Timer::beep_beep()
{
	int count = replay_count();

	while (count)
	{
		cout << "\a";
		--count;
		Sleep(interval_between_replay() * 1000);
	}
}

void Timer::launch()
{
	time_t t = ::time(NULL);
	struct tm now;
	localtime_s(&now, &t);

	Time current_time = Time(now.tm_sec, now.tm_min, now.tm_hour);
	Date current_date = Date(now.tm_mday, now.tm_mon + 1, now.tm_year + 1900);

	while (current_date.day() != this->date().day() || current_date.month() != this->date().month() ||
		current_date.year() != this->date().year() || current_time.seconds() != this->time().seconds() ||
		current_time.minutes() != this->time().minutes() || current_time.hours() != this->time().hours())
	{
		if (current_time.seconds() == 59)
		{
			current_time.seconds() = 0;

			if (current_time.minutes() == 59)
			{
				current_time.minutes() = 0;

				if (current_time.hours() == 23)
				{
					current_time.hours() = 0;
					current_date.setDay(current_date.day() + 1);
				}
				else
				{
					current_time.hours() += 1;
				}
			}
			else
			{
				current_time.minutes() += 1;
			}
		}
		else
		{
			current_time.seconds() += 1;
		}

		Sleep(1000);
		cout << current_date.year() << ' ' << current_date.month() << ' ' << current_date.day() << ' ' << 
			current_time.hours() << ":" << current_time.minutes() << ":" << current_time.seconds() << endl;
	}
	
	beep_beep();
}