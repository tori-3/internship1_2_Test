#include "pch.h"
#include"List.h"

///@brief 要約説明
///@param (引数名) 引数の説明
///@param (引数名) 引数の説明
///@return 戻り値の説明
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



//リストのテスト

//データ数の取得

//リストが空である場合の戻り値
TEST(TestListSize, Test0) {
	List list;
	EXPECT_EQ(0, list.size());
}

//リスト末尾への挿入を行った際の戻り値
TEST(TestListSize, Test1) {
	List list;
	list.add(Grades{ 0,"hoge" });
	EXPECT_EQ(1, list.size());
}

//データの挿入を行った際の戻り値
TEST(TestListSize, Test3) {
	List list;
	list.insert(list.begin(),Grades{ 0,"hoge" });
	EXPECT_EQ(1, list.size());
}

//データの挿入に失敗した際の戻り値
TEST(TestListSize, Test4) {
	List list;
	list.insert(0, Grades{ 0,"hoge" });
	EXPECT_EQ(0, list.size());
}

//データの削除を行った際の戻り値
TEST(TestListSize, Test5) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.remove(list.begin());
	EXPECT_EQ(0, list.size());
}

//データの削除が失敗した際の戻り値
TEST(TestListSize, Test6) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.remove(0);
	EXPECT_EQ(1, list.size());
}

//リストが空である場合に、データの削除を行った際の戻り値
TEST(TestListSize, Test7) {
	List list;
	list.remove(list.begin());
	EXPECT_EQ(0, list.size());
}

//データの挿入

//リストが空である場合に、挿入した際の挙動
TEST(TestListInsert, Test9) {
	List list;
	EXPECT_TRUE(list.insert(list.begin(), Grades{ 0,"hoge" }));
}

//リストに複数の要素がある場合に、先頭イテレータを渡して、挿入した際の挙動
TEST(TestListInsert, Test10) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	EXPECT_TRUE(list.insert(list.begin(), Grades{ 0,"hoge" }));
}

//リストに複数の要素がある場合に、末尾イテレータを渡して、挿入した際の挙動
TEST(TestListInsert, Test11) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });	
	EXPECT_TRUE(list.insert(list.end(), Grades{ 0,"hoge" }));
}

//リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して挿入した際の挙動
//先頭に追加
TEST(TestListInsert, Test12_1) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	EXPECT_TRUE(list.insert(list.begin(), Grades{ 2,"piyo" }));
	EXPECT_TRUE(CheckValue({ Grades{ 2,"piyo" },Grades{ 0,"hoge" },Grades{ 1,"fuga" } }, list));
}

//末尾に追加
TEST(TestListInsert, Test12_2) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	EXPECT_TRUE(list.insert(list.end(), Grades{ 2,"piyo" }));
	EXPECT_TRUE(CheckValue({ Grades{ 0,"hoge" },Grades{ 1,"fuga" },Grades{ 2,"piyo" } }, list));
}

//途中に追加
TEST(TestListInsert, Test12_3) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	auto iterator = list.begin();
	++iterator;
	EXPECT_TRUE(list.insert(iterator, Grades{ 2,"piyo" }));
	EXPECT_TRUE(CheckValue({Grades{ 0,"hoge" }, Grades{ 2,"piyo" },Grades{ 1,"fuga" } }, list));
}

//ConstIteratorを指定して挿入を行った際の挙動
//先頭に追加
TEST(TestListInsert, Test13_1) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	EXPECT_TRUE(list.insert(list.constBegin(), Grades{ 2,"piyo" }));
	EXPECT_TRUE(CheckValue({ Grades{ 2,"piyo" },Grades{ 0,"hoge" },Grades{ 1,"fuga" } }, list));
}

//末尾に追加
TEST(TestListInsert, Test13_2) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	EXPECT_TRUE(list.insert(list.constEnd(), Grades{ 2,"piyo" }));
	EXPECT_TRUE(CheckValue({ Grades{ 0,"hoge" },Grades{ 1,"fuga" },Grades{ 2,"piyo" } }, list));
}

//途中に追加
TEST(TestListInsert, Test13_3) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	auto iterator = list.constBegin();
	++iterator;
	EXPECT_TRUE(list.insert(iterator, Grades{ 2,"piyo" }));
	EXPECT_TRUE(CheckValue({ Grades{ 0,"hoge" }, Grades{ 2,"piyo" },Grades{ 1,"fuga" } }, list));
}

//不正なイテレータを渡して、挿入した場合の挙動
TEST(TestListInsert, Test14) {
	List list;
	EXPECT_FALSE(list.insert(0, Grades{ 0,"hoge" }));
}



