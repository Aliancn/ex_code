#include <iostream>
using namespace std;

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap(int year)
{
	return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
}

int get_day(int year, int month)
{
	if(month == 2) return 28 + is_leap(year);
	return days[month];
}

int main()
{
	int sum = 0, ans = 0;
	for (int i = 2000; i <= 2019; i ++)
		for (int j = 1; j <= 12; j ++)
			for (int k = 1; k <= get_day(i, j); k ++)
			{
				int weekday = (sum + 5) % 7;
				if(k == 1 || weekday == 0) ans += 2;
				else ans ++;
				sum ++;
			}
			
	for (int j = 1; j <= 9; j ++)
		for (int k = 1; k <= get_day(2020, j); k ++)
		{
			int weekday = (sum + 5) % 7;
			if(k == 1 || weekday == 0) ans += 2;
			else ans ++;
			sum ++;
		}			
	
	cout << ans + 2 << endl;
	return 0;
}
