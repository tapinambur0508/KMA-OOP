#include <iostream>

using namespace std;

class Screen
{
private:
	//����������� ������ ������
	static const int maxHeight;
	//����������� ������ ������
	static const int maxWidth;
	//����������
	static const char _filler;

	//�������� ������ ������
	int _height;
	//�������� ������ ������
	int _width;

	//���������� ������
	char *_wContent;
	//������
	mutable int _cursor;

	//��������� ������ �� �����������
	Screen(const Screen&);
	Screen& operator= (const Screen&);
public:
	//����� ������������ ������ pc,
	//���� �� �������, ������ �� ������������
	//������������ _filler
	Screen(int width = 10, int height = 10, char* pc = 0);
	~Screen();

	//���� �� �� ��������� ������
	//��������� ������ �� ������� ������
	const Screen& home() const;
	Screen& home();

	//�������� ������ �� ���� ������ ������
	const Screen& move() const;
	Screen& move();

	//�������� ������ �� ���� ������ ����
	const Screen& back() const;
	Screen& back();

	//�������� ���� ������
	const Screen& show() const;
	Screen& show();

	//��������� ������ �� ������ �������
	const Screen& move(int, int) const;
	Screen& move(int, int);

	//�������������
	Screen& clear();

	//�������� ������, �� ����� ����������� ������
	const Screen& showCurrent() const;

	//��������
	char get() const;
	//�����������
	Screen& set(char);

	//�������� ������ ��� ��������� ���������
	const int& width() const { return _width; }
	const int& height() const { return _height; }
	const char* content() const { return _wContent; }
};

ostream& operator<<(ostream&, const Screen&);

typedef const Screen& (Screen::* const ConstAction) () const;
typedef Screen& (Screen::* const NonConstAction) ();

void doActionConst(const Screen& s, ConstAction act, int n);
void doActionNonConst(Screen& s, NonConstAction act, int n);
