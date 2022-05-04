#include <iostream>
#include <cstring>
#include <cstdio>
#include <ctime>
#include <Windows.h>
using namespace std;
char map[20][20],ch;
int scoremap[20][20],order;
int a, b, a1, b1, a2, b2;
                              //�ж���Ӯ
bool winorlose(int x, int y,char t) {
	int count;
	count = 1;                         //��ֱ����
	for (int i = x, j = y + 1; i >= 0 && j >= 0 && i < 20 && j < 20 && j <= y + 5; j++) {
		if (map[i][j] == t) count++;
		else break;
	}
	for (int i = x, j = y - 1; i >= 0 && j >= 0 && i < 20 && j < 20 && j >= y - 5; j--) {
		if (map[i][j] == t) count++;
		else break;
	}
	if (count >= 6) return true;
	count = 1;                    //ˮƽ����
	for (int i = x + 1, j = y; i >= 0 && j >= 0 && i < 20 && j < 20 && i <= x + 5; i++) {
		if (map[i][j] == t) count++;
		else break;
	}
	for (int i = x - 1, j = y; i >= 0 && j >= 0 && i < 20 && j < 20 && i >= x - 5; i--) {
		if (map[i][j] == t) count++;
		else break;
	}
	if (count >= 6) return true;
	count = 1;          //������б������
	for (int i = x + 1, j = y + 1; i >= 0 && j >= 0 && i < 20 && j < 20 && i <= x + 5 && j <= y + 5; i++, j++) {
		if (map[i][j] == t) count++;
		else break;
	}
	for (int i = x - 1, j = y - 1; i >= 0 && j >= 0 && i < 20 && j < 20 && i >= x - 5 && j >= y - 5; i--, j--) {
		if (map[i][j] == t) count++;
		else break;
	}
	if (count >= 6) return true;
	count = 1;    //����б������
	for (int i = x - 1, j = y + 1; i >= 0 && j >= 0 && i < 20 && j < 20 && i >= x - 5 && j <= y + 5; i--, j++) {
		if (map[i][j] == t) count++;
		else break;
	}
	for (int i = x + 1, j = y - 1; i >= 0 && j >= 0 && i < 20 && j < 20 && i <= x + 5 && j >= y - 5; i++, j--) {
		if (map[i][j] == t) count++;
		else break;
	}
	if (count >= 6) return true;
	return false;
} 
                          //�жϺϷ���
bool legal(int x, int y) {
	if (x > 19 || x < 0 || y>19 || y < 0 || map[x][y] != '*')
		return false;
	else return true;
}
                   //�ж��Ƿ���壬 ����-1��20ʱ����
bool huiqi(int x, int y) {
	if (x == -1 && y == 20)
		return true;
	else return false;
} 
                  //�ж��Ƿ����
bool heqi( ) {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			if (map[i][j] == '*') return false;
		}
	}
	return true;
}
                 //�ж��Ƿ����
