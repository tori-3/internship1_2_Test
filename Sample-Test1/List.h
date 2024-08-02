#pragma once
#include<string>

///@brief ���тƖ��O�������N���X�ł��B
struct Grades
{
    //! �X�R�A
    int score;

    //! ���O
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

///@brief �o�������X�g�̃N���X�ł��B
class List
{
private:

    ///@brief ���X�g�̃m�[�h�ł��B
    struct Node
    {
        //! �f�[�^
        Grades data;

        //! �O�̃m�[�h�̃|�C���^
        Node* front = nullptr;

        //! ���̃m�[�h�̃|�C���^
        Node* back = nullptr;
    };

public:

    ///@brief ���X�g�̃R���X�g�C�e���[�^�[�ł��B
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

        Grades operator *()const
        {
            //����nullptr��������
            if (m_element == nullptr) 
            {
                throw std::runtime_error("nullptr�ł��B");
            }

            //�����_�~�[�m�[�h��������
            if (m_element==m_element->back) 
            {
                throw std::runtime_error("�����ȃC�e���[�^�[�ł��B");
            }

            return m_element->data;
        }

        ConstIterator& operator --()
        {
            //����nullptr��������
            if (m_element == nullptr)
            {
                throw std::runtime_error("nullptr�ł��B");
            }

            //�����_�~�[�m�[�h��������
            if (m_element == m_element->back)
            {
                throw std::runtime_error("�����ȃC�e���[�^�[�ł��B");
            }

            m_element = m_element->front;
            return *this;
        }

        ConstIterator& operator ++()
        {
            //����nullptr��������
            if (m_element == nullptr)
            {
                throw std::runtime_error("nullptr�ł��B");
            }

            //�����_�~�[�m�[�h��������
            if (m_element == m_element->back)
            {
                throw std::runtime_error("�����ȃC�e���[�^�[�ł��B");
            }

            m_element = m_element->back;
            return *this;
        }

        ConstIterator operator --(int)
        {
            //����nullptr��������
            if (m_element == nullptr)
            {
                throw std::runtime_error("nullptr�ł��B");
            }

            //�����_�~�[�m�[�h��������
            if (m_element == m_element->back)
            {
                throw std::runtime_error("�����ȃC�e���[�^�[�ł��B");
            }

            auto old = *this;
            m_element = m_element->front;
            return old;
        }

        ConstIterator operator ++(int)
        {
            //����nullptr��������
            if (m_element == nullptr)
            {
                throw std::runtime_error("nullptr�ł��B");
            }

            //�����_�~�[�m�[�h��������
            if (m_element == m_element->back)
            {
                throw std::runtime_error("�����ȃC�e���[�^�[�ł��B");
            }

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

        ///@brief �C�e���[�^�[�������Ă���Node�̃|�C���^��Ԃ��܂��B
        ///@return Node�̃|�C���^
        Node* getElement()const 
        {
            return m_element;
        }

    protected:

        Node* m_element;
    };

    ///@brief ���X�g�̃C�e���[�^�[�ł��B
    class Iterator :public ConstIterator
    {
    public:
        using ConstIterator::ConstIterator;

        Grades& operator *()
        {
            //����nullptr��������
            if (m_element == nullptr)
            {
                throw std::runtime_error("nullptr�ł��B");
            }

            //�����_�~�[�m�[�h��������
            if (m_element == m_element->back)
            {
                throw std::runtime_error("�����ȃC�e���[�^�[�ł��B");
            }

            return m_element->data;
        }
    };

    ///@brief List�̃R���X�g���N�^�ł��B
    List() :m_sentinel{ new Node{} }
    {
        m_sentinel->back = m_sentinel;
        m_sentinel->front = m_sentinel;
    }

    ///@brief ���X�g�̐擪�C�e���[�^�[��Ԃ��܂�
    ///@return �擪�C�e���[�^�[
    Iterator begin() const
    {
        return Iterator{ m_sentinel->back };
    }

    ///@brief ���X�g�̖����C�e���[�^�[��Ԃ��܂�
    ///@return �����C�e���[�^�[
    Iterator end() const
    {
        return Iterator{ m_sentinel };
    }

    ///@brief ���X�g�̐擪�R���X�g�C�e���[�^�[��Ԃ��܂�
    ///@return �擪�C�e���[�^�[
    ConstIterator constBegin() const
    {
        return ConstIterator{ m_sentinel->back };
    }

    ///@brief ���X�g�̖����R���X�g�C�e���[�^�[��Ԃ��܂�
    ///@return �����C�e���[�^�[
    ConstIterator constEnd() const
    {
        return ConstIterator{ m_sentinel };
    }

    ///@brief ���X�g�̒�����Ԃ��܂�
    ///@return ���X�g�̒���
    size_t size()const
    {
        return m_size;
    }

    ///@brief ���X�g�ɐV���ȗv�f��}�����܂��B
    ///@param iterator �ǉ�����ʒu�̃C�e���[�^�[
    ///@param addData �ǉ�����f�[�^
    ///@return �ǉ��ɐ���������true ���s������false
    bool insert(ConstIterator iterator, const Grades& addData) 
    {
        Node* node=iterator.getElement();

        if (node == nullptr) 
        {
            return false;
        }

        Node* addNode=new Node{ addData };
        Node* frontNode = node->front;

        node->front = addNode;
        addNode->back = node;

        addNode->front = frontNode;
        frontNode->back = addNode;

        ++m_size;

        return true;
    }

    ///@brief ���X�g�̗v�f���폜���܂��B
    ///@param iterator �폜����ʒu�̃C�e���[�^�[
    ///@return �폜�ɐ���������true ���s������false
    bool remove(ConstIterator iterator) 
    {

        Node* node = iterator.getElement();

        if (node == m_sentinel || node == nullptr) 
        {
            return false;
        };

        node->front->back = node->back;
        node->back->front = node->front;
        delete node;

        --m_size;

        return true;
    }

    ///@brief ���X�g�̖����ɗv�f��ǉ����܂��B
    ///@param addData �ǉ�����f�[�^
    void add(const Grades& addData)
    {
        insert(end(), addData);
    }

private:
    //! �ԕ��̃|�C���^
    Node* m_sentinel;

    //! ���X�g�̒���
    size_t m_size = 0;
};
