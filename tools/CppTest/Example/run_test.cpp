#include "test_point.hpp"

std::vector<Test*> get_tests(){
    return {
        new PointTest()
    };
};

int main(){
    auto tests = get_tests();
    for (auto test: tests){
        test->run();
    }
    for (auto test: tests){
        delete test;
    }


}