bool jinshou(int x, int y, char t, char s) {     //tΪ�Լ����ӣ�sΪ�з�����
	int num4 = 0, num5 = 0, i, j;
	int count;
	char temp1, temp2;
	count = 1;          //��ֱ�����жϽ���
	for (i = x, j = y + 1; i >= 0 && j >= 0 && i < 20 && j < 20 && j <= y + 4; j++) {
		if (map[i][j] == t) count++;
		else break;
	}
	temp1 = map[i][j];
	for (i = x, j = y - 1; i >= 0 && j >= 0 && i < 20 && j < 20 && j >= y - 4; j--) {
		if (map[i][j] == t) count++;
		else break;
	}
	temp2 = map[i][j];
	if (count == 4) {
		num4++;
		if (temp1 == s && temp2 == s) num4--;
	}
	if (count == 5) {
		num5++;
		if (temp1 == s && temp2 == s) num5--;
	}
	count = 1;          //ˮƽ�����жϽ���
	for (i = x + 1, j = y; i >= 0 && j >= 0 && i < 20 && j < 20 && i <= x + 4; i++) {
		if (map[i][j] == t) count++;
		else break;
	}
	temp1 = map[i][j];
	for (i = x - 1, j = y; i >= 0 && j >= 0 && i < 20 && j < 20 && i >= x - 4; i--) {
		if (map[i][j] == t) count++;
		else break;
	}
	temp2 = map[i][j];
	if (count == 4) {
		num4++;
		if (temp1 == s && temp2 == s) num4--;
	}
	if (count == 5) {
		num5++;
		if (temp1 == s && temp2 == s) num5--;
	}
	count = 1;    //������б������
	for (i = x + 1, j = y + 1; i >= 0 && j >= 0 && i < 20 && j < 20 && i <= x + 4 && j <= y + 4; i++, j++) {
		if (map[i][j] == t) count++;
		else break;
	}
	temp1 = map[i][j];
	for (i = x - 1, j = y - 1; i >= 0 && j >= 0 && i < 20 && j < 20 && i >= x - 4 && j >= y - 4; i--, j--) {
		if (map[i][j] == t) count++;
		else break;
	}
	temp2 = map[i][j];
	if (count == 4) {
		num4++;
		if (temp1 == s && temp2 == s) num4--;
	}
	if (count == 5) {
		num5++;
		if (temp1 == s && temp2 == s) num5--;
	}
	count = 1;    //����б������
	for (i = x - 1, j = y + 1; i >= 0 && j >= 0 && i < 20 && j < 20 && i >= x - 4 && j <= y + 4; i--, j++) {
		if (map[i][j] == t) count++;
		else break;
	}
	temp1 = map[i][j];
	for (i = x + 1, j = y - 1; i >= 0 && j >= 0 && i < 20 && j < 20 && i <= x + 4 && j >= y - 4; i++, j--) {
		if (map[i][j] == t) count++;
		else break;
	}
	temp2 = map[i][j];
	if (count == 4) {
		num4++;
		if (temp1 == s && temp2 == s) num4--;
	}
	if (count == 5) {
		num5++;
		if (temp1 == s && temp2 == s) num5--;
	}
	if (num4 >= 2) return true;
	else if (num5 >= 2) return true;
	else return false;
}
                  //��ͼ��ʼ��
void initializemap() {
	for (int i = 0; i < 20; i++)                 
		for (int j = 0; j < 20; j++)
			map[i][j] = '*';
}
                   //������Ϸ�Ľ���
void gamestart() {
		cout << "��ʼ����" << endl;
		cout << "��ѡ����Ϸģʽ" << endl;
		cout << "1.���˶�ս" << endl;
		cout << "2.�˻���ս" << endl;
		cout << "3.������ս" << endl;
		cout << "4.Quit" << endl;
}
                  //������ӣ�BΪ���壬WΪ����
void playchess(int x, int y, int player) {
	if (player == 1) map[x][y] = 'B';
	else map[x][y] = 'W';
}
                   //��ӡ����
void printmap() {
	cout << "     0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19" << endl;
	for (int i = 0; i < 20; i++) {
		if (i < 10) cout << "  " << i;
		else cout << " " << i;
		for (int j = 0; j < 20; j++)
			cout << "  " << map[i][j];
		cout << endl;
	}
}
        //AI����ÿһ���ĵ÷ַ���ͼ
