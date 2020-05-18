#pragma once
//#include "Field.h"
//idk, field is not a container, it is just an array of pointers

/*
class FieldIterator
{
    typedef typename std::vector<PlayingField::Cell>::iterator iter_type;
	FieldIterator(PlayingField *p_data) : m_p_data_(p_data){
        m_it_ = m_p_data_->begin();
    }

    void First() {
        m_it_ = m_p_data_->m_data_.begin();
    }

    void Next() {
        m_it_++;
    }

    bool IsDone() {
        return (m_it_ == m_p_data_->m_data_.end());
    }

    iter_type Current() {
        return m_it_;
    }

    private:
        PlayingField* m_p_data_;
        iter_type m_it_;
};

*/