//データの削除

//リストが空である場合に、削除を行った際の挙動
TEST(TestListRemove, Test16) {
	List list;
	EXPECT_FALSE(list.remove(list.begin()));
	EXPECT_FALSE(list.remove(list.end()));
}

//リストに複数の要素がある場合に、先頭イテレータを渡して、削除した際の挙動
TEST(TestListRemove, Test17) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	EXPECT_TRUE(list.remove(list.begin()));
}

//リストに複数の要素がある場合に、末尾イテレータを渡して、削除した際の挙動
TEST(TestListRemove, Test18) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	EXPECT_FALSE(list.remove(list.end()));
}

//リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して削除した際の挙動 ##################################
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

//ConstIteratorを指定して削除を行った際の挙動
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

//不正なイテレータを渡して、削除した場合の挙動
TEST(TestListRemove, Test21) {
	List list;
	EXPECT_FALSE(list.remove(0));
}



//先頭イテレータの取得

//リストが空である場合に、呼び出した際の挙動
TEST(TestListBegin, Test23) {
	List list;
	EXPECT_TRUE(list.begin() != List::Iterator{ nullptr });
}

//リストに要素が一つある場合に、呼び出した際の挙動
TEST(TestListBegin, Test24) {
	List list;
	list.add(Grades{ 0,"hoge" });
	EXPECT_TRUE((*list.begin() == Grades{ 0,"hoge" }));
}

//リストに二つ以上の要素がある場合に、呼び出した際の挙動
TEST(TestListBegin, Test25) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	EXPECT_TRUE((*list.begin() == Grades{ 0,"hoge" }));
}

//データの挿入を行った後に、呼び出した際の挙動
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


//データの削除を行った後に、呼び出した際の挙動
//末尾を削除
TEST(TestListBegin, Test27_1) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	list.add(Grades{ 2,"piyo" });
	list.remove(list.begin());
	EXPECT_TRUE((*list.begin() == Grades{ 1,"fuga" }));
}

//末尾を削除
TEST(TestListBegin, Test27_2) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	list.add(Grades{ 2,"piyo" });
	auto it = list.end();
	list.remove(list.end());

	EXPECT_TRUE((*list.begin() == Grades{ 0,"hoge" }));
}


//途中を削除
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


//先頭コンストイテレータの取得

//リストが空である場合に、呼び出した際の挙動
TEST(TestListConstBegin, Test29) {
	List list;
	EXPECT_TRUE(list.constBegin() != List::Iterator{ nullptr });
}

//リストに要素が一つある場合に、呼び出した際の挙動
TEST(TestListConstBegin, Test30) {
	List list;
	list.add(Grades{ 0,"hoge" });
	EXPECT_TRUE((*list.constBegin() == Grades{ 0,"hoge" }));
}

//リストに二つ以上の要素がある場合に、呼び出した際の挙動
TEST(TestListConstBegin, Test31) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	EXPECT_TRUE((*list.constBegin() == Grades{ 0,"hoge" }));
}

//データの挿入を行った後に、呼び出した際の挙動
//先頭に挿入
TEST(TestListConstBegin, Test32_1) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	list.insert(list.begin(), Grades{ 2,"piyo" });
	EXPECT_TRUE((*list.constBegin() == Grades{ 2,"piyo" }));
}

//末尾に挿入
TEST(TestListBegin, Test32_2) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	list.insert(list.end(), Grades{ 2,"piyo" });
	EXPECT_TRUE((*list.constBegin() == Grades{ 0,"hoge" }));
}

//途中に挿入
TEST(TestListConstBegin, Test32_3) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	auto iterator = list.begin();
	++iterator;
	list.insert(iterator, Grades{ 2,"piyo" });
	EXPECT_TRUE((*list.constBegin() == Grades{ 0,"hoge" }));
}


//データの削除を行った後に、呼び出した際の挙動
//先頭を削除
TEST(TestListConstBegin, Test33_1) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	list.add(Grades{ 2,"piyo" });
	list.remove(list.begin());
	EXPECT_TRUE((*list.constBegin() == Grades{ 1,"fuga" }));
}

//末尾を削除
TEST(TestListConstBegin, Test33_2) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	list.add(Grades{ 2,"piyo" });
	list.remove(list.end());
	EXPECT_TRUE((*list.constBegin() == Grades{ 0,"hoge" }));
}

//途中を削除
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



//末尾イテレータの取得

//リストが空である場合に、呼び出した際の挙動
TEST(TestListEnd, Test35) {
	List list;
	EXPECT_TRUE(list.end() != List::Iterator{ nullptr });
}

