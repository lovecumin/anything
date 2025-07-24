#pragma once
using namespace std;

class point
{
public:
	void set_x(int x);
	
	int get_x();

	void set_y(int y);
	
	int get_y();

private:
	int m_x;
	int m_y;
};