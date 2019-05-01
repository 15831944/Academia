/*

###########################
      vector container
###########################

- <vector> header ���� ���� ���Ѿ� �մϴ�.
(namespace�� �־���� ��.)

- ���ø� Ŭ�����̹Ƿ�, <> "angle bracket"�ȿ� ���� �� �����ϰ� �ϴ� �ڷ����� ������ش�.

vector<int> intVec;


#################
   ������ �߰�
#################

- "back" ��ġ������ �������� �߰��� �̷�����ϴ�.
("front"�� �����ֽ��ϴ�.)
So, push_back() �Լ� �̿�.

#################
   ������ ���
#################

- for ���� �̿��մϴ�.
���� �迭 ������� ������ vector �����̳ʴ� �ε��� �������� ����� �����մϴ� !!!!
(����, �ε��� �����ڰ� �����ε��� �Ǿ��ְ�, Random Access�� �����ϴϱ� !!!!)

- vector �����̳��� ����� size() �Լ��� ����ϸ� �˴ϴ� !!!!

#################
   ������ ����
#################

- "back" ��ġ������ �������� ���Ű� �̷�����ϴ�.
("front"�� �����ֽ��ϴ�.)
So, pop_back() �Լ� �̿�.


####################################################################################################################

###############################
  vector �����̳��� ��� �Լ�
###############################


##############################
   �����̳��� ���� ���� Ȯ�� - size()
##############################

size_t size() const;

- ���� vector �����̳��� ���� ������ ��ȯ�մϴ�.
(��ȯ���� size_t "unsigned int"������ ��ȯ�ϱ� ������...)


##############################
   �����̳��� ���� �迭 ũ�� - capacity()
##############################

- vector �����̳��� ���� ���� �Ҵ�� �޸��� ������ ��ȯ�մϴ�.
- vector �����̳ʿ� �����͸� �߰� ��, ���� �迭�� ũ�⸦ �Ѿ�� �Ǹ� ���Ҵ� �� ���簡 �Ͼ��.
(���� �����̳��� �ʱ� ���� ���¿����� "0")
- �Ҵ�� �޸𸮴� �پ���� �ʽ��ϴ� !!!!


#############################
  �����̳��� ��� ��ü ���� - claer()
#############################

- vector �����̳ʿ� �߰��Ǿ� �ִ� ��� ���Ҹ� ���ϴ�.
but, �Ҵ�� �޸𸮴� �״�� �����ϴ�.


###############################
  �����̳ʰ� ����ִ� �� ���� - empty()
###############################

- bool �ڷ����� ��ȯ�ϱ� ������...
��������� "true", ���Ұ� �����Ѵٸ� "false"


########################
  �����̳� ��ü�� ��ȯ - swap()
########################

- swap �Լ��� ȣ���ϴ� vector �����̳ʿ� ���ڷ� �����ϴ� vector �����̳��� ������ �ٲߴϴ�.

########################################################################
- �ӽ� ��ü�� �̿��Ѵٸ�, vector �����̳��� �޸𸮸� ���� �� �ִٰ� ?!?! - �ʱ� ���·�...
�ֳ��ϸ� �ӽ� ��ü�� �ٷ� �Ҹ��ڸ� ȣ���� �� �����ϱ� !!!!
########################################################################


############################
  �����̳��� ���� �˾ƺ��� - front(), back()
############################

- front() : ù ���� Reference (= intVec[0])
- back() : ������ ���� Reference (= intVec[intVec.size() - 1])

������ �����Ϳ� �����ؼ� ���� �ٲ� ���� �ִ� ?!?!?!



####################################################################################################################

#####################
   iterator(�ݺ���) - ��ü
#####################

- �ݺ��ڴ� �����Ϳ� ����� �����̰�, �ϳ��� "��ü"�Դϴ� !!!!
- "operater*"�� ���� ���ҿ� ������ �� �ֽ��ϴ�.

- �����̳ʸ��� �������� ���� ��� �� ���� ������ �޶�, �����̳ʸ� ��ȸ�ϴ� ����� �ٸ��ϴ�.

but, �Ϲ�ȭ�Ͽ� ���������� ����� �� �ֵ��� "iterator"�� �����߽��ϴ�.
(��, �����̳ʸ��� �ݺ��� ��ü�� ���ø�ȭ�Ͽ� �������ҽ��ϴ�.)

ex. vector<int>::iterator iter_begin = intVec.begin();


############################################
   �����̳��� �ݺ��ڸ� ��ȯ�ϴ� ��� �Լ� - begin(), end()
############################################

- begin() : "ù��° ������ ��ġ"�� ����Ű�� �ݺ��ڸ� ��ȯ
- end() : "������ ������ ���� ��ġ"�� ����Ű�� �ݺ��ڸ� ��ȯ (��ȸ ������ ����...)

So, �ݺ��ڸ� �̿��� �����̳� ��ȸ ���

ex.
vector<int>::iterator iter_begin = intVec.begin();
vector<int>::iterator iter_end = intVec.end();

for (; iter_begin != iter_end; ++iter_begin)
{
	cout << *iter_begin << endl; // ���� Reference�� ��ȯ�ϱ� ������ �����Ͽ� �� ���浵 �����մϴ�.
}



##############################
   iterator & const Ű����
##############################

- �б⸸ ����մϴ�.
- ���ʿ� �����̳� ��ü�� const_iterator�� �����մϴ� !!!!

ex.
vector<int>::const_iterator const_iter_begin = intVec.begin();
vector<int>::const_iterator const_iter_end = intVec.end();

####################################################################################################################

#####################
   iterator �� ���� - 5����
#####################

case 1. ���� ���� �ݺ���(Random Access Iterator)
case 2. ����� �ݺ���(Bidirectional Iterator)
case 3. ������ �ݺ���(Forward Iterator)
case 4. �Է� �ݺ���(Input Iterator)
case 5. ��� �ݺ���(Output Iterator)


################################################
case 1. ���� ���� �ݺ���(Random Access Iterator)
################################################
- ���ӵ�(contiguous) �޸𸮸� ����ϴ� �迭 ��� �����̳ʵ��� ���� �ݺ����Դϴ�.
- "[], +=, -=, ++, --" ���� �����ڵ��� �����ε� �Ǿ� �ֽ��ϴ�.
(��ġ ������ ������ �ϰų�, ������ �����Ϳ� �����Ͽ� ���� ������ �� �ֽ��ϴ�.)


#############################################
case 2. ����� �ݺ���(Bidirectional Iterator)
#############################################
- ��� ��� �����̵��� ���� �ݺ����Դϴ�.
- "++, --"�� �����ڷ� ����⿡���� ���ٸ� �����մϴ�.

#############################################


####################################################################################################################

########################################################
   ���� ���� �ݺ��ڸ� ���� �߰� ��ġ�� ���� �߰�, ���� - insert(), erase()
########################################################

- insert() : �Ű������� "iterator"�� �����͸� �޽��ϴ�.

- erase() : �Ű������� "iterator"�� �ް�, ������ ���Ҹ� ����Ű�� iterator�� ��ȯ�մϴ�.
			(����, ���� �޸� �ּҴ� ����)

####################################################################################################################


*/