void AIgetscore(char ch) {    //chΪ�з����ӵ�����
	int oppnum = 0, AInum = 0,blanknum= 0;
	char dh;
	if (ch == 'B') dh = 'W';
	else if (ch == 'W') dh = 'B';
	for (int i = 0; i < 20; i++)             //��AI�÷ֵ�ͼ��ʼ��
		for (int j = 0; j < 20; j++)
			scoremap[i][j] = 0;
	for (int i = 0; i < 20; i++) {       //����÷�
		for (int j = 0; j < 20; j++) {
			if (i >= 0 && j >= 0 && i <= 19 && j <= 19 && map[i][j] == '*') {  //��֤�˴���������
				for(int k=-1;k<=1;k++)
					for (int z = -1; z <= 1; z++) {   //Ѱ����Χ�˸����������
						oppnum = 0; AInum = 0; blanknum = 0;  //�Ƚ�ÿ������ĸ�������������Ϊ��
						if (!(k == 0 && z == 0)) {  //k zΪ0ʱ��Ϊ�˸�����֮һ
						 //���ݶ������������������:
							for (int s = 1; s <= 5; s++) {   //�˷����ѯ�������
								if (i + k * s >= 0 && i + k * s <= 19 &&    //��ѯ�˷������������ĵз����Ӹ���
									j + z * s >= 0 && j + z * s <= 19 &&
									map[i + k * s][j + z * s] == ch) oppnum++;   //����˷������������ĵз����Ӹ���
								else if (i + k * s >= 0 && i + k * s <= 19 &&  //��ѯ�˷���������������������λ��
									j + z * s >= 0 && j + z * s <= 19 &&
									map[i + k * s][j + z * s] == '*') {
									blanknum++;  //�˷���������λ�ü�һ
									break;   //����ѭ��
								}
								else break;   //��⵽�Լ������ӻ��ߴﵽ�߽����˳�ѭ��
							}
							for (int s = 1; s <= 5; s++) {   //�˷���ķ������ѯ�������
								if (i - k * s >= 0 && i - k * s <= 19 &&    //��ѯ�˷��򷴷������������ĵз����Ӹ���
									j - z * s >= 0 && j - z * s <= 19 &&
									map[i - k * s][j - z * s] == ch) oppnum++;   //����˷��򷴷������������ĵз����Ӹ���
								else if (i - k * s >= 0 && i - k * s <= 19 &&  //��ѯ�˷��򷴷���������������������λ��
									j - z * s >= 0 && j - z * s <= 19 &&
									map[i - k * s][j - z * s] == '*') {
									blanknum++;  //�˷��򷴷���������λ�ü�һ
									break;   //����ѭ��
								}
								else break;   //��⵽�Լ������ӻ��ߵ���߽����˳�ѭ��
							}
							if (oppnum == 1) scoremap[i][j] += 10;   //�ֵ��з�����һ��ʱ����+10
							else if (oppnum == 2) {
								if (blanknum == 1) scoremap[i][j] += 20;  //�ֵ��з���2ʱ����+20
								else scoremap[i][j] += 25;        //�ֵ��з���2ʱ����+25
							}
							else if (oppnum == 3) {
								if (blanknum == 1) scoremap[i][j] += 30;
								else scoremap[i][j] += 35;
							}
							else if (oppnum == 4) {
								if (blanknum == 1) scoremap[i][j] += 40;
								else scoremap[i][j] += 45;
							}
							else if (oppnum == 5) scoremap[i][j] += 100;
							blanknum = 0;
						//�����Լ������������������
							for (int s = 1; s <= 5; s++) {   //�˷����ѯ�������
								if (i + k * s >= 0 && i + k * s <= 19 &&    //��ѯ�˷��������������ҷ����Ӹ���
									j + z * s >= 0 && j + z * s <= 19 &&
									map[i + k * s][j + z * s] == dh) AInum++;   //����˷��������������ҷ����Ӹ���
								else if (i + k * s >= 0 && i + k * s <= 19 &&  //��ѯ�˷���������������������λ��
									j + z * s >= 0 && j + z * s <= 19 &&
									map[i + k * s][j + z * s] == '*') {
									blanknum++;  //�˷���������λ�ü�һ
									break;   //����ѭ��
								}
								else break;   //��⵽�з������ӻ��ߴﵽ�߽����˳�ѭ��
							}
							for (int s = 1; s <= 5; s++) {   //�˷���ķ������ѯ�������
								if (i - k * s >= 0 && i - k * s <= 19 &&    //��ѯ�˷��򷴷��������������ҷ����Ӹ���
									j - z * s >= 0 && j - z * s <= 19 &&
									map[i - k * s][j - z * s] == dh) AInum++;   //����˷��򷴷��������������ҷ����Ӹ���
								else if (i - k * s >= 0 && i - k * s <= 19 &&  //��ѯ�˷��򷴷���������������������λ��
									j - z * s >= 0 && j - z * s <= 19 &&
									map[i - k * s][j - z * s] == '*') {
									blanknum++;  //�˷��򷴷���������λ�ü�һ
									break;   //����ѭ��
								}
								else break;   //��⵽�з������ӻ��ߵ���߽����˳�ѭ��
							}
							if (AInum == 1) scoremap[i][j] += 10;   //
							else if (AInum == 2) {
								if (blanknum == 1) scoremap[i][j] += 20;  //
								else scoremap[i][j] += 25;        //
							}
							else if (AInum == 3) {
								if (blanknum == 1) scoremap[i][j] += 30;
								else scoremap[i][j] += 35;
							}
							else if (AInum == 4) {
								if (blanknum == 1) scoremap[i][j] += 40;
								else scoremap[i][j] += 45;
							}
							else if (AInum >= 5) scoremap[i][j] += 100;
							blanknum = 0;
						}
					}
			}
		}
	}
}
               //AI���壨�н��ֹ���
