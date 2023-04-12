#pragma once
#include "point.hpp"
#include "tools/CppTest/test.hpp"

#include <string>
#include <string_view>
#include <vector>

class DistCase: public TestCase{
private:
    struct Point_dist{
        Point point1;
        Point point2;

        Point_dist() = default;
        Point_dist(Point&& p1, Point&& p2): point1(p1), point2(p2){}

        double test_func() // there is function that we test
        {
            return point1.dist(point2);
        }
    };
    Point_dist input_data;
    double expected;

public:
    DistCase() = default;
    DistCase(const std::string& description_, Point_dist&& datas, double expected_):
    TestCase(description_, "DistCase"), input_data(datas), expected(expected_)
    {}

    bool run() override final{
        std::cout << "Expected_data: " << expected << std::endl;
        auto data = input_data.test_func();
        std::cout << "Real data: " << data << std::endl;
        return input_data.test_func() == expected;
    }

    Point_dist get_input_data() const{
        return input_data;
    }
    double get_expected() const{
        return expected;
    };

    std::vector<TestCase*> get_test_data() const override{
        return {
            new DistCase("Base case", Point_dist(Point(1.0, 0.0), Point(0.0, 0.0)), 1.0),
            new DistCase("Identical points", Point_dist(Point(0.0, 0.0), Point(0.0, 0.0)), 0.0)
        };
    };
    ~DistCase() = default;
};


class SumPointsCase: public TestCase{
private:
    struct Points_sum{
        Point point1;
        Point point2;

        Points_sum() = default;
        Points_sum(Point&& p1, Point&& p2): point1(p1), point2(p2){}
        Point test_func()
        {
            point1.sum(point2);
            return point1;
        }
    };

    Points_sum input_data;
    Point expected;

public:
    SumPointsCase() = default;
    SumPointsCase(const std::string& description_, Points_sum&& datas, Point&& expected_):
    TestCase(description_, "SumPointsCase"), input_data(datas), expected(expected_){}

    std::vector<TestCase*> get_test_data() const override final{
        return {
            new SumPointsCase("main case", Points_sum(Point(1.0, 2.0), Point(3.0, 5.0)), Point(4.0, 7.0)),
            new SumPointsCase("Identical points", Points_sum(Point(1.0, 1.0), Point(1.0, 1.0)), Point(2.0, 2.0)),
            new SumPointsCase("Add zero point", Points_sum(Point(1.0, 1.0), Point(0.0, 0.0)), Point(1.0, 1.0)),
        };
    };
    bool run() override final{
        std::cout << "Expected_data: " << expected << std::endl;
        auto data = input_data.test_func();
        std::cout << "Real data: " << data << std::endl;
        return data == expected;
    }

    Points_sum get_input_data() const{
        return input_data;
    }
    Point get_expected() const{
        return expected;
    };

    ~SumPointsCase() = default;
};

class PointTest: public Test{
public:
    PointTest(): Test("Point.cpp", {new DistCase, new SumPointsCase}) {};
};

