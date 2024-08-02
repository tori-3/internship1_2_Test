#include "pch.h"
#include"List.h"

///@brief �v�����
///@param (������) �����̐���
///@param (������) �����̐���
///@return �߂�l�̐���
bool CheckValue(const std::vector<Grades>& ans,const List&list) 
{
	if (ans.size() != list.size()) {
		return false;
	}

	bool failFlg = false;
	size_t i = 0;
	for (const auto& element : list)
	{
		if (element != ans[i]) {
			failFlg = true;
		}

		++i;
	}
	return !failFlg;
}



//���X�g�̃e�X�g

//�f�[�^���̎擾

//���X�g����ł���ꍇ�̖߂�l
TEST(TestListSize, Test0) {
	List list;
	EXPECT_EQ(0, list.size());
}

//���X�g�����ւ̑}�����s�����ۂ̖߂�l
TEST(TestListSize, Test1) {
	List list;
	list.add(Grades{ 0,"hoge" });
	EXPECT_EQ(1, list.size());
}

//�f�[�^�̑}�����s�����ۂ̖߂�l
TEST(TestListSize, Test3) {
	List list;
	list.insert(list.begin(),Grades{ 0,"hoge" });
	EXPECT_EQ(1, list.size());
}

//�f�[�^�̑}���Ɏ��s�����ۂ̖߂�l
TEST(TestListSize, Test4) {
	List list;
	list.insert(0, Grades{ 0,"hoge" });
	EXPECT_EQ(0, list.size());
}

//�f�[�^�̍폜���s�����ۂ̖߂�l
TEST(TestListSize, Test5) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.remove(list.begin());
	EXPECT_EQ(0, list.size());
}

//�f�[�^�̍폜�����s�����ۂ̖߂�l
TEST(TestListSize, Test6) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.remove(0);
	EXPECT_EQ(1, list.size());
}

//���X�g����ł���ꍇ�ɁA�f�[�^�̍폜���s�����ۂ̖߂�l
TEST(TestListSize, Test7) {
	List list;
	list.remove(list.begin());
	EXPECT_EQ(0, list.size());
}

//�f�[�^�̑}��

//���X�g����ł���ꍇ�ɁA�}�������ۂ̋���
TEST(TestListInsert, Test9) {
	List list;
	EXPECT_TRUE(list.insert(list.begin(), Grades{ 0,"hoge" }));
}

//���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^��n���āA�}�������ۂ̋���
TEST(TestListInsert, Test10) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	EXPECT_TRUE(list.insert(list.begin(), Grades{ 0,"hoge" }));
}

//���X�g�ɕ����̗v�f������ꍇ�ɁA�����C�e���[�^��n���āA�}�������ۂ̋���
TEST(TestListInsert, Test11) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });	
	EXPECT_TRUE(list.insert(list.end(), Grades{ 0,"hoge" }));
}

//���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���đ}�������ۂ̋���
//�擪�ɒǉ�
TEST(TestListInsert, Test12_1) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	EXPECT_TRUE(list.insert(list.begin(), Grades{ 2,"piyo" }));
	EXPECT_TRUE(CheckValue({ Grades{ 2,"piyo" },Grades{ 0,"hoge" },Grades{ 1,"fuga" } }, list));
}

//�����ɒǉ�
TEST(TestListInsert, Test12_2) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	EXPECT_TRUE(list.insert(list.end(), Grades{ 2,"piyo" }));
	EXPECT_TRUE(CheckValue({ Grades{ 0,"hoge" },Grades{ 1,"fuga" },Grades{ 2,"piyo" } }, list));
}

//�r���ɒǉ�
TEST(TestListInsert, Test12_3) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	auto iterator = list.begin();
	++iterator;
	EXPECT_TRUE(list.insert(iterator, Grades{ 2,"piyo" }));
	EXPECT_TRUE(CheckValue({Grades{ 0,"hoge" }, Grades{ 2,"piyo" },Grades{ 1,"fuga" } }, list));
}

//ConstIterator���w�肵�đ}�����s�����ۂ̋���
//�擪�ɒǉ�
TEST(TestListInsert, Test13_1) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	EXPECT_TRUE(list.insert(list.constBegin(), Grades{ 2,"piyo" }));
	EXPECT_TRUE(CheckValue({ Grades{ 2,"piyo" },Grades{ 0,"hoge" },Grades{ 1,"fuga" } }, list));
}