void AIplayyou() {
	AIgetscore(ch);
	char dh;
	if (ch == 'B') dh = 'W';
	else dh = 'B';
	int maxscore = 0;
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			if (scoremap[i][j] > maxscore) maxscore = scoremap[i][j];     //�õ�������ֵ
	int num = 0;             //���ֵ����
	int p[400], q[400];            //��ſɷ����ֵλ�õ�����
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			if (scoremap[i][j] == maxscore) {
				if (!jinshou(i, j, dh, ch)) {
					p[num] = i;
					q[num] = j;
					num++;
				}
			}
	int n;
	srand((unsigned)time(0));
	n = rand() % num;	                 //nΪ0��num-1������������ȡһ�������ֵ
	if (ch == 'B') map[p[n]][q[n]] = 'W';
	else map[p[n]][q[n]] = 'B';
	a2 = p[n];
	b2 = q[n];
	a = p[n];
	b = q[n];
	Sleep(2000);
	printmap();
}
           //AI���壨�޽��ֹ���
void AIplaywu() {
	AIgetscore(ch);
	int maxscore = 0;
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			if (scoremap[i][j] > maxscore) maxscore = scoremap[i][j];     //�õ�������ֵ
	int num = 0;             //���ֵ����
	int p[400], q[400];            //������ֵλ�õ�����
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			if (scoremap[i][j] == maxscore) {
				p[num] = i;
				q[num] = j;
				num++;
			}
	int n;
	srand((unsigned)time(0));
	n = rand() % num;	                 //nΪ0��num-1������������ȡһ�������ֵ
	if (ch == 'B') map[p[n]][q[n]] = 'W';
	else map[p[n]][q[n]] = 'B';
	a2 = p[n];
	b2 = q[n];
	a = p[n];
	b = q[n];
	Sleep(2000);
	printmap();
}
//AI1���壨�н��ֹ���
void AI1play() {
	AIgetscore(ch);
	char dh;
	if (ch == 'B') dh = 'W';
	else dh = 'B';
	int maxscore = 0;
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			if (scoremap[i][j] > maxscore) maxscore = scoremap[i][j];     //�õ�������ֵ
	int num = 0;             //���ֵ����
	int p[400], q[400];            //��ſɷ����ֵλ�õ�����
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			if (scoremap[i][j] == maxscore) {
				if (!jinshou(i, j, dh, ch)) {
					p[num] = i;
					q[num] = j;
					num++;
				}
			}
	int n;
	srand((unsigned)time(0));
	n = rand() % num;	                 //nΪ0��num-1������������ȡһ�������ֵ
	if (ch == 'B') map[p[n]][q[n]] = 'W';
	else map[p[n]][q[n]] = 'B';
	a = p[n];
	b = q[n];
	Sleep(2000);
	printmap();
}
//AI2���壨�޽��ֹ���
void AI2play() {
	AIgetscore(ch);
	int maxscore = 0;
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			if (scoremap[i][j] > maxscore) maxscore = scoremap[i][j];     //�õ�������ֵ
	int num = 0;             //���ֵ����
	int p[400], q[400];            //������ֵλ�õ�����
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			if (scoremap[i][j] == maxscore) {
				p[num] = i;
				q[num] = j;
				num++;
			}
	int n;
	srand((unsigned)time(0));
	n = rand() % num;	                 //nΪ0��num-1������������ȡһ�������ֵ
	if (ch == 'B') map[p[n]][q[n]] = 'W';
	else map[p[n]][q[n]] = 'B';
	a = p[n];
	b = q[n];
	Sleep(2000);
	printmap();
}
   //���˶�սģʽ
