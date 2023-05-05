# include <math.h>
# include <iostream>
# include <algorithm>
# include <string>
# include <stack>
using namespace std;
bool CheckOperator(char c);             //�ж��Ƿ�Ϊ�����
bool CheckMatch(string str);            //�ж���ʽ�Ƿ���ȷ
int Prior(char c);                      //����ŵ����ȼ�
bool CheckPrior(char c1, char c2);      //ͨ�����ȼ��ж��Ƿ���ջ
float CalNum(float a, float b, char c); //��������Ľ��
float CalResult(string str);            //�������ս��
int main()
{
	string str;
	cout << "���������ʽ:";
	cin >> str;
	str.append("#");           //��Ϊ��ʽ����ֹ��
	bool t = CheckMatch(str);  //�ж���ʽ�Ƿ���ȷ
	if (t) {
		float r = CalResult(str);  //�������ս��
		cout << "������Ϊ:" << r << endl;
	}
	return 0;
}
 
bool CheckOperator(char c)   //�ж��Ƿ�Ϊ�����
{
	if (c == '+' || c == '-' || c == '*' || c == '/') {
		return true;
	}
	else {
		return false;
	}
}
 
bool CheckMatch(string str)  //�ж���ʽ�Ƿ���ȷ
{
	if (CheckOperator(str[0]) || CheckOperator(str[str.length() - 2])) {
		//��ʽ��βλ�ó��������
		cout << "��ʽ����\n" << "ԭ��ȱ�������������" << endl;
		return false;
	}
	//�ж����ż�����������Ƿ���ȷ
	stack<char>S;   //���ڴ�����ŵ�ջ
	for (int i = 0; i < str.length() - 1; i++) {
		if (!CheckOperator(str[i]) && (str[i] < 48 || str[i]>57) && str[i] != '(' && str[i] != ')' && str[i] != '.') {
			//���ַǷ��ַ�
			cout << "��ʽ����\n" << "ԭ�򣺳��ַǷ��ַ�" << str[i] << endl;
			return false;
		}
		if (CheckOperator(str[i]) && CheckOperator(str[i + 1])) {
			//������ظ�
			cout << "��ʽ����\n" << "ԭ�������" << str[i] << "�ظ�" << endl;
			return false;
		}
		if (str[i] == '(')
		{
			S.push(str[i]);
			if (CheckOperator(str[i + 1])) {
				//'('��ȱ�������������
				cout << "��ʽ����\n" << "ԭ��ȱ�������������" << endl;
				return false;
			}
		}
		if (str[i] == ')')
		{
			if (S.empty()) {
				//��ջ��Ϊ�գ�˵����©������
				cout << "��ʽ����\n" << "ԭ����©������" << endl;
				return false;
			}
			S.pop();
		}
	}
	if (!S.empty()) {
		//����ʱջ����Ϊ�գ�˵����©������
		cout << "��ʽ����\n" << "ԭ����©������" << endl;
		return false;
	}
	return true;
}
 
int Prior(char c)    //���ط��ŵ����ȼ�
{
	switch (c)
	{
	case '#': return 0;
	case '+':
	case '-': return 1;
	case '*':
	case '/': return 2;
	case ')': return 3;
	case '(': return 4;
	}
}
 
bool CheckPrior(char c1, char c2) //ͨ�����ȼ��ж��Ƿ���ջ��c1��ǰ��c2ջ�У�
{
	if (c2 == '(') {
		return true;  //ͬ���ջ
	}
	int p1 = Prior(c1);
	int p2 = Prior(c2);
	if (p1 > p2) {   //��ǰ����������ȼ��ϸ�
		return true; //ͬ���ջ
	}
	else {
		return false; //��ͬ���ջ
	}
}
 
float CalNum(float a, float b, char c) //��������Ľ��
{
	switch (c)
	{
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': return a / b;
	}
}
 
float CalResult(string str) //�������ս��
{
	stack<float>Num;  //������������ջ
	stack<char>Sign;  //�����������ջ
	Sign.push('#');
	float a, b;
	for (int i = 0; i < str.length() && !Sign.empty(); i++) {
		if (str[i] >= 48 && str[i] <= 57) {
			//��Ϊ����
			a = float(str[i]) - 48;           //a�������ַ�ת��Ϊ���ֺ��ֵ
			int j;
			//���ַ�ת��Ϊ����
			for (j = i + 1; (str[j] == '.') || (j < str.length() && str[j] >= 48 && str[j] <= 57); j++) {
				if (str[j] == '.') {
					//��ΪС��
					int k, l;
					for (k = j + 1, l = 1; k < str.length() && str[k] >= 48 && str[k] <= 57; k++, l++) {
						b = float(str[k]) - 48;
						a = a + b * pow(10, -l);
					}
					j = k;
					break;
				}
				else {
					b = float(str[j]) - 48;
					a = a * 10 + b;
				}
			}
			i = j - 1;
			Num.push(a);  //��������ջ
		}
		else {
			//��Ϊ�����
			char c1 = str[i];  //c1��ǰ�����
			while (1) {
				char c2 = Sign.top();             //c2ջ�������
				if (c2 == '#' && str[i] == '#') { //��������ʼ��������strҲ����ĩβ
					Sign.pop();
					break;
				}
				bool t = CheckPrior(c1, c2);     //ͨ�����ȼ��ж��Ƿ���ջ��c1��ǰ��c2ջ�У�
				if (t) {
					//ͬ���������ջ
					int s = Prior(str[i]);
					if (s == 3) {
						//����')'�����Ƚ��������ڵ�����
						while ((c2 = Sign.top()) != '(') {
							a = Num.top();  //ȡ����һ����
							Num.pop();
							b = Num.top();  //ȡ���ڶ�����
							Num.pop();
							float r = CalNum(b, a, c2);  //��������Ľ��
							Sign.pop();
							Num.push(r);    //����õ���������ջ
						}
						Sign.pop();
					}
					else {
						Sign.push(c1); //�������ջ
					}
					break;
				}
				else {
					//��ͬ���������ջ��ִ���������
					a = Num.top();
					Num.pop();
					b = Num.top();
					Num.pop();
					float r = CalNum(b, a, c2); //��������Ľ��
					Sign.pop();
					Num.push(r);
				}
			}
		}
	}
	return Num.top();

}
