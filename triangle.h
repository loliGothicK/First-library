#ifndef FIRSTLIB_PCC_AREA_H_
#define FIRSTLIB_PCC_AREA_H_

#include<iostream>
#include<cmath>
#include<string>

namespace brahman{

enum class TriangleShape
{
    NotTriangle,
    Equilateral,
    IsoscelesRight,
    Isosceles,
    Right,
    InEquilateral,
    UnInitialized = -1,
};


template <typename T>
class Triangle
{
    T ab;//Didn't use const, because I'm going to implement side-length extension function.
    T bc;
    T ca;
    TriangleShape shape;
    T area;

public:

    Triangle(T ab, T bc, T ca): ab(ab), bc(bc), ca(ca), shape(TriangleShape::UnInitialized)
    {
        shape = InitializeShape();
        area = CalculateArea();
    }

    ~Triangle()
    {

    }

    TriangleShape InitializeShape() const
    {
        if((ab + bc > ca && ab + ca > bc && bc + ca > ab) && (ab > 0 && bc > 0 && ca > 0))
        {
            if(ab == bc && bc == ca)
            {
                return TriangleShape::Equilateral;
            }
            else if(ab*ab + bc*bc == ca*ca || ab*ab + ca*ca == bc*bc || bc*bc + ca*ca == ab*ab)
            {
                if(ab == bc || bc == ca || ca == ab)
                {
                    return TriangleShape::IsoscelesRight;
                }
                else
                {
                    return TriangleShape::Right;
                }
            }
            else if(ab == bc || bc == ca || ca == ab)
            {
                return TriangleShape::Isosceles;
            }
            else
            {
                return TriangleShape::InEquilateral;
            }
            
        }
        else
        {
            return TriangleShape::NotTriangle;
        }
    }

    T CalculateArea() const
    {
        T s = static_cast<T>(ab+bc+ca)/2;//Is cast necessary? Yes, necessary
        return static_cast<T>(sqrt(s*(s-ab)*(s-bc)*(s-ca)));
    }    

    T GetAB() const
    {
        return ab;
    }
    T GetBC() const
    {
        return bc;
    }
    T GetCA() const
    {
        return ca;
    }
    T GetArea() const
    {
        return area;
    }
    
    std::string GetShape() const
    {
        
        switch (shape)
        {

        case TriangleShape::NotTriangle:
            return std::string("NotTriangle");

        case TriangleShape::Equilateral:
            return std::string("Equilateral Triangle");
        
        case TriangleShape::IsoscelesRight:
            return std::string("IsoscelesRight Triangle");

        case TriangleShape::Isosceles:
            return std::string("Isosceles Triangle");

        case TriangleShape::Right:
            return std::string("Right Triangle");

        case TriangleShape::InEquilateral:
            return std::string("InEquilateral Triangle");

        default:
            return std::string("Error");//It will become exception handling
        }
    }    

    void PrintCondition()
    {
        std::cout << "AB: " << GetAB() << std::endl;
        std::cout << "BC: " << GetBC() << std::endl;
        std::cout << "CA: " << GetCA() << std::endl;
        std::cout << "Area is " << GetArea() << std::endl;        
        std::cout << "Shape is " << GetShape() << std::endl;
    }
};
}

#endif //FIRSTLIB_PCC_AREA_H_