#include <iostream>
#include <vector>

using std::cout;
using std::endl;

using std::vector;


int main(void)
{
	cout << "############################################################################" << endl;
	cout << "### vector �����̳�.01(����, ������ �߰�, ����, ���)" << endl << endl;

	// vector �����̳� ����
	vector<int> intVec1;

	// ������ �߰�  - pop_push() �Լ�, vector �����̳ʴ� "back" ��ġ������ �������� �߰�, ������ �����մϴ�.
	intVec1.push_back(1);
	intVec1.push_back(2);
	intVec1.push_back(3);
	intVec1.push_back(4);

	// ������ ���
	// vector �����̳ʴ� ���� �迭�� ������� �����Ǿ� �ֱ� ������
	// �ε��� ������ ���� ������ �����ϸ�, ���� ���浵 �����մϴ�.
	for (int i = 0; i < 4; ++i) // ������ ������ ��ȯ�ϴ� ��� �Լ� size()�� ����մϴ�.
	{
		cout << intVec1[i] << ' ';
	}
	cout << endl;

	for (int i = 0; i < 4; ++i)
	{
		intVec1[i] += 5;
		cout << intVec1[i] << ' ';
	}
	cout << endl << endl;

	// ������ ���� - pop_back() �Լ�, vector �����̳ʴ� "back" ��ġ������ �������� �߰�, ������ �����մϴ�.
	intVec1.pop_back();
	intVec1.pop_back();

	for (int i = 0; i < 2; ++i)
	{
		cout << intVec1[i] << ' ';
	}
	cout << endl;

	cout << "############################################################################" << endl;
	cout << "### vector �����̳�.02(size(), capacity(), empty(), swap()" << endl << endl;

	vector<int> intVec2;

	intVec2.push_back(1);
	intVec2.push_back(2);
	intVec2.push_back(3);
	intVec2.push_back(4);

	// vector �����̳��� ��� �Լ� : size(), size_t(unsigned int)�� ��ȯ�մϴ�.
	for (size_t i = 0; i < intVec2.size(); ++i)
	{
		cout << intVec2[i] << ' ';
	}
	cout << endl << endl;

	cout << "intVec2 size: " << intVec2.size() << endl;
	cout << "intVec2 capacity: " << intVec2.capacity() << endl << endl; // �߰� ���� �ʴ� �� �þ�� �ʰ�,
																		// �پ������ ����.
	// ���� ��ü ����
	cout << "vector �����̳��� ���� ��ü ����" << endl;
	intVec2.clear(); // ����, ������ �Ѿ �迭 ���ٽ� Runtime Error !!!!
	cout << "intVec2 size: " << intVec2.size() << endl;
	cout << "intVec2 capacity: " << intVec2.capacity() << endl << endl;

	// ����ִ� �� ���� Ȯ��
	cout << "empty() �Լ��� �̿��� vector �����̳��� ���� ���� ����" << endl;
	cout << '[';
	for (size_t i = 0; i < intVec1.size(); ++i)
	{
		cout << intVec1[i] << ' ';
	}
	cout << ']' << endl;

	if (intVec1.empty())
	{
		cout << "intVec1: ����ֽ��ϴ�." << endl;
	}
	else
	{
		cout << "intVec1: ���Ұ� �ֽ��ϴ�." << endl;
	}

	cout << '[';
	for (size_t i = 0; i < intVec2.size(); ++i)
	{
		cout << intVec2[i] << ' ';
	}
	cout << ']' << endl;

	if (intVec2.empty())
	{
		cout << "intVec2: ����ֽ��ϴ�." << endl;
	}
	else
	{
		cout << "intVec2: ���Ұ� �ֽ��ϴ�." << endl;
	}
	cout << endl;


	cout << "���� ���� ��ȯ - swap()" << endl;
	vector<int> tempVec;
	tempVec.push_back(10);
	tempVec.push_back(20);
	
	cout << "#### �ʱ� ���� ####" << endl;
	cout << "intVec2 size: " << intVec2.size() << endl;
	cout << "intVec2 capacity: " << intVec2.capacity() << endl << endl;

	cout << "tempVec size: " << tempVec.size() << endl;
	cout << "tempVec capacity: " << tempVec.capacity() << endl << endl;

	cout << "#### swap() ��� ȣ�� ####" << endl;

	intVec2.swap(tempVec);

	cout << "intVec2 size: " << intVec2.size() << endl;
	cout << "intVec2 capacity: " << intVec2.capacity() << endl << endl;

	cout << "tempVec size: " << tempVec.size() << endl;
	cout << "tempVec capacity: " << tempVec.capacity() << endl << endl;

	cout << "#### �ӽ� ��ü�� �̿��� swap() �Լ��� ���� �迭 ���ֱ� ####" << endl;

	cout << "intVec2 size: " << intVec2.size() << endl;
	cout << "intVec2 capacity: " << intVec2.capacity() << endl << endl;

	// ###########################
	// �ӽ� ��ü�� �̿��� vector �����̳� �ʱ�ȭ
	vector<int>().swap(intVec2);
	//intVec2.swap(vector<int>());
	// ###########################

	cout << "intVec2 size: " << intVec2.size() << endl;
	cout << "intVec2 capacity: " << intVec2.capacity() << endl << endl;

	cout << "############################################################################" << endl;
	cout << "### iterator ����� �ʱ�ȭ, begin(), end()" << endl << endl;

	vector<int> intVec3;

	intVec3.push_back(1);
	intVec3.push_back(2);
	intVec3.push_back(3);
	intVec3.push_back(4);

	// �ݺ����� ����� �ʱ�ȭ
	vector<int>::iterator iter_begin3 = intVec3.begin(); // ù ��° ������ ��ġ
	vector<int>::iterator iter_end3 = intVec3.end(); // ������ ���� ��ġ�� ���� ��ġ

	// ++, * operator�� �����ε� �Ǿ��־� ������ �����ϴ� ��ó�� ����� �� �ֽ��ϴ�.
	for (; iter_begin3 != iter_end3; ++iter_begin3)
	{
		cout << *iter_begin3 << ' ';
	}
	cout << endl;

	// iter_begin3�� �� ������ �־ "iterator ��ȿȭ"�� �߻��߽��ϴ�.
	// So, ����ϱ� ���� ó�� ������ �ٽ� �����ؾ� �մϴ�.
	iter_begin3 = intVec3.begin();
	for (; iter_begin3 != iter_end3; ++iter_begin3) // "iterator"�� �̿��� ��� �������� �� ������ �����մϴ�.
	{
		*iter_begin3 += 10;
		cout << *iter_begin3 << ' ';
	}
	cout << endl << endl;


	cout << "����ִ� �����̳��� begin()�� end()" << endl;
	intVec3.clear(); // vector �����̳��� ���� ��ü ����
	iter_begin3 = intVec3.begin();
	iter_end3 = intVec3.end();

	if (iter_begin3 == iter_end3)
	{
		cout << "begin(), end() ����" << endl; // ����ִ� �����̳ʶ� �����ϴ� !!!!
	}
	else
	{
		cout << "�ٸ���" << endl;
	}
	cout << endl;

	cout << "############################################################################" << endl;
	cout << "### vector container�� iterator - Random Access Iterator " << endl << endl;

	vector<int> intVec4;
	// vector �����̳ʴ� ���ӵ� �޸𸮸� ����ϴ� ���� �迭�� �����Ǿ� �ֱ� ������,
	// "Random Access Iterator"�� ����մϴ�.

	intVec4.push_back(1);
	intVec4.push_back(2);
	intVec4.push_back(3);
	intVec4.push_back(4);

	cout << "���� ���� �ݺ��ڷ� �߰� ��ġ ����, ���� - insert(), erase()" << endl << endl;

	vector<int>::iterator iter_begin4 = intVec4.begin();
	vector<int>::iterator iter_end4 = intVec4.end();

	cout << "�ʱ� ����" << endl;
	for (size_t i = 0; i< intVec4.size(); ++i)
	{
		cout << intVec4[i] << ' ';
	}
	cout << endl << endl;


	// �ݺ��ڸ� ���� insert() �Լ� ���� �����ϸ�... �Ǵ� �ݺ��ڸ� ���� ��ȸ���� ��...
	// �ݺ����� ��ġ�� ������ �� �����Ƿ�, �ݺ����� ��ȿȭ�� �߻��մϴ�.
	// So, �ٽ� ���� �־��ְ� ����ؾ� �մϴ�.
	iter_begin4 += 2; // "iter_begin[3]"�� ���� �ǹ��Դϴ�.
	intVec4.insert(iter_begin4, 0);

	cout << "�߰�" << endl;
	for (size_t i = 0; i< intVec4.size() ; ++i)
	{
		cout << intVec4[i] << ' ';
	}
	cout << endl << endl;


	iter_begin4 = intVec4.begin() + 3;
	intVec4.erase(iter_begin4); // erase() �Լ��� ���� ������ ���� ���Ҹ� ����ŵ�ϴ�.
								// So, �̰��� �̿��� �ʱ�ȭ...

	// �ݺ����� ��ȿȭ�� �߻��� �� �����Ƿ�... �ʱ�ȭ ��Ű�� �ϰų� �ƴϸ� size() �Լ��� �̿��Ͽ�...
	cout << "����" << endl;
	for (size_t i = 0; i< intVec4.size(); ++i)
	{
		cout << intVec4[i] << ' ';
	}
	cout << endl;

	cout << "############################################################################" << endl;
	cout << "### iterator�� ��ȿȭ �Ǵ� ���..." << endl << endl;

	vector<int> intVec5;

	intVec5.push_back(1);
	intVec5.push_back(2);
	intVec5.push_back(3);
	intVec5.push_back(4);

	for (size_t i = 0; i< intVec5.size(); ++i)
	{
		cout << intVec5[i] << ' ';
	}
	cout << endl << endl;


	cout << "Ȧ����° ���Ҹ� ����� ���" << endl;
	vector<int>::iterator iter = intVec5.begin();
	for (; iter != intVec5.end();)
	{
		if ((*iter) % 2 == 1)
		{
			iter = intVec5.erase(iter); // out of range Runtime Error �����ϸ鼭...
		}								// ������ �߻��ϸ� �ε����� �������� ������� �� !!!!
		else
		{
			++iter;
		}
	}

	for (size_t i = 0; i< intVec5.size(); ++i)
	{
		cout << intVec5[i] << ' ';
	}
	cout << endl;


	//////////////////////////////////////////////////////
	vector<int> intVec6;

	intVec6.push_back(1);
	intVec6.push_back(2);
	intVec6.push_back(3);
	intVec6.push_back(4);

	cout << "¦����° ���Ҹ� ����� ���" << endl;
	iter = intVec6.begin();
	for (; iter != intVec6.end(); ++iter)
	{
		if ((*iter) % 2 == 1)
		{
			iter = intVec6.erase(iter); // ���ʿ� ���Ҹ� ������ ��ܿ�...
			iter--; // Ȧ����° ���ﶧ�� out of range Runtime Error
					// �ֳ��ϸ�, ù ��° ���Ҹ� ����Ű�� �ִ� iterator����
					// ������ �Ѿ���� ���� ������ ������ �� ���� ������ !!!!
		}			// (vector iterator not decrementable)
	}

	for (size_t i = 0; i< intVec6.size(); ++i)
	{
		cout << intVec6[i] << ' ';
	}
	cout << endl;

	cout << "############################################################################" << endl;


	return 0;
}