//�����ɒǉ�
TEST(TestListInsert, Test13_2) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	EXPECT_TRUE(list.insert(list.constEnd(), Grades{ 2,"piyo" }));
	EXPECT_TRUE(CheckValue({ Grades{ 0,"hoge" },Grades{ 1,"fuga" },Grades{ 2,"piyo" } }, list));
}

//�r���ɒǉ�
TEST(TestListInsert, Test13_3) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	auto iterator = list.constBegin();
	++iterator;
	EXPECT_TRUE(list.insert(iterator, Grades{ 2,"piyo" }));
	EXPECT_TRUE(CheckValue({ Grades{ 0,"hoge" }, Grades{ 2,"piyo" },Grades{ 1,"fuga" } }, list));
}

//�s���ȃC�e���[�^��n���āA�}�������ꍇ�̋���
TEST(TestListInsert, Test14) {
	List list;
	EXPECT_FALSE(list.insert(0, Grades{ 0,"hoge" }));
}



//�f�[�^�̍폜

//���X�g����ł���ꍇ�ɁA�폜���s�����ۂ̋���
TEST(TestListRemove, Test16) {
	List list;
	EXPECT_FALSE(list.remove(list.begin()));
	EXPECT_FALSE(list.remove(list.end()));
}

//���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�C�e���[�^��n���āA�폜�����ۂ̋���
TEST(TestListRemove, Test17) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	EXPECT_TRUE(list.remove(list.begin()));
}

//���X�g�ɕ����̗v�f������ꍇ�ɁA�����C�e���[�^��n���āA�폜�����ۂ̋���
TEST(TestListRemove, Test18) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	EXPECT_FALSE(list.remove(list.end()));
}

//���X�g�ɕ����̗v�f������ꍇ�ɁA�擪�ł������ł��Ȃ��C�e���[�^��n���č폜�����ۂ̋��� ##################################
TEST(TestListRemove, Test19) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	list.add(Grades{ 2,"piyo" });

	auto iterator = list.begin();
	++iterator;
	EXPECT_TRUE(list.remove(iterator));
	EXPECT_TRUE(CheckValue({ Grades{ 0,"hoge" }, Grades{ 2,"piyo" } }, list));
}

//ConstIterator���w�肵�č폜���s�����ۂ̋���
TEST(TestListRemove, Test20) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	list.add(Grades{ 2,"piyo" });

	auto iterator = list.constBegin();
	++iterator;
	EXPECT_TRUE(list.remove(iterator));
	EXPECT_TRUE(CheckValue({ Grades{ 0,"hoge" }, Grades{ 2,"piyo" } }, list));
}

//�s���ȃC�e���[�^��n���āA�폜�����ꍇ�̋���
TEST(TestListRemove, Test21) {
	List list;
	EXPECT_FALSE(list.remove(0));
}



//�擪�C�e���[�^�̎擾

//���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
TEST(TestListBegin, Test23) {
	List list;
	EXPECT_TRUE(list.begin() != List::Iterator{ nullptr });
}

//���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
TEST(TestListBegin, Test24) {
	List list;
	list.add(Grades{ 0,"hoge" });
	EXPECT_TRUE((*list.begin() == Grades{ 0,"hoge" }));
}

//���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
TEST(TestListBegin, Test25) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	EXPECT_TRUE((*list.begin() == Grades{ 0,"hoge" }));
}

//�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
TEST(TestListBegin, Test26_1) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	list.insert(list.begin(), Grades{ 2,"piyo" });
	EXPECT_TRUE((*list.begin() == Grades{ 2,"piyo" }));
}

TEST(TestListBegin, Test26_2) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	list.insert(list.end(), Grades{ 2,"piyo" });
	EXPECT_TRUE((*list.begin() == Grades{ 0,"hoge" }));
}

TEST(TestListBegin, Test26_3) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	auto iterator = list.begin();
	++iterator;
	list.insert(iterator, Grades{ 2,"piyo" });
	EXPECT_TRUE((*list.begin() == Grades{ 0,"hoge" }));
}


//�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
//�������폜
TEST(TestListBegin, Test27_1) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	list.add(Grades{ 2,"piyo" });
	list.remove(list.begin());
	EXPECT_TRUE((*list.begin() == Grades{ 1,"fuga" }));
}

//�������폜
TEST(TestListBegin, Test27_2) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	list.add(Grades{ 2,"piyo" });
	auto it = list.end();
	list.remove(list.end());

	EXPECT_TRUE((*list.begin() == Grades{ 0,"hoge" }));
}