void gamemodeone() {
	int count = 1;
	bool flag1 = true, flag2 = true;
	while (1) {
		cout << "��" << count++ << "�غϣ�" << endl<< "���1������:" << endl;
		cin >> a>> b;
		if (huiqi(a, b) && flag1 && (count > 2)) {
			flag1 = false;
			map[a1][b1] = '*';
			map[a2][b2] = '*';
			printmap();
			cout << "���1����ɹ������������룺" << endl;
			cin >> a >> b;
			while (!legal(a, b)) {
				cout << "�˲��岻�Ϸ������������룺" << endl;
				cin >> a >> b;
			}
			a1= a; b1 = b;
		}
		else {
			while (!legal(a, b)) {
				cout << "�˲��岻�Ϸ������������룺" << endl;
				cin >> a >> b;
			}
			a1 = a; b1 = b;
		}
		playchess(a, b, 1);
		printmap();
		if (jinshou(a, b, 'B', 'W')) {
			cout << "���2ʤ��" << endl << "Game Over!" << endl;
			initializemap();                            //��ͼ��ʼ��
			break;
		}
		if (winorlose(a, b,'B')) {
			cout << "���1ʤ��" << endl<<"Game Over!" << endl;
			initializemap();                            //��ͼ��ʼ��
			break;
		}
		cout << "���2�����壺" << endl;
		cin >> a >> b;
		if (huiqi(a, b)&&flag2&&(count>2)) {
			flag2 = false;
			map[a1][b1] = '*';
			map[a2][b2] = '*';
			printmap();
			cout << "���2����ɹ������������룺" << endl;
			cin >> a >> b;
			while (!legal(a, b)) {
				cout << "�˲��岻�Ϸ������������룺" << endl;
				cin >> a >> b;
			}
			a2 = a; b2 = b;
		}
		else {
			while (!legal(a, b)) {
				cout << "�˲��岻�Ϸ������������룺" << endl;
				cin >> a >> b;
			}
			a2 =a; b2 = b;
		}
		playchess(a, b, 2);
		printmap();
		if (winorlose(a, b,'W')) {
			cout << "���2ʤ��" << endl << "Game Over!" << endl;
			initializemap();                            //��ͼ��ʼ��
			break;
		}
		if (heqi()) {
			cout << "����" << endl;
			initializemap();                            //��ͼ��ʼ��
			break;
		}
	}
}
     //�˻���սģʽ
