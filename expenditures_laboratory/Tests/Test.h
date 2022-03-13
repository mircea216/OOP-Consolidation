//
//

#ifndef LAB_07_TEST_H
#define LAB_07_TEST_H


class Test {
public:
    Test() = default;

    static void testDomain();

    static void testRepository();

    static void testService();

    static void runAllTests();

    ~Test() = default;
};


#endif //LAB_07_TEST_H
