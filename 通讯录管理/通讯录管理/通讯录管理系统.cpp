#include <iostream>	
#include <string>
#define max 1000  //�������
using namespace std;
//�����ϵ�˽ṹ��
struct person
{
	//����
	string m_name;

	//�Ա�     1.��  2.Ů
	int m_sex;
	//����
	int m_age;

	//�绰
	string m_phone;

	//סַ
	string m_address;

};


//���ͨѶ¼�ṹ��
struct addressbooks
{
	//ͨѶ¼�б������ϵ������

	struct person personarry[max];

	//ͨѶ¼�е�ǰ��¼��ϵ�˸���
	int m_size;

};

//1�������ϵ��
void addperson(addressbooks * abs)
{
	//�ж�ͨѶ¼�Ƿ����������������
	if (abs->m_size == max)
	{
		cout << "ͨѶ¼�������޷�������ӣ�" << endl;
		return;
	}
	else
	{
		//��Ӿ�����ϵ��
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personarry[abs->m_size].m_name = name;
		

		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			//�������1��2�����˳�ѭ����������������
			if (sex == 1 || sex == 2)
			{
				abs->personarry[abs->m_size].m_sex = sex;
				break;
			}
			cout << "�����������������룡" << endl;
		}
		

		//����
		cout << "���������䣺" << endl;
		
		int age = 0;
		while (true)
		{
			cin >> age;
			//�������1��2�����˳�ѭ����������������
			if (0 < age&&age < 200)
			{
				abs->personarry[abs->m_size].m_age = age;
				break;
			}
			cout << "�����������������룡" << endl;
		}

		//�绰
		cout << "������绰��" << endl;
		string phone;
		cin >> phone;
		abs->personarry[abs->m_size].m_phone = phone;
		//סַ
		cout << "������סַ��" << endl;
		string address;
		cin >> address;
		abs->personarry[abs->m_size].m_address = address;
		//��������
		abs->m_size++;
		cout << "��ӳɹ���" << endl;
		system("pause");//�밴���������

		system("cls");//����
	}
}
//2����ʾ��ϵ��
void showperson(addressbooks * abs)
{
	//�ж�ͨѶ¼�������Ƿ�Ϊ0��������򷵻ؿ�
	if (abs->m_size == 0)
	{
		cout << "��ǰ��¼��ϵ��Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "������ " << abs->personarry[i].m_name << "\t";
			cout << "�Ա� " << (abs->personarry[i].m_sex == 1?"��":"Ů" )<< "\t";
			cout << "���䣺 " << abs->personarry[i].m_age << "\t";
			cout << "�绰�� " << abs->personarry[i].m_phone << "\t";
			cout << "סַ�� " << abs->personarry[i].m_address << endl;
		}

	}
	system("pause");//�밴���������

	system("cls");//����
}

//�����ϵ���Ƿ���ڣ������ڷ��ؾ���λ�ã����򷵻�-1
int isexit(addressbooks * abs, string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		//�ҵ�
		if (abs->personarry[i].m_name == name)
		{
			return i;

		}

	}
	return -1;
}

//3��ɾ��ָ����ϵ��
void deleteperson(addressbooks * abs)
{

	cout << "������Ҫɾ������ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	//ret == -1,���޴���
	//ret != -1,�ҵ�
	int ret = isexit(abs, name);
	if (ret != -1)
	{
		//�鵽�����ɾ��
		for (int i = ret; i < abs->m_size; i++)
		{
			//����ǰ��
			abs->personarry[i] = abs->personarry[i++];

		}
		abs->m_size--;//��������
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");//�밴���������

	system("cls");//����
}

//4��������ϵ��
void findperson(addressbooks *abs)
{
	cout << "������Ҫ���ҵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	//ret == -1,���޴���
	//ret != -1,�ҵ�
	int ret = isexit(abs, name);
	if (ret != -1)//�ҵ�
	{
		cout << "������ " << abs->personarry[ret].m_name << "\t";
		cout << "�Ա� " << (abs->personarry[ret].m_sex == 1 ? "��" : "Ů") << "\t";
		cout << "���䣺 " << abs->personarry[ret].m_age << "\t";
		cout << "�绰�� " << abs->personarry[ret].m_phone << "\t";
		cout << "סַ�� " << abs->personarry[ret].m_address << endl;
	}
	else
	{
		cout << "���޴���" << endl;

	}
	system("pause");//�밴���������

	system("cls");//����
}

//5���޸��ƶ���ϵ��
void modifyperson(addressbooks *abs)
{
	cout << "������Ҫ�޸ĵ���ϵ�ˣ�" << endl;
	string name;
	cin >> name;
	//ret == -1,���޴���
	//ret != -1,�ҵ�
	int ret = isexit(abs, name);
	if (ret != -1)//�ҵ�
	{
		//����
		string name;
		cout << "������������ " << endl;
		cin >> name;
		abs->personarry[ret].m_name = name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			//�������1��2�����˳�ѭ����������������
			if (sex == 1 || sex == 2)
			{
				abs->personarry[ret].m_sex = sex;
				break;
			}
			cout << "�����������������룡" << endl;
		}


		//����
		cout << "���������䣺" << endl;

		int age = 0;
		while (true)
		{
			cin >> age;
			//�������1��2�����˳�ѭ����������������
			if (0 < age&&age < 200)
			{
				abs->personarry[ret].m_age = age;
				break;
			}
			cout << "�����������������룡" << endl;
		}

		//�绰
		cout << "������绰��" << endl;
		string phone;
		cin >> phone;
		abs->personarry[ret].m_phone = phone;
		//סַ
		cout << "������סַ��" << endl;
		string address;
		cin >> address;
		abs->personarry[ret].m_address = address;
		
		cout << "�޸ĳɹ���" << endl;

	}
	else
	{
		cout << "���޴���" << endl;

	}
	system("pause");//�밴���������

	system("cls");//����
}

//6�����ͨѶ¼
void cleanperson(addressbooks *abs)
{
	abs->m_size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}

//�˵�����
void showmenu()
{
	cout << "*****************************" << endl;
	cout << "*****   1�������ϵ��   *****" << endl;
	cout << "*****   2����ʾ��ϵ��   *****" << endl;
	cout << "*****   3��ɾ����ϵ��   *****" << endl;
	cout << "*****   4��������ϵ��   *****" << endl;
	cout << "*****   5���޸���ϵ��   *****" << endl;
	cout << "*****   6�������ϵ��   *****" << endl;
	cout << "*****   0���˳�ͨѶ¼   *****" << endl;
	cout << "*****************************" << endl;
}

int main()
{
	//�����ṹ�����
	addressbooks abs;
	//��ʼ����Ա����
	abs.m_size = 0;

	int select = 0;
	while (true)
	{
		//�˵�����
		showmenu();
		cin >> select;
		switch (select)
		{
		case 1:    //1�������ϵ��
			addperson(&abs);
			break;
		case 2:    //2����ʾ��ϵ��
			showperson(&abs);
			break;
		case 3:    //3��ɾ����ϵ��
			deleteperson(&abs);
			break;
		case 4:    //4��������ϵ��
			findperson(&abs);
			break;
		case 5:    //5���޸���ϵ��
			modifyperson(&abs);
			break;
		case 6:    //6�������ϵ��
			cleanperson(&abs);
			break;
		case 0:    //0���˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}


	}

	
	system("pause");
	return 0;

}