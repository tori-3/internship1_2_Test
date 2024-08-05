#pragma once
#include<string>

///@brief 成績と名前を扱うクラスです。
struct Grades
{
    //! スコア
    int score;

    //! 名前
    std::string name;

    bool operator ==(const Grades& right)const
    {
        return (score == right.score)&&(name == right.name);
    }

    bool operator !=(const Grades& right)const
    {
        return (score != right.score) || (name != right.name);
    }
};

///@brief 双方向リストのクラスです。
class List
{
private:

    ///@brief リストのノードです。
    struct Node
    {
        //! データ
        Grades data;

        //! 前のノードのポインタ
        Node* front = nullptr;

        //! 後ろのノードのポインタ
        Node* back = nullptr;

        List* parent = nullptr;
    };

public:

    ///@brief リストのコンストイテレーターです。
    class ConstIterator
    {
    public:

        ConstIterator(Node* ptr)
            :m_element{ ptr }{}

        ConstIterator(const ConstIterator& iterator) 
            :m_element{ iterator.m_element }{}

        ConstIterator operator =(const ConstIterator& iterator)
        {
            m_element = iterator.m_element;
            return  *this;
        }

        const Grades& operator *()const
        {

            assert(m_element != nullptr);

            assert(m_element->back!=nullptr);

            assert(m_element->front != nullptr);

            return m_element->data;
        }

        ConstIterator& operator --()
        {
            assert(m_element != nullptr);

            assert(m_element->back != nullptr);

            assert(m_element->front != nullptr);

            m_element = m_element->front;
            return *this;
        }

        ConstIterator& operator ++()
        {
            assert(m_element != nullptr);

            assert(m_element->back != nullptr);

            assert(m_element->front != nullptr);

            m_element = m_element->back;
            return *this;
        }

        ConstIterator operator --(int)
        {
            assert(m_element != nullptr);

            assert(m_element->back != nullptr);

            assert(m_element->front != nullptr);

            auto old = *this;
            m_element = m_element->front;
            return old;
        }

        ConstIterator operator ++(int)
        {
            assert(m_element != nullptr);

            assert(m_element->back != nullptr);

            assert(m_element->front != nullptr);

            auto old = *this;
            m_element = m_element->back;
            return old;
        }

        bool operator !=(ConstIterator right)const
        {
            return m_element != right.m_element;
        }

        bool operator ==(ConstIterator right)const
        {
            return m_element == right.m_element;
        }

        ///@brief イテレーターが持っているNodeのポインタを返します。
        ///@return Nodeのポインタ
        Node* getElement()const 
        {
            return m_element;
        }

        ///@brief ダミーノードか調べます。
        ///@return ダミーノードならtrue そうでないならfalseを返します。
        bool isDummyNode()const
        {
            return m_element->back == nullptr || m_element->front == nullptr;
        }

    protected:

        Node* m_element;
    };

    ///@brief リストのイテレーターです。
    class Iterator :public ConstIterator
    {
    public:
        using ConstIterator::ConstIterator;

        Grades& operator *()
        {
            assert(m_element != nullptr);

            assert(m_element->back != nullptr);

            assert(m_element->front != nullptr);

            return m_element->data;
        }
    };

    ///@brief Listのコンストラクタです。
    List() :m_sentinelBegin{ new Node{} },m_sentinelEnd{ new Node{} }
    {
        m_sentinelBegin->back = m_sentinelEnd;
        m_sentinelEnd->front = m_sentinelBegin;
        m_sentinelBegin->parent = this;
        m_sentinelEnd->parent = this;
    }

    ///@brief リストの先頭イテレーターを返します
    ///@return 先頭イテレーター
    Iterator begin()
    {
        return Iterator{ m_sentinelBegin->back };
    }

    ///@brief リストの末尾イテレーターを返します
    ///@return 末尾イテレーター
    Iterator end()
    {
        return Iterator{ m_sentinelEnd };
    }

    ///@brief リストの先頭コンストイテレーターを返します
    ///@return 先頭イテレーター
    ConstIterator constBegin() const
    {
        return ConstIterator{ m_sentinelBegin->back };
    }

    ///@brief リストの末尾コンストイテレーターを返します
    ///@return 末尾イテレーター
    ConstIterator constEnd() const
    {
        return ConstIterator{ m_sentinelEnd };
    }

    ///@brief リストの長さを返します
    ///@return リストの長さ
    size_t size()const
    {
        return m_size;
    }

    ///@brief リストに新たな要素を挿入します。
    ///@param iterator 追加する位置のイテレーター
    ///@param addData 追加するデータ
    ///@return 追加に成功したらtrue 失敗したらfalse
    bool insert(ConstIterator iterator, const Grades& addData)
    {
        Node* node=iterator.getElement();

        if (node == nullptr||node->parent!=this) 
        {
            return false;
        }

        Node* addNode=new Node{ addData };
        Node* frontNode = node->front;

        node->front = addNode;
        addNode->back = node;

        addNode->front = frontNode;
        frontNode->back = addNode;

        addNode->parent = this;

        ++m_size;

        return true;
    }

    ///@brief リストの要素を削除します。
    ///@param iterator 削除する位置のイテレーター
    ///@return 削除に成功したらtrue 失敗したらfalse
    bool remove(ConstIterator iterator) 
    {

        Node* node = iterator.getElement();

        if (node == nullptr|| iterator.isDummyNode() || node->parent != this)
        {
            return false;
        };

        node->front->back = node->back;
        node->back->front = node->front;
        delete node;

        --m_size;

        return true;
    }

    ///@brief リストの末尾に要素を追加します。
    ///@param addData 追加するデータ
    void add(const Grades& addData)
    {
        insert(end(), addData);
    }

private:
    //! 番兵のポインタ
    Node* m_sentinelBegin;
    Node* m_sentinelEnd;

    //! リストの長さ
    size_t m_size = 0;
};
