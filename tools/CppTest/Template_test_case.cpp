#pragma once
#include "tools/CppTest/test.hpp"

class CASE_NAME: public TestCase{
private:
    struct function_args_name{
        /*
        there should be fields for function call arguments here
        ex:
        Point p1;
        Point p2;
        */ 
        function_args_name() = default;
        function_args_name(/*ex: Point&& p1, Point&& p2*/): /*point1(p1), point2(p2)*/{};

        return_type test_func()
        {
            /*
            there should be fuction call, that we tests
            */
        }
    };
    function_args_name input_data;
    return_type expected;

public:
    CASE_NAME() = default;
    CASE_NAME(const std::string& description_, function_args_name&& datas, return_type expected_):
    TestCase(description_, "DistCase"), input_data(datas), expected(expected_)
    {}

    bool run() override final{
        /*
        there should be compare test_func and expected data
        */
        std::cout << "Expected_data: " << expected << std::endl;
        auto data = input_data.test_func();
        std::cout << "Real data: " << data << std::endl;
        return input_data.test_func() == expected;
    }

    decltype(auto) get_input_data() const{
        return input_data;
    }
    decltype(auto) get_expected() const{
        return expected;
    };

    std::vector<TestCase*> get_test_data() const override{
        return {
            new CASE_NAME(<args>),
            new CASE_NAME(<args>)
        };
    };
    CASE_NAME() = default;
};
