#include "../include/sum.hpp"

namespace m_math
{
    sum::sum(const function& lop, const function& rop): sum{lop.clone(), rop.clone()}
    {

    }

    sum::sum(function * lop, function * rop):function{}, two_operands{lop,rop}
    {

    }

    function * sum::clone() const
    {
        return new sum{this->left_operand()->clone(), this->right_operand()->clone()};
    }

    std::string sum::derivate(std::string var) const
    {
        return std::string{"("}+this->left_operand()->derivate(var)+std::string{"+"}+this->right_operand()->derivate(var)+std::string{")"};
    }

    std::string sum::to_string() const
    {
        return std::string{"("}+this->left_operand()->to_string()+std::string{"+"}+this->right_operand()->to_string()+std::string{")"};
    }
}