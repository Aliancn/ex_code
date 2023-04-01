#include <iostream>
using namespace std;

int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool is_leap(int year)
{
	return year % 400 == 0 || year % 4 == 0 && year % 100 != 0;
}

bool check1(int x)
{
	int year = x / 10000;
	int month = x / 100 % 100;
	int day = x % 100;
	
	if(month < 1 || month > 12) return false;
	if(month != 2) 
	{
		if(day < 1 || day > days[month]) return false;
	}
	else
	{
		if(day < 1 || day > days[month] + is_leap(year)) return false;
	}
	return true;
}



int main()
{
	int ans = 0;
    int week = 6;
	for (int i = 20000101; i <= 20201001; i ++)
		if(check1(i) ) {
            if(week== 1||(i%100==1)){
                ans+=2;
            }
            else{
                
                ans++;
            }
            week%=7;
            week++;
        }
	
	cout << ans << endl;
	return 0;
}