//�r�����폜
TEST(TestListBegin, Test27_3) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	list.add(Grades{ 2,"piyo" });
	auto iterator = list.begin();
	++iterator;
	list.remove(iterator);
	EXPECT_TRUE((*list.begin() == Grades{ 0,"hoge" }));
}


//�擪�R���X�g�C�e���[�^�̎擾

//���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
TEST(TestListConstBegin, Test29) {
	List list;
	EXPECT_TRUE(list.constBegin() != List::Iterator{ nullptr });
}

//���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
TEST(TestListConstBegin, Test30) {
	List list;
	list.add(Grades{ 0,"hoge" });
	EXPECT_TRUE((*list.constBegin() == Grades{ 0,"hoge" }));
}

//���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
TEST(TestListConstBegin, Test31) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	EXPECT_TRUE((*list.constBegin() == Grades{ 0,"hoge" }));
}

//�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
//�擪�ɑ}��
TEST(TestListConstBegin, Test32_1) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	list.insert(list.begin(), Grades{ 2,"piyo" });
	EXPECT_TRUE((*list.constBegin() == Grades{ 2,"piyo" }));
}

//�����ɑ}��
TEST(TestListBegin, Test32_2) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	list.insert(list.end(), Grades{ 2,"piyo" });
	EXPECT_TRUE((*list.constBegin() == Grades{ 0,"hoge" }));
}

//�r���ɑ}��
TEST(TestListConstBegin, Test32_3) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	auto iterator = list.begin();
	++iterator;
	list.insert(iterator, Grades{ 2,"piyo" });
	EXPECT_TRUE((*list.constBegin() == Grades{ 0,"hoge" }));
}


//�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
//�擪���폜
TEST(TestListConstBegin, Test33_1) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	list.add(Grades{ 2,"piyo" });
	list.remove(list.begin());
	EXPECT_TRUE((*list.constBegin() == Grades{ 1,"fuga" }));
}

//�������폜
TEST(TestListConstBegin, Test33_2) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	list.add(Grades{ 2,"piyo" });
	list.remove(list.end());
	EXPECT_TRUE((*list.constBegin() == Grades{ 0,"hoge" }));
}

//�r�����폜
TEST(TestListConstBegin, Test33_3) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	list.add(Grades{ 2,"piyo" });
	auto iterator = list.begin();
	++iterator;
	list.remove(iterator);
	EXPECT_TRUE((*list.constBegin() == Grades{ 0,"hoge" }));
}



//�����C�e���[�^�̎擾

//���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
TEST(TestListEnd, Test35) {
	List list;
	EXPECT_TRUE(list.end() != List::Iterator{ nullptr });
}

//���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
TEST(TestListEnd, Test36) {
	List list;
	list.add(Grades{ 0,"hoge" });
	auto it = list.end();
	--it;
	EXPECT_TRUE((*it == Grades{ 0,"hoge" }));
}

//���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
TEST(TestListEnd, Test37) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	auto it = list.end();
	--it;
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

//�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
//�擪�ɑ}��
TEST(TestListEnd, Test38_1) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	list.insert(list.begin(), Grades{ 2,"piyo" });
	auto it = list.end();
	--it;
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

//�����ɑ}��
TEST(TestListEnd, Test38_2) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	list.insert(list.end(), Grades{ 2,"piyo" });
	auto it = list.end();
	--it;
	EXPECT_TRUE((*it == Grades{ 2,"piyo" }));
}

//�r���ɑ}��
TEST(TestListEnd, Test38_3) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	auto iterator = list.begin();
	++iterator;
	list.insert(iterator, Grades{ 2,"piyo" });
	auto it = list.end();
	--it;
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}


//�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
//�擪���폜
TEST(TestListEnd, Test39_1) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	list.add(Grades{ 2,"piyo" });
	list.remove(list.begin());
	auto it = list.end();
	--it;
	EXPECT_TRUE((*it == Grades{ 2,"piyo" }));
}

//�������폜
TEST(TestListEnd, Test39_2) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	list.add(Grades{ 2,"piyo" });
	auto endIt = list.end();
	--endIt;
	list.remove(endIt);
	auto it = list.end();
	--it;
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

//�r�����폜
TEST(TestListEnd, Test39_3) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	list.add(Grades{ 2,"piyo" });
	auto iterator = list.begin();
	++iterator;
	list.remove(iterator);
	auto it = list.end();
	--it;
	EXPECT_TRUE((*it == Grades{ 2,"piyo" }));
}


