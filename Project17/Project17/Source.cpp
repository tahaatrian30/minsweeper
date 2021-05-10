#include<iostream>
#include<stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include<ctime>
using namespace std;
void color(int textColor, int backColor = 0)

{

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	int colorAttribute = backColor << 4 | textColor;

	SetConsoleTextAttribute(consoleHandle, colorAttribute);

}
int tedad_bomb(int, int);
int open(int, int, char);
int chk();
void print();
void end();
int zir[31][31];
char roo[31][31];
int main() {
	srand(time(NULL));
	char t;
	do {
		int ii, jj, s=-2;
		char a, x, y,K;
		for (int i = 0; i < 31; i++) {//matris namayeshi
			for (int j = 0; j < 31; j++) {
				if (i == 0) {
					roo[i][j] = char(64 + j);
				}
				else if (j == 0)
				{
					roo[i][j] = char(64 + i);
				}
				else {
					roo[i][j] = '*';
				}
			}
		}
		roo[0][0] = ' ';
		for (int i = 0; i < 30;) {//bomb gozari
			ii = rand() % 30 + 1;
			jj = rand() % 30 + 1;
			if (zir[ii][jj] != -1) {
				zir[ii][jj] = -1;
				++i;
			}
		}
		for (int i = 1; i < 31; i++) {
			for (int j = 1; j < 31; j++) {
				if (zir[i][j] != -1) {
					zir[i][j] = tedad_bomb(i, j);
				}
			}
		}
		while (true)
		{
			print();
			cout << "please inter the position and f or o" << endl;
			cin >> x >> y;
			cin >> a;
			ii = int(x) - 64, jj = int(y) - 64;
			s = open(ii, jj, a);
			if (s == 0) {
				break;
			}
			if (s == 2) {
				cin >> t;
				if (t == 'y' || t == 'Y') {
					roo[ii][jj] = '*';
					s = open(ii, jj, 'o');
					if (s == 0)
						break;
				}
			}
			K = chk();
			if (K == 0) {
				end();
				color(3, 0);
				cout << "You won!!!!" << endl;
				color(7, 0);
				break;
			}
		}
			cout << "play again ?! y or n"<<endl;
			cin >> t;
	} while (t=='y' || t== 'Y');
	return 0;
}
	int tedad_bomb(int i,int j) { //tabe meghdar bomb
		int f=0;
		if ((zir[i - 1][j - 1] == -1)&&i-1<31&&i-1>0&&j-1<31&&j-1>0)
			++f;
		if ((zir[i - 1][j] == -1) && i - 1 < 31 && i - 1 > 0 && j < 31 && j > 0)
			++f;
		if ((zir[i - 1][j + 1] == -1) && i - 1 < 31 && i - 1 > 0 && j + 1 < 31 && j + 1 > 0)
			++f;
		if ((zir[i][j - 1] == -1) && i < 31 && i > 0 && j - 1 < 31 && j - 1 > 0)
			++f;
		if ((zir[i ][j + 1] == -1) && i < 31 && i > 0 && j + 1 < 31 && j + 1 > 0)
			++f;
		if ((zir[i + 1][j - 1] == -1) && i + 1 < 31 && i + 1 > 0 && j - 1 < 31 && j - 1 > 0)
			++f;
		if ((zir[i + 1][j] == -1) && i + 1 < 31 && i + 1 > 0 && j < 31 && j > 0)
			++f;
		if ((zir[i + 1][j + 1] == -1) && i + 1 < 31 && i + 1 > 0 && j + 1 < 31 && j + 1 > 0)
			++f;
		return f;
	}
	int open(int i, int j, char a) { //baz kardan khane ha
		if (roo[i][j] == '^') { //flag boodan
			cout << "are you sure? y or n" << endl;
			return 2;
		}else{
		if (a == 'f' || a == 'F') {
			roo[i][j] = '^';
			return 1;
		}
		else
		{
			if (zir[i][j] == -1) {
				end();
				color(4, 0);
				cout << '\a'<<"Game Over !" << endl;
				color(7, 0);
				return 0;
			}
			else if (zir[i][j] == 0)
			{
				roo[i][j] = '0';
				if (i - 1 < 31 && i - 1 > 0 && j - 1 < 31 && j - 1 > 0 && roo[i - 1][j - 1] != '0')
					open(i - 1, j - 1, 'o');
				if (i - 1 < 31 && i - 1 > 0 && j < 31 && j  > 0 && roo[i - 1][j] != '0')
					open(i - 1, j, 'o');
				if (i - 1 < 31 && i - 1 > 0 && j + 1 < 31 && j + 1 > 0 && roo[i - 1][j + 1] != '0')
					open(i - 1, j, 'o');
				if (i < 31 && i > 0 && j - 1 < 31 && j - 1 > 0 && roo[i][j - 1] != '0')
					open(i, j - 1, 'o');
				if (i < 31 && i > 0 && j + 1 < 31 && j + 1 > 0 && roo[i - 1][j + 1] != '0')
					open(i, j + 1, 'o');
				if (i + 1 < 31 && i + 1 > 0 && j - 1 < 31 && j - 1 > 0 && roo[i + 1][j - 1] != '0')
					open(i + 1, j - 1, 'o');
				if (i + 1 < 31 && i + 1 > 0 && j < 31 && j > 0 && roo[i + 1][j] != '0')
					open(i + 1, j, 'o');
				if (i + 1 < 31 && i + 1 > 0 && j + 1 < 31 && j + 1 > 0 && roo[i + 1][j + 1] != '0')
					open(i + 1, j + 1, 'o');
				return 1;
			}
			else {
				roo[i][j] = char(zir[i][j] + int('0'));
				return 1;
			}
		}
		}
	}
	void print() { //shop kardan 
		for (int i = 0; i < 31; i++) {
			for (int j = 0; j < 31; j++) {
				if (roo[i][j] == '0') {//rang 
					color(8, 0);
					cout << roo[i][j] << ' ';
					color(7, 0);
				}
				else if(roo[i][j]=='1')
				{
					color(3, 0);
					cout << roo[i][j] << ' ';
					color(7, 0);
				}
				else if(roo[i][j]=='2')
				{
					color(2, 0);
					cout << roo[i][j] << ' ';
					color(7, 0);
				}
				else if(roo[i][j]=='3')
				{
					color(5, 0);
					cout << roo[i][j] << ' ';
					color(7, 0);
				}
				else if(roo[i][j]=='4')
				{
					color(6, 0);
					cout << roo[i][j] << ' ';
					color(7, 0);
				}
				else if(roo[i][j]=='5')
				{
					color(9, 0);
					cout << roo[i][j] << ' ';
					color(7, 0);
				}
				else if(roo[i][j]=='6')
				{
					color(1, 0);
					cout << roo[i][j] << ' ';
					color(7, 0);
				}
				else if(roo[i][j]=='^')
				{
					color(7, 0);
					cout << roo[i][j] << ' ';
					color(7, 0);
				}
				else
				{
					cout << roo[i][j] << ' ';
				}
			}
			cout << endl;
		}
	}
	void end() {
		for (int i = 0;i < 31;i++) {
			for (int j = 0;j < 31;j++) {
				if (i == 0&&j==0) {
					cout << roo[i][j]<<" ";
				}
				else
				{
					if (i == 0) {
						cout << roo[i][j] << ' ';
					}
					else if (j == 0) {
						cout << roo[i][j]<<' ';
					}
					else
					{
						if (zir[i][j] == -1) {
							cout << '@' << ' ';
						}
						else {
							cout << zir[i][j] << ' ';
						}
					}
				}
			}
			cout << endl;
		}
	}
	int chk() {
		int flag = 0;
		for (int i = 1;i < 31;i++) {
			for (int j = 1;j < 31;j++) {
				if (zir[i][j] != -1) {
					if (roo[i][j] == '*'||roo[i][j]=='^'){
						return 1;
					}
				}
			}
		}
		return 0;
	}