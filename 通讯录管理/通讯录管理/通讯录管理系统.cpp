#include <iostream>	
#include <string>
#define max 1000  //最大人数
using namespace std;
//设计联系人结构体
struct person
{
	//姓名
	string m_name;

	//性别     1.男  2.女
	int m_sex;
	//年龄
	int m_age;

	//电话
	string m_phone;

	//住址
	string m_address;

};


//设计通讯录结构体
struct addressbooks
{
	//通讯录中保存的联系人数组

	struct person personarry[max];

	//通讯录中当前记录联系人个数
	int m_size;

};

//1、添加联系人
void addperson(addressbooks * abs)
{
	//判断通讯录是否满，已满则不再添加
	if (abs->m_size == max)
	{
		cout << "通讯录已满，无法继续添加！" << endl;
		return;
	}
	else
	{
		//添加具体联系人
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personarry[abs->m_size].m_name = name;
		

		//性别
		cout << "请输入性别：" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			//如果输入1或2，则退出循环，否则重新输入
			if (sex == 1 || sex == 2)
			{
				abs->personarry[abs->m_size].m_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}
		

		//年龄
		cout << "请输入年龄：" << endl;
		
		int age = 0;
		while (true)
		{
			cin >> age;
			//如果输入1或2，则退出循环，否则重新输入
			if (0 < age&&age < 200)
			{
				abs->personarry[abs->m_size].m_age = age;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}

		//电话
		cout << "请输入电话：" << endl;
		string phone;
		cin >> phone;
		abs->personarry[abs->m_size].m_phone = phone;
		//住址
		cout << "请输入住址：" << endl;
		string address;
		cin >> address;
		abs->personarry[abs->m_size].m_address = address;
		//更新人数
		abs->m_size++;
		cout << "添加成功！" << endl;
		system("pause");//请按任意键继续

		system("cls");//清屏
	}
}
//2、显示联系人
void showperson(addressbooks * abs)
{
	//判断通讯录中人数是否为0，如果是则返回空
	if (abs->m_size == 0)
	{
		cout << "当前记录联系人为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "姓名： " << abs->personarry[i].m_name << "\t";
			cout << "性别： " << (abs->personarry[i].m_sex == 1?"男":"女" )<< "\t";
			cout << "年龄： " << abs->personarry[i].m_age << "\t";
			cout << "电话： " << abs->personarry[i].m_phone << "\t";
			cout << "住址： " << abs->personarry[i].m_address << endl;
		}

	}
	system("pause");//请按任意键继续

	system("cls");//清屏
}

//检测联系人是否存在，若存在返回具体位置，否则返回-1
int isexit(addressbooks * abs, string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		//找到
		if (abs->personarry[i].m_name == name)
		{
			return i;

		}

	}
	return -1;
}

//3、删除指定联系人
void deleteperson(addressbooks * abs)
{

	cout << "请输入要删除的联系人：" << endl;
	string name;
	cin >> name;
	//ret == -1,查无此人
	//ret != -1,找到
	int ret = isexit(abs, name);
	if (ret != -1)
	{
		//查到后进行删除
		for (int i = ret; i < abs->m_size; i++)
		{
			//数据前移
			abs->personarry[i] = abs->personarry[i++];

		}
		abs->m_size--;//更新人数
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");//请按任意键继续

	system("cls");//清屏
}

//4、查找联系人
void findperson(addressbooks *abs)
{
	cout << "请输入要查找的联系人：" << endl;
	string name;
	cin >> name;
	//ret == -1,查无此人
	//ret != -1,找到
	int ret = isexit(abs, name);
	if (ret != -1)//找到
	{
		cout << "姓名： " << abs->personarry[ret].m_name << "\t";
		cout << "性别： " << (abs->personarry[ret].m_sex == 1 ? "男" : "女") << "\t";
		cout << "年龄： " << abs->personarry[ret].m_age << "\t";
		cout << "电话： " << abs->personarry[ret].m_phone << "\t";
		cout << "住址： " << abs->personarry[ret].m_address << endl;
	}
	else
	{
		cout << "查无此人" << endl;

	}
	system("pause");//请按任意键继续

	system("cls");//清屏
}

//5、修改制定联系人
void modifyperson(addressbooks *abs)
{
	cout << "请输入要修改的联系人：" << endl;
	string name;
	cin >> name;
	//ret == -1,查无此人
	//ret != -1,找到
	int ret = isexit(abs, name);
	if (ret != -1)//找到
	{
		//姓名
		string name;
		cout << "请输入姓名： " << endl;
		cin >> name;
		abs->personarry[ret].m_name = name;
		//性别
		cout << "请输入性别：" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			//如果输入1或2，则退出循环，否则重新输入
			if (sex == 1 || sex == 2)
			{
				abs->personarry[ret].m_sex = sex;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}


		//年龄
		cout << "请输入年龄：" << endl;

		int age = 0;
		while (true)
		{
			cin >> age;
			//如果输入1或2，则退出循环，否则重新输入
			if (0 < age&&age < 200)
			{
				abs->personarry[ret].m_age = age;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}

		//电话
		cout << "请输入电话：" << endl;
		string phone;
		cin >> phone;
		abs->personarry[ret].m_phone = phone;
		//住址
		cout << "请输入住址：" << endl;
		string address;
		cin >> address;
		abs->personarry[ret].m_address = address;
		
		cout << "修改成功！" << endl;

	}
	else
	{
		cout << "查无此人" << endl;

	}
	system("pause");//请按任意键继续

	system("cls");//清屏
}

//6、清空通讯录
void cleanperson(addressbooks *abs)
{
	abs->m_size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");
}

//菜单界面
void showmenu()
{
	cout << "*****************************" << endl;
	cout << "*****   1、添加联系人   *****" << endl;
	cout << "*****   2、显示联系人   *****" << endl;
	cout << "*****   3、删除联系人   *****" << endl;
	cout << "*****   4、查找联系人   *****" << endl;
	cout << "*****   5、修改联系人   *****" << endl;
	cout << "*****   6、清空联系人   *****" << endl;
	cout << "*****   0、退出通讯录   *****" << endl;
	cout << "*****************************" << endl;
}

int main()
{
	//创建结构体变量
	addressbooks abs;
	//初始化人员个数
	abs.m_size = 0;

	int select = 0;
	while (true)
	{
		//菜单界面
		showmenu();
		cin >> select;
		switch (select)
		{
		case 1:    //1、添加联系人
			addperson(&abs);
			break;
		case 2:    //2、显示联系人
			showperson(&abs);
			break;
		case 3:    //3、删除联系人
			deleteperson(&abs);
			break;
		case 4:    //4、查找联系人
			findperson(&abs);
			break;
		case 5:    //5、修改联系人
			modifyperson(&abs);
			break;
		case 6:    //6、清空联系人
			cleanperson(&abs);
			break;
		case 0:    //0、退出通讯录
			cout << "欢迎下次使用" << endl;
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