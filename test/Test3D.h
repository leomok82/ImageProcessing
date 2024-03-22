#ifndef TEST3D_H
#define TEST3D_H

#include <iostream>
#include <vector>
#include <functional>
#include <string>
#include <sstream>
#include "../src/new/Volume.h"
#include "../src/new/Slice.h"
#include "../src/new/Projections.h"
#include "../src/new/Filter3D.h"

// Assertion macro, used to verify if an expression is true, if not, record an error message
#define ASSERT_TRUE(expression, message)                                 \
    if (!(expression))                                                   \
    {                                                                    \
        std::stringstream ss;                                            \
        ss << "Assertion failed: " << (message) << " (" #expression ")"; \
        throw std::runtime_error(ss.str());                              \
    }

class Test
{
public:
    virtual void run() = 0;
    virtual std::string getName() const = 0;
};

class TestSuite
{
private:
    std::vector<Test *> tests;

public:
    void addTest(Test *test);
    void runAll();
};

// Global test suite instance
extern TestSuite globalTestSuite;

// Test registration macro
#define TEST_CASE(className)                                        \
    class className : public Test                                   \
    {                                                               \
    public:                                                         \
        className() { globalTestSuite.addTest(this); }              \
        void run() override;                                        \
        std::string getName() const override { return #className; } \
    };                                                              \
    className global##className;                                    \
    void className::run()

#endif // TEST3D_H