//リストに要素が一つある場合に、呼び出した際の挙動
TEST(TestListEnd, Test36) {
	List list;
	list.add(Grades{ 0,"hoge" });
	auto it = list.end();
	--it;
	EXPECT_TRUE((*it == Grades{ 0,"hoge" }));
}

//リストに二つ以上の要素がある場合に、呼び出した際の挙動
TEST(TestListEnd, Test37) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	auto it = list.end();
	--it;
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

//データの挿入を行った後に、呼び出した際の挙動
//先頭に挿入
TEST(TestListEnd, Test38_1) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	list.insert(list.begin(), Grades{ 2,"piyo" });
	auto it = list.end();
	--it;
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

//末尾に挿入
TEST(TestListEnd, Test38_2) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	list.insert(list.end(), Grades{ 2,"piyo" });
	auto it = list.end();
	--it;
	EXPECT_TRUE((*it == Grades{ 2,"piyo" }));
}

//途中に挿入
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


//データの削除を行った後に、呼び出した際の挙動
//先頭を削除
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

//末尾を削除
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

//途中を削除
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


//末尾コンストイテレータの取得

//リストが空である場合に、呼び出した際の挙動
TEST(TestListConstEnd, Test41) {
	List list;
	EXPECT_TRUE(list.constEnd() != List::Iterator{ nullptr });
}

//リストに要素が一つある場合に、呼び出した際の挙動
TEST(TestListConstEnd, Test42) {
	List list;
	list.add(Grades{ 0,"hoge" });
	auto it = list.constEnd();
	--it;
	EXPECT_TRUE((*it == Grades{ 0,"hoge" }));
}

//リストに二つ以上の要素がある場合に、呼び出した際の挙動
TEST(TestListConstEnd, Test43) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	auto it = list.constEnd();
	--it;
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

//データの挿入を行った後に、呼び出した際の挙動
//先頭に挿入
TEST(TestListConstEnd, Test44_1) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	list.insert(list.begin(), Grades{ 2,"piyo" });
	auto it = list.constEnd();
	--it;
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

//後方に挿入
TEST(TestListConstEnd, Test44_2) {
	List list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 1,"fuga" });
	list.insert(list.end(), Grades{ 2,"piyo" });
	auto it = list.constEnd();
	--it;
	EXPECT_TRUE((*it == Grades{ 2,"piyo" }));
}

//途中に挿入
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


//データの削除を行った後に、呼び出した際の挙動
//先頭を削除
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

//末尾を削除
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

//途中を削除
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


//イテレーターのテスト

//イテレータの指す要素を取得する

//リストの参照がない状態で呼び出した際の挙動
TEST(TestIterator, Test0) {
	List::Iterator it{ nullptr };
	EXPECT_ANY_THROW((*it).score);
}

//Iteratorから取得した要素に対して、値の代入が行えるかをチェック
TEST(TestIterator, Test1) {

	List list;
	list.add({ 0,"hoge" });

	auto it = list.begin();
	(*it) = Grades{ 1,"fuga" };

	EXPECT_TRUE(((*it) == Grades{ 1,"fuga" }));
}

//リストが空の際の、先頭イテレータに対して呼び出した際の挙動
TEST(TestIterator, Test3) {
	List list;
	EXPECT_ANY_THROW((*list.begin()).score);
}

//末尾イテレータに対して呼び出した際の挙動
TEST(TestIterator, Test4) {
	List list;
	EXPECT_ANY_THROW((*list.end()).score);
}


//イテレータをリストの末尾に向かって一つ進める

//リストの参照がない状態で呼び出した際の挙動
TEST(TestIterator, Test5) {
	auto it = List::Iterator{ nullptr };
	EXPECT_ANY_THROW(++it);
}

//リストが空の際の、先頭イテレータに対して呼び出した際の挙動
TEST(TestIterator, Test6) {
	List list;
	auto it = list.begin();
	EXPECT_ANY_THROW(++it);
}

//末尾イテレータに対して呼び出した際の挙動
TEST(TestIterator, Test7) {
	List list;
	auto it = list.end();
	EXPECT_ANY_THROW(++it);
}