void gamemodetwo() {
	int count,c;
	bool flag = true;
	cout << "1.����" << endl << "2.����" << endl;
	cin >> c;
	if (c == 1) {
		count = 1;
		while (1) {
			cout << "��" << count++ << "�غϣ�" << endl << "���������:" << endl;
			cin >> a >> b;
			if (huiqi(a, b) && flag && (count > 2)) {
				flag = false;
				map[a1][b1] = '*';
				map[a2][b2] = '*';
				printmap();
				cout << "��һ���ɹ������������룺" << endl;
				cin >> a >> b;
				while (!legal(a, b)) {
					cout << "�˲��岻�Ϸ������������룺" << endl;
					cin >> a >> b;
				}
				a1 = a; b1 = b;
			}
			else {
				while (!legal(a, b)) {
					cout << "�˲��岻�Ϸ������������룺" << endl;
					cin >> a >> b;
				}
				a1 = a; b1 = b;
			}
			playchess(a, b, 1);
			ch = 'B';
			printmap();
			if (jinshou(a, b, 'B', 'W')) {
				cout << "����ʤ��" << endl << "Game Over!" << endl;
				initializemap();                            //��ͼ��ʼ��
				break;
			}
			if (winorlose(a, b,'B')) {
				cout << "���ʤ��" << endl << "Game Over!" << endl;
				initializemap();                            //��ͼ��ʼ��
				break;
			}
			cout << "�������壺" << endl;
			AIplaywu();
			if (winorlose(a, b,'W')) {
				cout << "����ʤ��" << endl << "Game Over!" << endl;
				initializemap();                            //��ͼ��ʼ��
				break;
			}
			if (heqi()) {
				cout << "����" << endl;
				initializemap();                            //��ͼ��ʼ��
				break;
			}
		}
	}
	if (c == 2) {
		count = 1;
		while (1) {
			cout << "��" << count++ << "�غϣ�" << endl << "��������:" << endl;
			ch = 'W';
			AIplayyou();
			if (winorlose(a, b,'B')) {
				cout << "����ʤ��" << endl << "Game Over!" << endl;
				initializemap();                            //��ͼ��ʼ��
				break;
			}
			cout << "��������壺" << endl;
			cin >> a >> b;
			if (huiqi(a, b) && flag && (count > 2)) {
				flag = false;
				map[a1][b1] = '*';
				map[a2][b2] = '*';
				printmap();
				cout << "��һ���ɹ������������룺" << endl;
				cin >> a >> b;
				while (!legal(a, b)) {
					cout << "�˲��岻�Ϸ������������룺" << endl;
					cin >> a >> b;
				}
				a1 = a; b1 = b;
			}
			else {
				while (!legal(a, b)) {
					cout << "�˲��岻�Ϸ������������룺" << endl;
					cin >> a >> b;
				}
				a1 = a; b1 = b;
			}
			playchess(a, b, 2);
			printmap();
			if (winorlose(a, b,'W')) {
				cout << "���ʤ��" << endl << "Game Over!" << endl;
				initializemap();                            //��ͼ��ʼ��
				break;
			}
			if (heqi()) {
				cout << "����" << endl;
				initializemap();                            //��ͼ��ʼ��
				break;
			}
		}
	}
}
        //������սģʽ
void gamemodethree() {
	int count = 1;
	while (1) {
		cout << "��" << count++ << "�غ�:" << endl << "����1���壺" << endl;
		ch = 'W';
		AI1play();
		if (winorlose(a, b,'B')) {
			cout << "����1ʤ��" << endl << "Game Over!" << endl;
			initializemap();                            //��ͼ��ʼ��
			break;
		}
		cout << "����2���壺" << endl;
		ch = 'B';
		AI2play();
		if (winorlose(a, b,'W')) {
			cout << "����2ʤ��" << endl << "Game Over!" << endl;
			initializemap();                            //��ͼ��ʼ��
			break;
		}
		if (heqi()) {
			cout << "����" << endl;
			initializemap();                            //��ͼ��ʼ��
			break;
		}
	}
}
int main() {
	initializemap();                            //��ͼ��ʼ��
	gamestart();                                //������Ϸ
	while (cin >> order) {
		if (order == 1) gamemodeone();
		if (order == 2) gamemodetwo();
		if (order == 3) gamemodethree();
		if (order == 4) {
			cout << "��л���Ĳ��룬���ٽ�������߾���ˮƽ��" << endl;
				break;
		}
		return 0;
	}
}