#include <iostream>

using namespace std;

typedef struct tagInfo
{
	char	szName[16];
	int		iAtt;
	int		iMaxHp;
	int		iHp;
}INFO;


INFO* Select_Job();
void Render_Info(INFO* _pInfo);
int Combat(INFO* _pPlayer, INFO* _pMonster);
void MainGame(INFO* _pPlayer);
void Create_Object(INFO** _pInfo, char* _pName, int _iAtt, int _iMaxHp);

void main()
{
	INFO* pPlayer = Select_Job();

	if (nullptr == pPlayer)
		return;

	MainGame(pPlayer);

	if (pPlayer)
	{
		delete pPlayer;
		pPlayer = nullptr;
	}
}

void Create_Object(INFO** _pInfo, char* _pName, int _iAtt, int _iMaxHp)
{
	(*_pInfo) = new INFO;
	strcpy_s((*_pInfo)->szName, sizeof((*_pInfo)->szName), _pName);
	(*_pInfo)->iAtt = _iAtt;
	(*_pInfo)->iMaxHp = _iMaxHp;
	(*_pInfo)->iHp = (*_pInfo)->iMaxHp;

}

void MainGame(INFO* _pPlayer)
{
	int iSelect = 0;
	INFO* pMonster = nullptr;

	while (true)
	{
		system("cls");
		Render_Info(_pPlayer);
		cout << "1.�ʱ� 2.�߱� 3.��� 4.����" << endl;
		cout << "=======================================================" << endl;
		cout << "�Է�: ";
		cin >> iSelect;

		switch (iSelect)
		{
		case 1:
			Create_Object(&pMonster, "������", 5, 30);
			break;
		case 2:
			Create_Object(&pMonster, "�����", 15, 60);
			break;
		case 3:
			Create_Object(&pMonster, "��", 30, 90);
			break;
		case 4:
			return;
		default:
			break;
		}

		int iRes = Combat(_pPlayer, pMonster);

		if (pMonster)
		{
			delete pMonster;
			pMonster = nullptr;
		}

		switch (iRes)
		{
		case 0:	// �÷��̾� ����ġ, ��� ���� ����
			break;
		case 1:	// �÷��̾��� ��� �г�Ƽ
			_pPlayer->iHp = _pPlayer->iMaxHp;
			break;
		case 2:	// ���� �� �г�Ƽ
			break;
		default:
			break;
		}
	}
}

int Combat(INFO* _pPlayer, INFO* _pMonster)
{
	int iSelect = 0;

	while (true)
	{
		system("cls");
		Render_Info(_pPlayer);
		Render_Info(_pMonster);
		cout << "1.���� 2.����" << endl;
		cout << "=======================================================" << endl;
		cout << "�Է�: ";
		cin >> iSelect;

		switch (iSelect)
		{
		case 1:
			_pPlayer->iHp -= _pMonster->iAtt;
			_pMonster->iHp -= _pPlayer->iAtt;
			break;
		case 2:
			return 2;
		default:
			break;
		}

		if (0 >= _pPlayer->iHp)
		{
			cout << "�÷��̾� ���" << endl;
			system("pause");
			return 1;
		}
		if (0 >= _pMonster->iHp)
		{
			cout << "��� ����" << endl;
			system("pause");
			return 0;
		}
	}
}

void Render_Info(INFO* _pInfo)
{
	cout << "����: " << _pInfo->szName << endl;
	cout << "���ݷ�: " << _pInfo->iAtt << endl;
	cout << "ü��: " << _pInfo->iHp << " / " << _pInfo->iMaxHp << endl;
	cout << "=======================================================" << endl;
}

INFO* Select_Job()
{
	int iSelect = 0;
	INFO* pPlayer = nullptr;

	cout << "1.���� 2.������ 3.���� 4.����" << endl;
	cout << "=======================================================" << endl;
	cout << "�Է�: ";
	cin >> iSelect;

	switch (iSelect)
	{
	case 1:
		Create_Object(&pPlayer, "����", 10, 200);
		break;
	case 2:
		Create_Object(&pPlayer, "������", 30, 100);
		break;
	case 3:
		Create_Object(&pPlayer, "����", 20, 150);
		break;
	case 4:
		break;
	default:
		break;
	}

	return pPlayer;
}