#include <gtest/gtest.h>

#include <lib/acc.h>

TEST(Acc, Adding) 
{
    acc accu;
    accu.add(2);
    accu.add(4);
    EXPECT_EQ(accu.get(), 6);
}

TEST(Acc, AddingUnderflow)
{
    acc accu;
    accu.add(2);
    accu.add(-4);
    EXPECT_EQ(accu.get(), -2);
}

TEST(Acc, Substract)
{
    acc accu;
    accu.add(4);
    accu.sub(1);
    EXPECT_EQ(accu.get(), 3);
}

TEST(Acc, SubstractUnderflow)
{
    acc accu;
    accu.add(2);
    accu.sub(6);
    EXPECT_EQ(accu.get(), -4);
}