//リストに二つ以上の要素がある場合に呼び出した際の挙動
TEST(TestIterator, Test8) {
	List list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.begin();
	++it;
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

//前置インクリメントを行った際の挙動(++演算子オーバーロードで実装した場合)
TEST(TestIterator, Test9) {
	List list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.begin();
	EXPECT_TRUE((*(++it) == Grades{ 1,"fuga" }));
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

////後置インクリメントを行った際の挙動( ++演算子オーバーロードで実装した場合 )
TEST(TestIterator, Test10) {
	List list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.begin();
	EXPECT_TRUE((*(it++) == Grades{ 0,"hoge" }));
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}


//イテレータをリストの先頭に向かって一つ進める

//リストの参照がない状態で呼び出した際の挙動
TEST(TestIterator, Test11) {
	auto it = List::Iterator{ nullptr };
	EXPECT_ANY_THROW(--it);
}

//リストが空の際の、先頭イテレータに対して呼び出した際の挙動
TEST(TestIterator, Test12) {
	List list;
	auto it = list.begin();
	EXPECT_ANY_THROW(--it);
}

//末尾イテレータに対して呼び出した際の挙動
TEST(TestIterator, Test13) {
	List list;
	auto it = list.end();
	EXPECT_ANY_THROW(--it);
}

//リストに二つ以上の要素がある場合に呼び出した際の挙動
TEST(TestIterator, Test14) {
	List list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.end();
	--it;
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

//前置デクリメントを行った際の挙動( ++演算子オーバーロードで実装した場合)
TEST(TestIterator, Test15) {
	List list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.end();
	EXPECT_TRUE((*(--it) == Grades{ 1,"fuga" }));
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

//後置デクリメントを行った際の挙動( ++演算子オーバーロードで実装した場合 )
TEST(TestIterator, Test16) {
	List list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.end();
	it--;
	EXPECT_TRUE(((*(it--)) == Grades{ 1,"fuga" }));
	EXPECT_TRUE(((*it) == Grades{ 0,"hoge" }));
}



//イテレータのコピーを行う


//コピーコンストラクト後の値がコピー元と等しいことをチェック
TEST(TestIterator, Test18) {
	List list;
	list.add({ 0,"hoge" });

	auto it = list.begin();

	auto itCopy = it;
	
	EXPECT_TRUE(itCopy == it);
}

//イテレータの代入を行う

//代入後の値がコピー元と等しいことをチェック
TEST(TestIterator, Test20) {
	List list;
	list.add({ 0,"hoge" });

	auto it = list.begin();
	auto itCopy = List::Iterator{ nullptr };
	itCopy = it;

	EXPECT_TRUE(itCopy == it);
}

//二つのイテレータが同一のものであるか、比較を行う


//リストが空の状態での先頭イテレータと末尾イテレータを比較した際の挙動をチェック
TEST(TestIterator, Test21) {
	List list;
	EXPECT_TRUE(list.begin() == list.end());
}

//同一のイテレータを比較した際の挙動
TEST(TestIterator, Test22) {
	List list;
	list.add({ 0,"hoge" });
	EXPECT_TRUE(list.begin() == list.begin());
}

//異なるイテレータを比較した際の挙動
TEST(TestIterator, Test23) {
	List list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.begin();
	auto itA = it;
	auto itB = ++it;
	EXPECT_FALSE(itA==itB);
}



//二つのイテレータが異なるものであるか、比較を行う


//リストが空の状態での先頭イテレータと末尾イテレータを比較した際の挙動をチェック
TEST(TestIterator, Test24) {
	List list;
	EXPECT_FALSE(list.begin() != list.end());
}

//同一のイテレータを比較した際の挙動
TEST(TestIterator, Test25) {
	List list;
	list.add({ 0,"hoge" });
	EXPECT_FALSE(list.begin() != list.begin());
}

//異なるイテレータを比較した際の挙動
TEST(TestIterator, Test26) {
	List list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.begin();
	auto itA = it;
	auto itB = ++it;
	EXPECT_TRUE(itA != itB);
}



//コンストイテレーターのテスト


//イテレータの指す要素を取得する

//リストの参照がない状態で呼び出した際の挙動
TEST(TestConstIterator, Test0) {
	List::ConstIterator it{ nullptr };
	EXPECT_ANY_THROW((*it).score);
}

//リストが空の際の、先頭イテレータに対して呼び出した際の挙動
TEST(TestConstIterator, Test3) {
	List list;
	EXPECT_ANY_THROW((*list.constBegin()).score);
}

//末尾イテレータに対して呼び出した際の挙動
TEST(TestConstIterator, Test4) {
	List list;
	EXPECT_ANY_THROW((*list.constEnd()).score);
}


//イテレータをリストの末尾に向かって一つ進める


//リストの参照がない状態で呼び出した際の挙動
TEST(TestConstIterator, Test5) {
	auto it = List::ConstIterator{ nullptr };
	EXPECT_ANY_THROW(++it);
}

//リストが空の際の、先頭イテレータに対して呼び出した際の挙動
TEST(TestConstIterator, Test6) {
	List list;
	auto it = list.constBegin();
	EXPECT_ANY_THROW(++it);
}

//末尾イテレータに対して呼び出した際の挙動
TEST(TestConstIterator, Test7) {
	List list;
	auto it = list.constEnd();
	EXPECT_ANY_THROW(++it);
}

//リストに二つ以上の要素がある場合に呼び出した際の挙動
TEST(TestConstIterator, Test8) {
	List list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.constBegin();
	++it;
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

//前置インクリメントを行った際の挙動(++演算子オーバーロードで実装した場合)
TEST(TestConstIterator, Test9) {
	List list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.constBegin();
	EXPECT_TRUE((*(++it) == Grades{ 1,"fuga" }));
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

////後置インクリメントを行った際の挙動( ++演算子オーバーロードで実装した場合 )
TEST(TestConstIterator, Test10) {
	List list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.constBegin();
	EXPECT_TRUE((*(it++) == Grades{ 0,"hoge" }));
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}


//イテレータをリストの先頭に向かって一つ進める

//リストの参照がない状態で呼び出した際の挙動
TEST(TestConstIterator, Test11) {
	auto it = List::ConstIterator{ nullptr };
	EXPECT_ANY_THROW(--it);
}

//リストが空の際の、先頭イテレータに対して呼び出した際の挙動
TEST(TestConstIterator, Test12) {
	List list;
	auto it = list.constBegin();
	EXPECT_ANY_THROW(--it);
}

//末尾イテレータに対して呼び出した際の挙動
TEST(TestConstIterator, Test13) {
	List list;
	auto it = list.constEnd();
	EXPECT_ANY_THROW(--it);
}

//リストに二つ以上の要素がある場合に呼び出した際の挙動
TEST(TestConstIterator, Test14) {
	List list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.constEnd();
	--it;
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

//前置デクリメントを行った際の挙動( ++演算子オーバーロードで実装した場合)
TEST(TestConstIterator, Test15) {
	List list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.constEnd();
	EXPECT_TRUE((*(--it) == Grades{ 1,"fuga" }));
	EXPECT_TRUE((*it == Grades{ 1,"fuga" }));
}

////後置デクリメントを行った際の挙動( ++演算子オーバーロードで実装した場合 )
TEST(TestConstIterator, Test16) {
	List list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.constEnd();
	it--;
	EXPECT_TRUE(((*(it--)) == Grades{ 1,"fuga" }));
	EXPECT_TRUE(((*it) == Grades{ 0,"hoge" }));
}




//イテレータのコピーを行う

//コピーコンストラクト後の値がコピー元と等しいことをチェック
TEST(TestConstIterator, Test18) {
	List list;
	list.add({ 0,"hoge" });

	auto it = list.constBegin();

	auto itCopy = it;

	EXPECT_TRUE(itCopy == it);
}


//イテレータの代入を行う

//代入後の値がコピー元と等しいことをチェック
TEST(TestConstIterator, Test20) {
	List list;
	list.add({ 0,"hoge" });

	auto it = list.constBegin();
	auto itCopy = List::ConstIterator{ nullptr };
	itCopy = it;

	EXPECT_TRUE(itCopy == it);
}


//二つのイテレータが同一のものであるか、比較を行う


//リストが空の状態での先頭イテレータと末尾イテレータを比較した際の挙動をチェック
TEST(TestConstIterator, Test21) {
	List list;
	EXPECT_TRUE(list.constBegin() == list.constEnd());
}

//同一のイテレータを比較した際の挙動
TEST(TestConstIterator, Test22) {
	List list;
	list.add({ 0,"hoge" });
	EXPECT_TRUE(list.constBegin() == list.constBegin());
}

//異なるイテレータを比較した際の挙動
TEST(TestConstIterator, Test23) {
	List list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.constBegin();
	auto itA = it;
	auto itB = ++it;
	EXPECT_FALSE(itA == itB);
}



//二つのイテレータが異なるものであるか、比較を行う


//リストが空の状態での先頭イテレータと末尾イテレータを比較した際の挙動をチェック
TEST(TestConstIterator, Test24) {
	List list;
	EXPECT_FALSE(list.constBegin() != list.constEnd());
}

//同一のイテレータを比較した際の挙動
TEST(TestConstIterator, Test25) {
	List list;
	list.add({ 0,"hoge" });
	EXPECT_FALSE(list.constBegin() != list.constBegin());
}

//異なるイテレータを比較した際の挙動
TEST(TestConstIterator, Test26) {
	List list;
	list.add({ 0,"hoge" });
	list.add({ 1,"fuga" });

	auto it = list.constBegin();
	auto itA = it;
	auto itB = ++it;
	EXPECT_TRUE(itA != itB);
}