//�����R���X�g�C�e���[�^�̎擾

//���X�g����ł���ꍇ�ɁA�Ăяo�����ۂ̋���
TEST(TestListConstEnd, Test41) {
	List list;
	EXPECT_TRUE(list.constEnd() != List::Iterator{ nullptr });
}

//���X�g�ɗv�f�������ꍇ�ɁA�Ăяo�����ۂ̋���
TEST(TestListConstEnd, Test42) {
	List list;
	list.add(Grades{ 0,"hoge" });
	auto it = list.constEnd();
	--it;
	EXPECT_TRUE((*it == Grades{ 0,"hoge" }));
}

//���X�g�ɓ�ȏ�̗v�f������ꍇ�ɁA�Ăяo�����ۂ̋���
TEST(TestListConstEnd, Test43) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	auto it = list.constEnd();
	--it;
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

//�f�[�^�̑}�����s������ɁA�Ăяo�����ۂ̋���
//�擪�ɑ}��
TEST(TestListConstEnd, Test44_1) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	list.insert(list.begin(), Grades{ 2,"piyo" });
	auto it = list.constEnd();
	--it;
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

//����ɑ}��
TEST(TestListConstEnd, Test44_2) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	list.insert(list.end(), Grades{ 2,"piyo" });
	auto it = list.constEnd();
	--it;
	EXPECT_TRUE((*it == Grades{ 2,"piyo" }));
}

//�r���ɑ}��
TEST(TestListConstEnd, Test44_3) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	auto iterator = list.begin();
	++iterator;
	list.insert(iterator, Grades{ 2,"piyo" });
	auto it = list.constEnd();
	--it;
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}


//�f�[�^�̍폜���s������ɁA�Ăяo�����ۂ̋���
//�擪���폜
TEST(TestListConstEnd, Test45_1) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	list.add(Grades{ 2,"piyo" });
	list.remove(list.begin());
	auto it = list.constEnd();
	--it;
	EXPECT_TRUE((*it == Grades{ 2,"piyo" }));
}

//�������폜
TEST(TestListConstEnd, Test45_2) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	list.add(Grades{ 2,"piyo" });
	auto endIt = list.end();
	--endIt;
	list.remove(endIt);
	auto it = list.constEnd();
	--it;
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

//�r�����폜
TEST(TestListConstEnd, Test45_3) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	list.add(Grades{ 2,"piyo" });
	auto iterator = list.begin();
	++iterator;
	list.remove(iterator);
	auto it = list.constEnd();
	--it;
	EXPECT_TRUE((*it == Grades{ 2,"piyo" }));
}


//�C�e���[�^�[�̃e�X�g

//�C�e���[�^�̎w���v�f���擾����

//���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
TEST(TestIterator, Test0) {
	List::Iterator it{ nullptr };
	EXPECT_ANY_THROW((*it).score);
}

//Iterator����擾�����v�f�ɑ΂��āA�l�̑�����s���邩���`�F�b�N
TEST(TestIterator, Test1) {

	List list;
	list.add({ 0,"hoge" });

	auto it = list.begin();
	(*it) = Grades{ 1,"fuga" };

	EXPECT_TRUE(((*it) == Grades{ 1,"fuga" }));
}

//���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
TEST(TestIterator, Test3) {
	List list;
	EXPECT_ANY_THROW((*list.begin()).score);
}

//�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
TEST(TestIterator, Test4) {
	List list;
	EXPECT_ANY_THROW((*list.end()).score);
}


//�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�

//���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
TEST(TestIterator, Test5) {
	auto it = List::Iterator{ nullptr };
	EXPECT_ANY_THROW(++it);
}

//���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
TEST(TestIterator, Test6) {
	List list;
	auto it = list.begin();
	EXPECT_ANY_THROW(++it);
}

//�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
TEST(TestIterator, Test7) {
	List list;
	auto it = list.end();
	EXPECT_ANY_THROW(++it);
}

//���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂ̋���
TEST(TestIterator, Test8) {
	List list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.begin();
	++it;
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

//�O�u�C���N�������g���s�����ۂ̋���(++���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ)
TEST(TestIterator, Test9) {
	List list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.begin();
	EXPECT_TRUE((*(++it) == Grades{ 1,"fuga" }));
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

////��u�C���N�������g���s�����ۂ̋���( ++���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )
TEST(TestIterator, Test10) {
	List list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.begin();
	EXPECT_TRUE((*(it++) == Grades{ 0,"hoge" }));
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}


//�C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�

//���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
TEST(TestIterator, Test11) {
	auto it = List::Iterator{ nullptr };
	EXPECT_ANY_THROW(--it);
}

//���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
TEST(TestIterator, Test12) {
	List list;
	auto it = list.begin();
	EXPECT_ANY_THROW(--it);
}

//�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
TEST(TestIterator, Test13) {
	List list;
	auto it = list.end();
	EXPECT_ANY_THROW(--it);
}

//���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂ̋���
TEST(TestIterator, Test14) {
	List list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.end();
	--it;
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

//�O�u�f�N�������g���s�����ۂ̋���( ++���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ)
TEST(TestIterator, Test15) {
	List list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.end();
	EXPECT_TRUE((*(--it) == Grades{ 1,"fuga" }));
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

//��u�f�N�������g���s�����ۂ̋���( ++���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )
TEST(TestIterator, Test16) {
	List list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.end();
	it--;
	EXPECT_TRUE(((*(it--)) == Grades{ 1,"fuga" }));
	EXPECT_TRUE(((*it) == Grades{ 0,"hoge" }));
}



//�C�e���[�^�̃R�s�[���s��


//�R�s�[�R���X�g���N�g��̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N
TEST(TestIterator, Test18) {
	List list;
	list.add({ 0,"hoge" });

	auto it = list.begin();

	auto itCopy = it;
	
	EXPECT_TRUE(itCopy == it);
}

//�C�e���[�^�̑�����s��

//�����̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N
TEST(TestIterator, Test20) {
	List list;
	list.add({ 0,"hoge" });

	auto it = list.begin();
	auto itCopy = List::Iterator{ nullptr };
	itCopy = it;

	EXPECT_TRUE(itCopy == it);
}

//��̃C�e���[�^������̂��̂ł��邩�A��r���s��


//���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋������`�F�b�N
TEST(TestIterator, Test21) {
	List list;
	EXPECT_TRUE(list.begin() == list.end());
}

//����̃C�e���[�^���r�����ۂ̋���
TEST(TestIterator, Test22) {
	List list;
	list.add({ 0,"hoge" });
	EXPECT_TRUE(list.begin() == list.begin());
}

//�قȂ�C�e���[�^���r�����ۂ̋���
TEST(TestIterator, Test23) {
	List list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.begin();
	auto itA = it;
	auto itB = ++it;
	EXPECT_FALSE(itA==itB);
}



//��̃C�e���[�^���قȂ���̂ł��邩�A��r���s��


//���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋������`�F�b�N
TEST(TestIterator, Test24) {
	List list;
	EXPECT_FALSE(list.begin() != list.end());
}

//����̃C�e���[�^���r�����ۂ̋���
TEST(TestIterator, Test25) {
	List list;
	list.add({ 0,"hoge" });
	EXPECT_FALSE(list.begin() != list.begin());
}

//�قȂ�C�e���[�^���r�����ۂ̋���
TEST(TestIterator, Test26) {
	List list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.begin();
	auto itA = it;
	auto itB = ++it;
	EXPECT_TRUE(itA != itB);
}



//�R���X�g�C�e���[�^�[�̃e�X�g


//�C�e���[�^�̎w���v�f���擾����

//���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
TEST(TestConstIterator, Test0) {
	List::ConstIterator it{ nullptr };
	EXPECT_ANY_THROW((*it).score);
}

//���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
TEST(TestConstIterator, Test3) {
	List list;
	EXPECT_ANY_THROW((*list.constBegin()).score);
}

//�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
TEST(TestConstIterator, Test4) {
	List list;
	EXPECT_ANY_THROW((*list.constEnd()).score);
}


//�C�e���[�^�����X�g�̖����Ɍ������Ĉ�i�߂�


//���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
TEST(TestConstIterator, Test5) {
	auto it = List::ConstIterator{ nullptr };
	EXPECT_ANY_THROW(++it);
}

//���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
TEST(TestConstIterator, Test6) {
	List list;
	auto it = list.constBegin();
	EXPECT_ANY_THROW(++it);
}

//�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
TEST(TestConstIterator, Test7) {
	List list;
	auto it = list.constEnd();
	EXPECT_ANY_THROW(++it);
}

//���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂ̋���
TEST(TestConstIterator, Test8) {
	List list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.constBegin();
	++it;
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

//�O�u�C���N�������g���s�����ۂ̋���(++���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ)
TEST(TestConstIterator, Test9) {
	List list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.constBegin();
	EXPECT_TRUE((*(++it) == Grades{ 1,"fuga" }));
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

////��u�C���N�������g���s�����ۂ̋���( ++���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )
TEST(TestConstIterator, Test10) {
	List list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.constBegin();
	EXPECT_TRUE((*(it++) == Grades{ 0,"hoge" }));
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}


//�C�e���[�^�����X�g�̐擪�Ɍ������Ĉ�i�߂�

//���X�g�̎Q�Ƃ��Ȃ���ԂŌĂяo�����ۂ̋���
TEST(TestConstIterator, Test11) {
	auto it = List::ConstIterator{ nullptr };
	EXPECT_ANY_THROW(--it);
}

//���X�g����̍ۂ́A�擪�C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
TEST(TestConstIterator, Test12) {
	List list;
	auto it = list.constBegin();
	EXPECT_ANY_THROW(--it);
}

//�����C�e���[�^�ɑ΂��ČĂяo�����ۂ̋���
TEST(TestConstIterator, Test13) {
	List list;
	auto it = list.constEnd();
	EXPECT_ANY_THROW(--it);
}

//���X�g�ɓ�ȏ�̗v�f������ꍇ�ɌĂяo�����ۂ̋���
TEST(TestConstIterator, Test14) {
	List list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.constEnd();
	--it;
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

//�O�u�f�N�������g���s�����ۂ̋���( ++���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ)
TEST(TestConstIterator, Test15) {
	List list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.constEnd();
	EXPECT_TRUE((*(--it) == Grades{ 1,"fuga" }));
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

////��u�f�N�������g���s�����ۂ̋���( ++���Z�q�I�[�o�[���[�h�Ŏ��������ꍇ )
TEST(TestConstIterator, Test16) {
	List list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.constEnd();
	it--;
	EXPECT_TRUE(((*(it--)) == Grades{ 1,"fuga" }));
	EXPECT_TRUE(((*it) == Grades{ 0,"hoge" }));
}




//�C�e���[�^�̃R�s�[���s��

//�R�s�[�R���X�g���N�g��̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N
TEST(TestConstIterator, Test18) {
	List list;
	list.add({ 0,"hoge" });

	auto it = list.constBegin();

	auto itCopy = it;

	EXPECT_TRUE(itCopy == it);
}


//�C�e���[�^�̑�����s��

//�����̒l���R�s�[���Ɠ��������Ƃ��`�F�b�N
TEST(TestConstIterator, Test20) {
	List list;
	list.add({ 0,"hoge" });

	auto it = list.constBegin();
	auto itCopy = List::ConstIterator{ nullptr };
	itCopy = it;

	EXPECT_TRUE(itCopy == it);
}


//��̃C�e���[�^������̂��̂ł��邩�A��r���s��


//���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋������`�F�b�N
TEST(TestConstIterator, Test21) {
	List list;
	EXPECT_TRUE(list.constBegin() == list.constEnd());
}

//����̃C�e���[�^���r�����ۂ̋���
TEST(TestConstIterator, Test22) {
	List list;
	list.add({ 0,"hoge" });
	EXPECT_TRUE(list.constBegin() == list.constBegin());
}

//�قȂ�C�e���[�^���r�����ۂ̋���
TEST(TestConstIterator, Test23) {
	List list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.constBegin();
	auto itA = it;
	auto itB = ++it;
	EXPECT_FALSE(itA == itB);
}



//��̃C�e���[�^���قȂ���̂ł��邩�A��r���s��


//���X�g����̏�Ԃł̐擪�C�e���[�^�Ɩ����C�e���[�^���r�����ۂ̋������`�F�b�N
TEST(TestConstIterator, Test24) {
	List list;
	EXPECT_FALSE(list.constBegin() != list.constEnd());
}

//����̃C�e���[�^���r�����ۂ̋���
TEST(TestConstIterator, Test25) {
	List list;
	list.add({ 0,"hoge" });
	EXPECT_FALSE(list.constBegin() != list.constBegin());
}

//�قȂ�C�e���[�^���r�����ۂ̋���
TEST(TestConstIterator, Test26) {
	List list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.constBegin();
	auto itA = it;
	auto itB = ++it;
	EXPECT_TRUE(itA != itB);
}

