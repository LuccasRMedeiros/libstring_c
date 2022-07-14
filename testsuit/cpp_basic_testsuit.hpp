#include <iostream>

#ifndef CPP_BASIC_TESTSUIT_HPP
#define CPP_BASIC_TESTSUIT_HPP

using namespace std;

class Test
{
    private:
        int (*m_test)(void);
        string m_testName;

    public:
        Test(int (*test)(void), string testName);
        int execTest(void);
};

class Testsuit
{
    private:
        size_t m_total;
        int m_success;
        int m_failure;
        Test* m_tests;

    public:
        Testsuit(Test* tests, size_t total);
        void execTests(void);
};

#endif
