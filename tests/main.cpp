#include <gtest/gtest.h>

TEST(FooTest, MethodBarDoesAbc)
{
    int i = 0;
    ASSERT_EQ(i, 0);
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    int retVal = RUN_ALL_TESTS();
    system("pause");
    return retVal;
}