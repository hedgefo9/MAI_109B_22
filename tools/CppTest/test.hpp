#pragma once

#include <string>
#include <string_view>
#include <vector>
#include <iostream>

class TestFailedException: public std::exception{
     std::string error_msg;
public:
    explicit TestFailedException(const std::string& error): error_msg(std::move(error))
    {}
    [[nodiscard]] const char *what() const noexcept override
    {
        return error_msg.c_str();
    }
};

class TestCase{
private:
    std::string case_description;
    std::string class_name;

public:
    TestCase() = default;
    TestCase(const std::string& description_, const std::string& class_name_):
    case_description(description_), class_name(class_name_)
    {};

    std::string get_case_description() const{
        return case_description;
    }

    std::string get_name_of_test() const{
        return class_name;
    }

    bool virtual run() = 0;
    std::vector<TestCase*> virtual get_test_data() const = 0;
    virtual ~TestCase() = default;
};



class Test{
    std::string name_of_test;
    std::vector<TestCase*> tests_cases;

public:
    Test() = default;
    Test(std::string name_of_test, const std::vector<TestCase*>& tests_cases_):
    name_of_test(name_of_test)
    {
        for (auto& test_case_: tests_cases_){
            for(auto& case_: test_case_->get_test_data()){
                tests_cases.push_back(case_);
            }
            delete test_case_;
        }
    }

    std::string get_name_of_test() const{
        return name_of_test;
    }
    std::vector<TestCase*> get_tests_cases() const{
        return tests_cases;
    }

    void run(){
        bool is_success = true;
        std::cout << "Running: " << name_of_test << std::endl;
        for (auto& test_case: tests_cases){
            std::cout << "\n[" << test_case->get_name_of_test() << ":" << test_case->get_case_description() << "]:\n";
            if (!test_case->run()){
                std::cout << "FAILED\n";
                is_success = false;
            } else{
                std::cout << "PASSED\n";
            }
        }
        if (!is_success){
            throw TestFailedException("Test " + this->name_of_test + "is failed!");
        };
    }
    ~Test(){
        for (auto& test: tests_cases){
            delete test;
        }
    };

};