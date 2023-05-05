# include <math.h>
# include <iostream>
# include <algorithm>
# include <string>
# include <stack>
using namespace std;
bool CheckOperator(char c);             //判断是否为运算符
bool CheckMatch(string str);            //判断算式是否正确
int Prior(char c);                      //求符号的优先级
bool CheckPrior(char c1, char c2);      //通过优先级判断是否入栈
float CalNum(float a, float b, char c); //求单项运算的结果
float CalResult(string str);            //计算最终结果
int main()
{
	string str;
	cout << "请输入计算式:";
	cin >> str;
	str.append("#");           //作为算式的终止符
	bool t = CheckMatch(str);  //判断算式是否正确
	if (t) {
		float r = CalResult(str);  //计算最终结果
		cout << "计算结果为:" << r << endl;
	}
	return 0;
}
 
bool CheckOperator(char c)   //判断是否为运算符
{
	if (c == '+' || c == '-' || c == '*' || c == '/') {
		return true;
	}
	else {
		return false;
	}
}
 
bool CheckMatch(string str)  //判断算式是否正确
{
	if (CheckOperator(str[0]) || CheckOperator(str[str.length() - 2])) {
		//算式首尾位置出现运算符
		cout << "算式错误！\n" << "原因：缺少用于运算的数" << endl;
		return false;
	}
	//判断括号及运算符输入是否正确
	stack<char>S;   //用于存放括号的栈
	for (int i = 0; i < str.length() - 1; i++) {
		if (!CheckOperator(str[i]) && (str[i] < 48 || str[i]>57) && str[i] != '(' && str[i] != ')' && str[i] != '.') {
			//出现非法字符
			cout << "算式错误！\n" << "原因：出现非法字符" << str[i] << endl;
			return false;
		}
		if (CheckOperator(str[i]) && CheckOperator(str[i + 1])) {
			//运算符重复
			cout << "算式错误！\n" << "原因：运算符" << str[i] << "重复" << endl;
			return false;
		}
		if (str[i] == '(')
		{
			S.push(str[i]);
			if (CheckOperator(str[i + 1])) {
				//'('后缺少用于运算的数
				cout << "算式错误！\n" << "原因：缺少用于运算的数" << endl;
				return false;
			}
		}
		if (str[i] == ')')
		{
			if (S.empty()) {
				//若栈已为空，说明遗漏左括号
				cout << "算式错误！\n" << "原因：遗漏左括号" << endl;
				return false;
			}
			S.pop();
		}
	}
	if (!S.empty()) {
		//若此时栈还不为空，说明遗漏右括号
		cout << "算式错误！\n" << "原因：遗漏右括号" << endl;
		return false;
	}
	return true;
}
 
int Prior(char c)    //返回符号的优先级
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
 
bool CheckPrior(char c1, char c2) //通过优先级判断是否入栈（c1当前，c2栈中）
{
	if (c2 == '(') {
		return true;  //同意进栈
	}
	int p1 = Prior(c1);
	int p2 = Prior(c2);
	if (p1 > p2) {   //当前运算符的优先级较高
		return true; //同意进栈
	}
	else {
		return false; //不同意进栈
	}
}
 
float CalNum(float a, float b, char c) //求单项运算的结果
{
	switch (c)
	{
	case '+': return a + b;
	case '-': return a - b;
	case '*': return a * b;
	case '/': return a / b;
	}
}
 
float CalResult(string str) //计算最终结果
{
	stack<float>Num;  //保存运算数的栈
	stack<char>Sign;  //保存运算符的栈
	Sign.push('#');
	float a, b;
	for (int i = 0; i < str.length() && !Sign.empty(); i++) {
		if (str[i] >= 48 && str[i] <= 57) {
			//若为数字
			a = float(str[i]) - 48;           //a保存由字符转化为数字后的值
			int j;
			//将字符转化为数字
			for (j = i + 1; (str[j] == '.') || (j < str.length() && str[j] >= 48 && str[j] <= 57); j++) {
				if (str[j] == '.') {
					//若为小数
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
			Num.push(a);  //运算数进栈
		}
		else {
			//若为运算符
			char c1 = str[i];  //c1当前运算符
			while (1) {
				char c2 = Sign.top();             //c2栈顶运算符
				if (c2 == '#' && str[i] == '#') { //若遇到起始符，并且str也到达末尾
					Sign.pop();
					break;
				}
				bool t = CheckPrior(c1, c2);     //通过优先级判断是否入栈（c1当前，c2栈中）
				if (t) {
					//同意运算符进栈
					int s = Prior(str[i]);
					if (s == 3) {
						//出现')'，优先进行括号内的运算
						while ((c2 = Sign.top()) != '(') {
							a = Num.top();  //取出第一个数
							Num.pop();
							b = Num.top();  //取出第二个数
							Num.pop();
							float r = CalNum(b, a, c2);  //求单项运算的结果
							Sign.pop();
							Num.push(r);    //运算得到的新数进栈
						}
						Sign.pop();
					}
					else {
						Sign.push(c1); //运算符进栈
					}
					break;
				}
				else {
					//不同意运算符进栈，执行运算操作
					a = Num.top();
					Num.pop();
					b = Num.top();
					Num.pop();
					float r = CalNum(b, a, c2); //求单项运算的结果
					Sign.pop();
					Num.push(r);
				}
			}
		}
	}
	return Num.top();

}
