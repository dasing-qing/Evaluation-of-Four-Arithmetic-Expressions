/* ������Ϊ����������ʽ��ֵϵͳ�����ڼ����С���ŵ�����������ʽ��ֵ�������㷨��
�Ƚ��ַ�������ɲ�����Ԫ�������������������������ջ������������
�����㷨����м��㣬���ó������*/

#include<iostream>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
const int Expmax_length = 1001;//���ʽ��󳤶ȣ��ɸ����ʵ�������� 
using namespace std;
struct Ope_unit
{//���������Ԫ 
	int    flag;//=1��ʾ�ǲ����� =0��ʾ�ǲ����� -1��ʾ���ŵ�Ԫ 
	char   oper;//������ 
	double real;//��������Ϊ˫���ȸ����� 
};
void Display();//�˵�
void Instru(); //ʹ��˵�� 
int Check(char Exp_arry[]);
void Evalua(); //�ȵ���Conver������Ԫ�����ٵ���Calculate��������������� 
int  Conver(struct Ope_unit Opeunit_arry[], char Exp_arry[]);//���ַ�������ɲ�����Ԫ 
int  Isoper(char ch);//�жϺϷ��ַ���+ - * / ( ) =��
int  Ope_Compar(char ope1, char ope2);//�������������ȼ��Ƚ� 
double Calculate(struct Ope_unit Opeunit_arry[], int Opeunit_count, int& flag);//��ջ������ʽ��� 
double Four_arithm(double x, double y, char oper);//�������� 

int main()
{
	int select;
	while (1)
	{
		Display();
		cout<<"��������ִ�й��ܶ�Ӧ������:";
		cin >> select;
		switch (select)
		{
		case   1: Evalua(); break;
		case   2: Instru(); break;
		case   0: return 0;
		default:cout << "�޸����ֶ�Ӧ�Ĺ��ܣ�����������";
			system("pause");
		}
	}
	return 0;
}

int Check(char Exp_arry[])
{//����Ƿ��зǷ��ַ�������1��ʾ���Ϸ���0��ʾ�Ϸ� 
	int Explength = strlen(Exp_arry), i;
	for (i = 0; i < Explength; i++)
	{
		if (!Isoper(Exp_arry[i]) && Exp_arry[i] != '.' && !isdigit(Exp_arry[i]))
			return 1;
		if (isdigit(Exp_arry[i]))
		{
			int Dig_number = 0, Cur_positoin = i + 1;
			while (isdigit(Exp_arry[Cur_positoin]) || Exp_arry[Cur_positoin] == '.')
			{
				Dig_number++;
				Cur_positoin++;
			}
			if (Dig_number >= 16)//����ܹ�����15λ��Ч���� 
				return 1;
		}
	}
	return 0;
}

int Evalua()
{//�ȵ���Conver�������ַ���������Ԫ�����ٵ���Calculate��������������� 
	char Exp_arry[Expmax_length];
	int flag = 0;//����տ�ʼ���Ϸ���1���ʽ�Ϸ���0���Ϸ� 
	struct Ope_unit Opeunit_arry[Expmax_length];
	getchar();//�Ե�һ�����з� 
	cout << "����������������ʽ����=��β��";
	gets_s(Exp_arry);
	flag = Check(Exp_arry);
	if (flag)
		cout << "�ñ��ʽ���Ϸ���";
	else
	{
		int Opeunit_count = Conver(Opeunit_arry, Exp_arry);
		double        ans = Calculate(Opeunit_arry, Opeunit_count, flag);
		if (flag)
		{
			cout << "������Ϊ��" << Exp_arry, ans;
		}
		else
			cout << "�ñ��ʽ���Ϸ���";
	}
	system("pause");
}

