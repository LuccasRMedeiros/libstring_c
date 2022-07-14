extern "C"
{
    #include <string_c.h>
}

#include <iostream>

using namespace std;

class Test
{
    private:
        int (*m_test)(void);
        string m_testName;

    public:

        Test(int (*test)(void), string testName)
        {
            m_testName = testName;
            m_test = test;
        }

        int execTest(void)
        {
            int res = m_test();
            cout << "\e[0;34m" << m_testName;

            if (res)
                cout << " \e[1;32mOK\e[0m" << endl;
            else
                cout << " \e[1;32mFAIL\e[0m" << endl;

            return res;
        }
};

class Testsuit
{
    private:
        size_t m_total;
        int m_success;
        int m_failure;
        Test* m_tests;
    
    public:
        Testsuit(Test* tests, size_t total)
        {
            m_total = total;
            m_success = 0;
            m_failure = 0;
            m_tests = tests;
        }

        void execTests(void)
        {
            for (size_t t = 0; t < m_total; ++t)
            {
                if (m_tests[t].execTest())
                    m_success++;
                else
                    m_failure++;
            }

            cout << "=============================================\n";
            cout << "\e[0;34mFinished all \e[1;34m" << m_total << " \e[0;34mtests\e[0m\n";
            if (m_success) // If one or more successes had happened prints how many
                cout << "\e[1;32m" << m_success << " \e[0;34msuccessfully completed\e[0m\n";
            if (m_failure) // If one or more failures had happened prints how many
                cout << "\e[1;31m" << m_failure << " \e[0;34mfailed\e[0m\n";
        }
};

int test3(void)
{
    string_t str = " \t\rtrim this\n\v\f";

    trim_string_t(str);

    // Return if str was correctly trimmed
    return (!strcmp(str, "trim this"));
}

int test2(void)
{
    string_t str = "does not trim this";

    trim_string_t(str);

    // Return if str didn't lose any data, making strcmp return 0
    return (!strcmp(str, "does not trim this"));
}

int test1(void)
{
    string_t str = "         trim this          ";
    trim_string_t(str);
    
    // Return if str was correctly trimmed, making strcmp return 0
    return (!strcmp(str, "trim this"));
}

int main(void)
{
    Test libstringTest1(&test1, "Test if trim_string_t trims string_t str");
    Test libstringTest2(&test2, "Test if trim_string_t does not trim trimmed string");
    Test libstringTest3(&test3, "Test if trim_string_t works with various whitespace chars");

    Test tests[] = {
        libstringTest1,
        libstringTest2,
        libstringTest3
    };

    Testsuit testbattery(tests, sizeof (tests) / sizeof (Test));

    testbattery.execTests();

    return 0;
}