int  Conver(struct Ope_unit Opeunit_arry[], char Exp_arry[])
{//���ַ���������Ԫ�� 
	int Explength = strlen(Exp_arry);
	int i, Opeunit_count = 0;
	for (i = 0; i < Explength; i++)
	{
		if (Isoper(Exp_arry[i]))//�ǲ����� 
		{
			Opeunit_arry[Opeunit_count].flag = 0;
			Opeunit_arry[Opeunit_count++].oper = Exp_arry[i];
		}
		else//�ǲ����� 
		{
			Opeunit_arry[Opeunit_count].flag = 1;
			char temp[Expmax_length];
			int k = 0;
			for (; isdigit(Exp_arry[i]) || Exp_arry[i] == '.'; i++)
			{
				temp[k++] = Exp_arry[i];
			}
			i--;
			temp[k] = '\0';
			Opeunit_arry[Opeunit_count].real = atof(temp);//���ַ�ת��Ϊ������

			//���� 
			if (Opeunit_count == 1 && Opeunit_arry[Opeunit_count - 1].flag == 0
				&& Opeunit_arry[Opeunit_count - 1].oper == '-')
			{
				Opeunit_arry[Opeunit_count - 1].flag = -1;
				Opeunit_arry[Opeunit_count].real *= -1;
			}// -9 
			if (Opeunit_count >= 2 && Opeunit_arry[Opeunit_count - 1].flag == 0
				&& Opeunit_arry[Opeunit_count - 1].oper == '-' && Opeunit_arry[Opeunit_count - 2].flag == 0
				&& Opeunit_arry[Opeunit_count - 2].oper != ')')
			{
				Opeunit_arry[Opeunit_count - 1].flag = -1;
				Opeunit_arry[Opeunit_count].real *= -1;
			}// )-9

			//���� 
			if (Opeunit_count == 1 && Opeunit_arry[Opeunit_count - 1].flag == 0
				&& Opeunit_arry[Opeunit_count - 1].oper == '+')
			{
				Opeunit_arry[Opeunit_count - 1].flag = -1;
			}// +9 
			if (Opeunit_count >= 2 && Opeunit_arry[Opeunit_count - 1].flag == 0
				&& Opeunit_arry[Opeunit_count - 1].oper == '+' && Opeunit_arry[Opeunit_count - 2].flag == 0
				&& Opeunit_arry[Opeunit_count - 2].oper != ')')
			{
				Opeunit_arry[Opeunit_count - 1].flag = -1;
			}// )+9
			Opeunit_count++;
		}
	}
	/*for(i=0;i<Opeunit_count;i++)
	{//�鿴��������Ԫ�Ƿ���ȷ,1�ǲ�������0�ǲ�����
		if(Opeunit_arry[i].flag == 1)
		cout<<"�õ�Ԫ�ǲ�����Ϊ��"<<Opeunit_arry[i].real;
		else if(Opeunit_arry[i].flag == 0)
		cout<<"�õ�Ԫ�ǲ�����Ϊ��"<<Opeunit_arry[i].oper;
		else
		cout<<"�õ�Ԫ�Ǹ��ŷ�Ϊ��"<<Opeunit_arry[i].oper;
	}*/
	return Opeunit_count;
}

double Calculate(struct Ope_unit Opeunit_arry[], int Opeunit_count, int& flag)
{//���������������ջ���м��� 
	int i, dS_pointer = 0, oS_pointer = 0;//dS_pointerΪ������ջ��ָʾ����oS_pointerΪ������ջ��ָʾ�� 
	double Dig_stack[Expmax_length];//������ջ��˳��洢�ṹ�� 
	char   Ope_stack[Expmax_length];//������ջ 

	for (i = 0; i < Opeunit_count - 1; i++)
	{
		if (Opeunit_arry[i].flag != -1)
		{
			if (Opeunit_arry[i].flag)//�ǲ����� 
			{
				Dig_stack[dS_pointer++] = Opeunit_arry[i].real;//�������ջ 
				//cout<<Digit[dS_pointer-1];
			}
			else//�ǲ����� + - * / ( ) 
			{
				//������ջΪ�ջ��������� ��ջ
				if (oS_pointer == 0 || Opeunit_arry[i].oper == '(')
				{
					Ope_stack[oS_pointer++] = Opeunit_arry[i].oper;
				}
				else
				{
					if (Opeunit_arry[i].oper == ')')//�������Ž������һֱ��ջ��ֱ������������ 
					{
						oS_pointer--;//ָ��ջ�� 
						dS_pointer--;//ָ��ջ�� 
						while (Ope_stack[oS_pointer] != '(' && oS_pointer != 0)
						{
							Dig_stack[dS_pointer - 1] = Four_arithm(Dig_stack[dS_pointer - 1], Dig_stack[dS_pointer],
								Ope_stack[oS_pointer--]);//oS_pointer--Ϊ��������ջ     						
							dS_pointer--;//ǰһ����������ջ 
							//cout<<"������ջ��Ԫ�ص���:"<<Digit[dS_pointer];
						}
						oS_pointer--;//�����ų�ջ    					 
						oS_pointer++;//�ָ�ָ��ջ��֮�� 
						dS_pointer++;
					}
					else if (Ope_Compar(Opeunit_arry[i].oper, Ope_stack[oS_pointer - 1]))//��ջ��Ԫ�رȽ� 
					{
						Ope_stack[oS_pointer++] = Opeunit_arry[i].oper;;
					}
					else//�������ջ���ٽ��ò�������ջ 
					{
						oS_pointer--;//ָ��ջ�� 
						dS_pointer--;//ָ��ջ��
						while (Ope_Compar(Opeunit_arry[i].oper, Ope_stack[oS_pointer]) == 0 && oS_pointer != -1)
						{//��ǰ��������ջ�����������ȼ��� 
							Dig_stack[dS_pointer - 1] = Four_arithm(Dig_stack[dS_pointer - 1], Dig_stack[dS_pointer],
								Ope_stack[oS_pointer--]);
							dS_pointer--;
							//cout<<"������ջ��Ԫ�ص���:"<<Digit[dS_pointer];
						}
						oS_pointer++;//�ָ�ָ��ջ��֮��  
						dS_pointer++;
						Ope_stack[oS_pointer++] = Opeunit_arry[i].oper;
					}
				}
			}
		}
	}
	oS_pointer--;//ָ��ջ��Ԫ�� 
	dS_pointer--;//ָ��ջ��Ԫ�� 
	while (oS_pointer != -1)
	{
		Dig_stack[dS_pointer - 1] = Four_arithm(Dig_stack[dS_pointer - 1], Dig_stack[dS_pointer],
			Ope_stack[oS_pointer--]);//oS_pointer--Ϊ��������ջ 
		dS_pointer--;//ǰһ����������ջ 
		//cout<<"������ջ��Ԫ��Ϊ:"<<Digit[dS_pointer];
	}
	if (oS_pointer == -1 && dS_pointer == 0)
		flag = 1;//Ϊ1��ʾ���ʽ�Ϸ� 
	return Dig_stack[0];
}
int  Ope_Compar(char ope1, char ope2)
{//�������������ȼ��Ƚ�
	char list[] = { "(+-*/" };
	int map[5][5] = {//���к��У��б��е����㼶���ȼ���Ϊ0����Ϊ1 
	//        ( + - * /    
		/*  (  */ 1,0,0,0,0,
		/*  +  */ 1,0,0,0,0,
		/*  -  */ 1,0,0,0,0,
		/*  *  */ 1,1,1,0,0,
		/*  /  */ 1,1,1,0,0 };
	int i, j;
	for (i = 0; i < 5; i++)
		if (ope1 == list[i]) break;
	for (j = 0; j < 5; j++)
		if (ope2 == list[j]) break;
	return map[i][j];
}

double Four_arithm(double x, double y, char oper)
{//�������� 
	switch (oper)//��֤������������� 
	{
	case '+': return x + y;
	case '-': return x - y;
	case '*': return x * y;
	case '/': return x / y;//y����Ϊ0 
	default: return 0;
	}
}

int  Isoper(char ch)
{//�жϺϷ��ַ�  + - * / ( ) =
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' || ch == ')' || ch == '=')
		return 1;
	return 0;
}

void Display()
{//��ӡ�˵� 
	system("cls");
	cout << "******************************************************************************" << '/n';
	cout << "��ӭʹ�ñ�����������ʽ��ֵϵͳ" << "\n";
	cout << "˵����������Ӧ�����ֽ��в���" << '\n';
	cout << "����������ʽ��ֵ" << '\n';
	cout << "ʹ��˵��" << '\n';
	cout << "�˳�" << '\n';
	cout << "******************************************************************************";
}

void Instru()
{//��ӡʹ��˵�� 
	FILE* fp;
	char ch;
	if ((fp = fopen("ʹ��˵��.txt", "r")) == NULL)
	{
		cout << "�ļ���ʧ�ܣ�";
		exit(0);
	}
	for (; (ch = fgetc(fp)) != EOF; )
		putchar(ch);
	fclose(fp);
	system("pause");
}